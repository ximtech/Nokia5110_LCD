#include "Nokia5110_LCD.h"

#define LCD_ASCII_OFFSET 0x20         //0x20, ASCII character for Space
#define LCD_ASCII_OFFSET_ZERO 0x2E   // ASCII code for . is 0X2E (. / 0 1 etc)

#define LCD_X_ADDRESS_LENGTH 84
#define LCD_Y_ADDRESS_LENGTH 6
#define LCD_TOTAL_ADDRESS_LINES (LCD_X_ADDRESS_LENGTH * LCD_Y_ADDRESS_LENGTH)
#define TOTAL_FONT_COUNT 9
#define MAX_LCD_CHARACTER_CAPACITY 70

// Size width of fonts in pixels, add 2 for padding 1-6
#define LCD_DEFAULT_FONT_WIDTH       5
#define LCD_THICK_FONT_WIDTH         7
#define LCD_AUREBESH_FONT_WIDTH      5
#define LCD_SEVEN_SEGMENT_FONT_WIDTH 4
#define LCD_WIDE_FONT_WIDTH          8
#define LCD_TINY_FONT_WIDTH          3
#define LCD_LARGE_FONT_WIDTH         12 // No padding, no lowercase letters
#define LCD_HUGE_FONT_WIDTH          16 // No padding, numbers only
#define LCD_MEGA_FONT_WIDTH          16 // No padding, numbers only

static SPI_Polling SPIInstance;
static uint8_t lcdFont = N5110_FONT_DEFAULT;
static uint8_t rowPosition = 0;
static uint8_t columnPosition = 0;
static TextColor textColor = BLACK;

static const uint8_t ZERO_VALUE_ARRAY[LCD_TOTAL_ADDRESS_LINES] = { [0 ... LCD_TOTAL_ADDRESS_LINES - 1] = 0x00 };

static void printChar(char character);
static void printLargeFontCharacter(char character);
static void printHugeFontCharacter(char character);
static void printMegaFontCharacter(char character);
static void transmitFontDataLCD(void *fontArray, char character, uint8_t columnLength);

void initN5110(SPI_TypeDef *SPIx) {
    SPIInstance = initSPI(SPIx, N5110_CHIP_SELECT_PORT, N5110_CHIP_SELECT_PIN);
    resetN5110();        // reset the display
    commandN5110(H_EXTENDED_INSTRUCTION_SET);
    commandN5110(VOP_BIAS_VOLTAGE_HIGH_CONTRAST);
    commandN5110(TEMPERATURE_COEFFICIENT_3);
    commandN5110(BIAS_VALUE_MUX_RATE_1X48);
    commandN5110(H_BASIC_INSTRUCTION_SET);  // for setting display mode switch to basic instructions
    commandN5110(DISPLAY_NORMAL_MODE);
    clearN5110();
}

void printCharN5110(char character) {
    chipSelectSet(&SPIInstance);
    printChar(character);
    chipSelectReset(&SPIInstance);
}

void printStringN5110(const char *string) {
    chipSelectSet(&SPIInstance);
    if (textColor == WHITE) {
        transmit8BitsSPI(&SPIInstance, 0xFF);
    }
    for (uint16_t i = 0; string[i] != '\0'; i++) {
        printChar(string[i]);
    }
    if (textColor == WHITE) {
        transmit8BitsSPI(&SPIInstance, 0xFF);
    }
    chipSelectReset(&SPIInstance);
}

void printfStringN5110(char *format, ...) {
    static char formatBuffer[MAX_LCD_CHARACTER_CAPACITY];
    memset(formatBuffer, 0, MAX_LCD_CHARACTER_CAPACITY);
    va_list args;

    va_start(args, format);
    vsnprintf(formatBuffer, MAX_LCD_CHARACTER_CAPACITY, format, args);
    va_end(args);
    printStringN5110(formatBuffer);
}

void printImageN5110(const uint8_t *imageData) {
    chipSelectSet(&SPIInstance);
    transmit8BitDataSPI(&SPIInstance, imageData, LCD_TOTAL_ADDRESS_LINES);
    chipSelectReset(&SPIInstance);
}

void fillBlockN5110(uint8_t fillData, uint8_t rowBlockNum) {
    goToXYN5110(0, rowBlockNum);
    chipSelectSet(&SPIInstance);
    for (uint8_t i = 0; i < LCD_X_ADDRESS_LENGTH; i++) {
        transmit8BitsSPI(&SPIInstance, fillData);
    }
    chipSelectReset(&SPIInstance);
}

void printCustomCharacter(const unsigned char characterData[], uint16_t length, CustomCharacterPadding padding) {
    chipSelectSet(&SPIInstance);
    if (padding == PADDING_LEFT ||  padding == PADDING_ALL) {
        transmit8BitsSPI(&SPIInstance, 0x00); //Blank vertical line padding, LHS
    }
    transmit8BitDataSPI(&SPIInstance, characterData, length);

    if (padding == PADDING_RIGHT || padding == PADDING_ALL) {
        transmit8BitsSPI(&SPIInstance, 0x00); //Blank vertical line padding, RHS
    }
    chipSelectReset(&SPIInstance);
}

void goToXYN5110(uint8_t x, uint8_t y) {
    if (x < LCD_X_ADDRESS_LENGTH && y < LCD_Y_ADDRESS_LENGTH) {
        commandN5110(SET_X_ADDRESS_OF_RAM_COMMAND_REGISTER | x);
        commandN5110(SET_Y_ADDRESS_OF_RAM_COMMAND_REGISTER | y);
        columnPosition = x;
        rowPosition = y;
    }
}

void setPixelN5110(uint8_t column, uint8_t row) {
    uint8_t rowBlock = row / 8; // from 0 to 5
    goToXYN5110(column, rowBlock);
    chipSelectSet(&SPIInstance);
    transmit8BitsSPI(&SPIInstance, (1 << (row - (rowBlock * 8))));
    chipSelectReset(&SPIInstance);
}

void setFontN5110(uint8_t font) {
    if (font <= TOTAL_FONT_COUNT) {
        lcdFont = font;
    }
}

void setTextColorN5110(TextColor color) {
    textColor = color;
}

void clearN5110() {
    LL_GPIO_SetOutputPin(N5110_DC_GPIO_PORT, N5110_DC_PIN);
    chipSelectSet(&SPIInstance);
    transmit8BitDataSPI(&SPIInstance, ZERO_VALUE_ARRAY, LCD_TOTAL_ADDRESS_LINES);
    chipSelectReset(&SPIInstance);
    goToXYN5110(0, 0);
}

void commandN5110(char command) {
    LL_GPIO_ResetOutputPin(N5110_DC_GPIO_PORT, N5110_DC_PIN);// make DC pin to logic zero for command operation
    chipSelectSet(&SPIInstance);
    transmit8BitsSPI(&SPIInstance, command);
    LL_GPIO_SetOutputPin(N5110_DC_GPIO_PORT, N5110_DC_PIN); // make DC pint to logic high for data operation
    chipSelectReset(&SPIInstance);
}

void resetN5110() {  // reset the Display at the beginning of initialization
    LL_GPIO_ResetOutputPin(N5110_RESET_GPIO_PORT, N5110_RESET_PIN);
    LL_mDelay(100);
    LL_GPIO_SetOutputPin(N5110_RESET_GPIO_PORT, N5110_RESET_PIN);
}

void printChar(char character) {
    switch (lcdFont) {
        #ifdef N5110_FONT_DEFAULT
        case N5110_FONT_DEFAULT:
            if (character >= 0xC0) break;
            transmitFontDataLCD((const unsigned char **) ASCII_CYRILLIC, character, LCD_DEFAULT_FONT_WIDTH);
            break;
        #endif
        #ifdef N5110_FONT_THICK
        case N5110_FONT_THICK:
            transmitFontDataLCD((const unsigned char **) ASCII_THICK, character, LCD_THICK_FONT_WIDTH);
            break;
        #endif
        #ifdef N5110_FONT_AUREBESH
        case N5110_FONT_AUREBESH:
            transmitFontDataLCD((const unsigned char **) ASCII_AUREBESH, character, LCD_AUREBESH_FONT_WIDTH);
            break;
        #endif
        #ifdef N5110_FONT_SEVEN_SEGMENT
        case N5110_FONT_SEVEN_SEGMENT:
            transmitFontDataLCD((const unsigned char **) ASCII_SEVEN_SEGMENT, character, LCD_SEVEN_SEGMENT_FONT_WIDTH);
            break;
        #endif
        #ifdef N5110_FONT_WIDE
        case N5110_FONT_WIDE:
            transmitFontDataLCD((const unsigned char **) ASCII_WIDE, character, LCD_WIDE_FONT_WIDTH);
            break;
        #endif
        #ifdef N5110_FONT_TINY
        case N5110_FONT_TINY:
            transmitFontDataLCD((const unsigned char **) ASCII_TINY, character, LCD_TINY_FONT_WIDTH);
            break;
        #endif
        #ifdef N5110_FONT_LARGE
        case N5110_FONT_LARGE:
            printLargeFontCharacter(character);
            break;
        #endif
        #ifdef N5110_FONT_HUGE
        case N5110_FONT_HUGE:
            printHugeFontCharacter(character);
            break;
        #endif
        #ifdef N5110_FONT_MEGA
        case N5110_FONT_MEGA:
            printMegaFontCharacter(character);
            break;
        #endif
        default:
            break;
    }
}

#ifdef N5110_FONT_LARGE
static void printLargeFontCharacter(char character) {
    chipSelectSet(&SPIInstance);
    for (uint8_t column = 0; column < LCD_LARGE_FONT_WIDTH; column++) {     //print upper byte
        transmit8BitsSPI(&SPIInstance, ASCII_LARGE[character - LCD_ASCII_OFFSET][column]);
    }
    goToXYN5110(columnPosition, ++rowPosition); // move to next block

    chipSelectSet(&SPIInstance);
    for (uint8_t column = 0; column < LCD_LARGE_FONT_WIDTH; column++) { //print lower byte
        transmit8BitsSPI(&SPIInstance, ((ASCII_LARGE[character - LCD_ASCII_OFFSET][column]) >> 8));
    }
    goToXYN5110((columnPosition + LCD_LARGE_FONT_WIDTH), --rowPosition);//move back to upper block
}
#endif

#ifdef N5110_FONT_HUGE
static void printHugeFontCharacter(char character) {
    chipSelectSet(&SPIInstance);
    for (uint8_t column = 0; column < LCD_HUGE_FONT_WIDTH; column++) {//print upper byte  DD
        transmit8BitsSPI(&SPIInstance, ASCII_HUGE[character - LCD_ASCII_OFFSET_ZERO][column]);
    }
    goToXYN5110(columnPosition, ++rowPosition); // move to next block

    chipSelectSet(&SPIInstance);
    for (uint8_t column = 0; column < LCD_HUGE_FONT_WIDTH; column++) {// print middle upper byte CC
        transmit8BitsSPI(&SPIInstance, ((ASCII_HUGE[character - LCD_ASCII_OFFSET_ZERO][column]) >> 8));
    }
    goToXYN5110(columnPosition, ++rowPosition); // move to next block

    chipSelectSet(&SPIInstance);
    for (uint8_t column = 0; column < LCD_HUGE_FONT_WIDTH; column++) {// print middle upper byte BB
        transmit8BitsSPI(&SPIInstance, ((ASCII_HUGE[character - LCD_ASCII_OFFSET_ZERO][column]) >> 16));
    }
    goToXYN5110(columnPosition + LCD_HUGE_FONT_WIDTH, rowPosition - 2); //move back for next character
}
#endif

#ifdef N5110_FONT_MEGA
static void printMegaFontCharacter(char character) {
    chipSelectSet(&SPIInstance);
    for (uint8_t column = 0; column < LCD_MEGA_FONT_WIDTH; column++) {//print upper byte  DD
        transmit8BitsSPI(&SPIInstance, ASCII_MEGA[character - LCD_ASCII_OFFSET_ZERO][column]);
    }
    goToXYN5110(columnPosition, ++rowPosition); // move to next block

    chipSelectSet(&SPIInstance);
    for (uint8_t column = 0; column < LCD_MEGA_FONT_WIDTH; column++) {// print middle upper byte CC
        transmit8BitsSPI(&SPIInstance, ((ASCII_MEGA[character - LCD_ASCII_OFFSET_ZERO][column]) >> 8));
    }
    goToXYN5110(columnPosition, ++rowPosition); // move to next block

    chipSelectSet(&SPIInstance);
    for (uint8_t column = 0; column < LCD_MEGA_FONT_WIDTH; column++) {// print middle upper byte BB
        transmit8BitsSPI(&SPIInstance, ((ASCII_MEGA[character - LCD_ASCII_OFFSET_ZERO][column]) >> 16));
    }
    goToXYN5110(columnPosition, ++rowPosition); // move to next block

    chipSelectSet(&SPIInstance);
    for (uint8_t column = 0; column < LCD_MEGA_FONT_WIDTH; column++) {// print middle upper byte AA
        transmit8BitsSPI(&SPIInstance, ((ASCII_MEGA[character - LCD_ASCII_OFFSET_ZERO][column]) >> 24));
    }
    goToXYN5110(columnPosition + LCD_HUGE_FONT_WIDTH, rowPosition - 3); 	//move back for next character
}
#endif

static void transmitFontDataLCD(void *fontArray, char character, uint8_t columnLength) {
    uint8_t dataByte;
    unsigned char (*arrayOfChars)[columnLength] = fontArray;
    for (int column = 0; column < columnLength; column++) {
        dataByte = arrayOfChars[character - LCD_ASCII_OFFSET][column];
        transmit8BitsSPI(&SPIInstance, textColor == BLACK ? dataByte : ~dataByte);
    }
    transmit8BitsSPI(&SPIInstance, textColor == BLACK ? 0x00 : 0xFF);   // Blank vertical line padding RHS
}