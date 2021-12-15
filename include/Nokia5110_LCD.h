#pragma once

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "SPI_Polling.h"

#define N5110_DC_GPIO_PORT       GPIOC
#define N5110_RESET_GPIO_PORT    GPIOC
#define N5110_CHIP_SELECT_PORT   GPIOA

#define N5110_DC_PIN             LL_GPIO_PIN_1
#define N5110_RESET_PIN          LL_GPIO_PIN_0
#define N5110_CHIP_SELECT_PIN    LL_GPIO_PIN_4

// Font define section. Uncomment fonts what you want to use
#define N5110_FONT_DEFAULT       1
//#define N5110_FONT_THICK         2
//#define N5110_FONT_AUREBESH      3
//#define N5110_FONT_SEVEN_SEGMENT 4
//#define N5110_FONT_WIDE          5
//#define N5110_FONT_TINY          6
//#define N5110_FONT_LARGE         7
//#define N5110_FONT_HUGE          8
//#define N5110_FONT_MEGA          9

#ifdef N5110_FONT_DEFAULT
#include "Fonts/Nokia5110_Font_Default_5x8.h"
#endif
#ifdef N5110_FONT_THICK
#include "Fonts/Nokia5110_Font_Thick_7x8.h" // NO LOWERCASE LETTERS
#endif
#ifdef N5110_FONT_AUREBESH
#include "Fonts/Nokia5110_Font_Aurebesh_5x8.h"
#endif
#ifdef N5110_FONT_SEVEN_SEGMENT
#include "Fonts/Nokia5110_Font_Seven_Segment_4x8.h"
#endif
#ifdef N5110_FONT_WIDE
#include "Fonts/Nokia5110_Font_Wide_8x8.h" // NO LOWERCASE LETTERS
#endif
#ifdef N5110_FONT_TINY
#include "Fonts/Nokia5110_Font_Tiny_3x8.h"
#endif
#ifdef N5110_FONT_LARGE
#include "Fonts/Nokia5110_Font_Large_12x16.h" // NO LOWERCASE LETTERS
#endif
#ifdef N5110_FONT_HUGE
#include "Fonts/Nokia5110_Font_Huge_16x24.h" // only: numbers, '+', '.', ':'
#endif
#ifdef N5110_FONT_MEGA
#include "Fonts/Nokia5110_Font_Mega_16x32.h" // only: numbers, '+', '.', ':'
#endif

#define FUNCTION_SET_COMMAND_REGISTER  0b00100000
#define H_BASIC_INSTRUCTION_SET       (FUNCTION_SET_COMMAND_REGISTER)
#define H_EXTENDED_INSTRUCTION_SET    (FUNCTION_SET_COMMAND_REGISTER | 0b00000001)
#define V_VERTICAL_ADDRESSING         (FUNCTION_SET_COMMAND_REGISTER | 0b00000010)
#define PD_CHIP_IS_IN_POWER_DOWN_MODE (FUNCTION_SET_COMMAND_REGISTER | 0b00000100)

// Commands for H_BASIC_INSTRUCTION_SET
#define DISPLAY_CONTROL_COMMAND_REGISTER  0b00001000
#define DISPLAY_BLANK                    (DISPLAY_CONTROL_COMMAND_REGISTER & ~(0b00000101)
#define DISPLAY_NORMAL_MODE              (DISPLAY_CONTROL_COMMAND_REGISTER | 0b00000100)
#define DISPLAY_ALL_SEGMENTS_ON          (DISPLAY_CONTROL_COMMAND_REGISTER | 0b00000001)
#define DISPLAY_INVERSE_VIDEO_MODE       (DISPLAY_CONTROL_COMMAND_REGISTER | 0b00000101)

#define SET_Y_ADDRESS_OF_RAM_COMMAND_REGISTER 0b01000000    // Format: 01000 Y2 Y1 Y0. Sets Y-address of RAM; 0 ≤ Y ≤ 5. Yn defines the Y vector addressing of the display RAM
#define Y_ADDRESS_OF_BANK_0 (SET_Y_ADDRESS_OF_RAM_COMMAND_REGISTER)
#define Y_ADDRESS_OF_BANK_1 (SET_Y_ADDRESS_OF_RAM_COMMAND_REGISTER | 0b00000001)
#define Y_ADDRESS_OF_BANK_2 (SET_Y_ADDRESS_OF_RAM_COMMAND_REGISTER | 0b00000010)
#define Y_ADDRESS_OF_BANK_3 (SET_Y_ADDRESS_OF_RAM_COMMAND_REGISTER | 0b00000011)
#define Y_ADDRESS_OF_BANK_4 (SET_Y_ADDRESS_OF_RAM_COMMAND_REGISTER | 0b00000100)
#define Y_ADDRESS_OF_BANK_5 (SET_Y_ADDRESS_OF_RAM_COMMAND_REGISTER | 0b00000101)

#define SET_X_ADDRESS_OF_RAM_COMMAND_REGISTER 0b10000000    // Format: 1 X6 X5 X4 X3 X2 X1 X0. Sets X-address part of RAM; 0 ≤ X ≤ 83. The X address points to the columns. The range of X is 0 to 83 (53H).

// Commands for H_EXTENDED_INSTRUCTION_SET
#define TEMPERATURE_CONTROL_COMMAND_REGISTER 0b00000100
#define TEMPERATURE_COEFFICIENT_0   (TEMPERATURE_CONTROL_COMMAND_REGISTER)
#define TEMPERATURE_COEFFICIENT_1   (TEMPERATURE_CONTROL_COMMAND_REGISTER | 0b00000001)
#define TEMPERATURE_COEFFICIENT_2   (TEMPERATURE_CONTROL_COMMAND_REGISTER | 0b00000010)
#define TEMPERATURE_COEFFICIENT_3   (TEMPERATURE_CONTROL_COMMAND_REGISTER | 0b00000011)

#define BIAS_SYSTEM_COMMAND_REGISTER 0b00010000     // Format: 000010 BS2 BS1 BS0. Set Bias System (BSx)
#define BIAS_VALUE_MUX_RATE_1X100        (BIAS_SYSTEM_COMMAND_REGISTER)
#define BIAS_VALUE_MUX_RATE_1X80         (BIAS_SYSTEM_COMMAND_REGISTER | 0b00000001)
#define BIAS_VALUE_MUX_RATE_1X65_1X65    (BIAS_SYSTEM_COMMAND_REGISTER | 0b00000010)
#define BIAS_VALUE_MUX_RATE_1X48         (BIAS_SYSTEM_COMMAND_REGISTER | 0b00000011)
#define BIAS_VALUE_MUX_RATE_1X40_1X34    (BIAS_SYSTEM_COMMAND_REGISTER | 0b00000100)
#define BIAS_VALUE_MUX_RATE_1X24         (BIAS_SYSTEM_COMMAND_REGISTER | 0b00000101)
#define BIAS_VALUE_MUX_RATE_1X18_1X16    (BIAS_SYSTEM_COMMAND_REGISTER | 0b00000110)
#define BIAS_VALUE_MUX_RATE_1X10_1X9_1X8 (BIAS_SYSTEM_COMMAND_REGISTER | 0b00000111)

// VLCD = a + (VOP6 to VOP0) × b [V]. In the PCD8544, a = 3.06 and b = 0.06 giving a program range of 3.00 to 10.68 at room temperature.
#define VOP_COMMAND_REGISTER 0b10000000     // 01 VOP6 VOP5 VOP4 VOP3 VOP2 VOP1 VOP0. Write VOP to register.
#define VOP_BIAS_VOLTAGE_MEDIUM_CONTRAST (VOP_COMMAND_REGISTER | 0b01000000)  // base contrast
#define VOP_BIAS_VOLTAGE_HIGH_CONTRAST   (VOP_COMMAND_REGISTER | 0b00111111) // try different contrast values in range = (VOP_COMMAND_REGISTER | (0x00-0x7F))

typedef enum N5110TextColor {
    BLACK, WHITE
} TextColor;

typedef enum N5110CustomCharacterPadding {
    PADDING_LEFT,
    PADDING_RIGHT,
    PADDING_ALL,
    PADDING_NONE
} CustomCharacterPadding;

void initN5110(SPI_TypeDef *SPIx);

void printCharN5110(char character);
void printStringN5110(const char *string);
void printfStringN5110(char *format, ...);
void printImageN5110(const uint8_t *imageData);
void fillBlockN5110(uint8_t fillData, uint8_t rowBlockNum);
void printCustomCharacter(const unsigned char characterData[], uint16_t length, CustomCharacterPadding padding);
void clearN5110(); // clear the display

void setFontN5110(uint8_t font);    // set font from 1 to 9, see font define section
void setTextColorN5110(TextColor color);
void goToXYN5110(uint8_t x, uint8_t y); // set the column and row
void setPixelN5110(uint8_t column, uint8_t row);

void commandN5110(char command);
void resetN5110();