#include "main.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);

/* USER CODE BEGIN 0 */

#include "Nokia5110_LCD.h"
#include "Images.h"

#define ARRAY_SIZE(array) (sizeof((array)) / sizeof(unsigned char))

// Custom Characters for  TEST 9 Custom Character
const unsigned char POWER_ICON[12] = {0xff, 0xe7, 0xc3, 0x99, 0xa5, 0xad, 0xad, 0xa5, 0x99, 0xc3, 0xe7, 0xff};
const unsigned char LIGHTING_SYMBOL[12] = {0xff, 0xff, 0xf7, 0xb3, 0xd1, 0xc0, 0xe0, 0xf4, 0xf6, 0xfe, 0xff, 0xff};

void testFont0() {
    clearN5110();
    setFontN5110(N5110_FONT_DEFAULT);
    goToXYN5110(0, 0);
    printStringN5110("АБВГД1234");
    goToXYN5110(0, 1);
    printStringN5110("Русские буквы");
    goToXYN5110(0, 2);
    printStringN5110("Привет Мир!!");
    LL_mDelay(5000);
}

void testFont1() {
    clearN5110();
    setFontN5110(N5110_FONT_DEFAULT);
    goToXYN5110(0, 0);
    printStringN5110("1234567890ABCD");
    LL_mDelay(1000);

    setFontN5110(N5110_FONT_THICK);
    goToXYN5110(0, 1);
    printStringN5110("THICKFONT");
    LL_mDelay(1000);

    setFontN5110(N5110_FONT_AUREBESH);
    goToXYN5110(0, 2);
    printStringN5110("5FYABCDEFGI");
    LL_mDelay(1000);

    setFontN5110(N5110_FONT_SEVEN_SEGMENT);
    goToXYN5110(0, 3);
    printStringN5110("7 Segment font");
    LL_mDelay(1000);

    setFontN5110(N5110_FONT_WIDE);
    goToXYN5110(0, 4);
    printStringN5110("ABCD1234");
    LL_mDelay(1000);

    setFontN5110(N5110_FONT_TINY);
    goToXYN5110(0, 5);
    printStringN5110("Tiny font 16wide");
    LL_mDelay(5000);
}

void testFont2(void) {
    clearN5110(); // clear whole screen
    setFontN5110(N5110_FONT_LARGE); // font 7
    goToXYN5110(20, 1);
    printStringN5110("TIME");
    goToXYN5110(15, 3); // this font takes two blocks
    printStringN5110("23:04");
    LL_mDelay(5000);
}

void testFont3(void) {
    clearN5110();
    setFontN5110(N5110_FONT_HUGE);  // font 8 this font takes 3 blocks
    goToXYN5110(0, 0);
    printStringN5110("10:39");
    goToXYN5110(0, 3);
    printStringN5110("4.288");
    LL_mDelay(5000);
}

void testFont4(void) {
    clearN5110();
    setFontN5110(N5110_FONT_MEGA);  // font 9, this font takes 4 blocks
    goToXYN5110(0, 1);
    printStringN5110("14:23");
    LL_mDelay(5000);
}

void menu(uint8_t menuNumber) {
    clearN5110();
    setFontN5110(N5110_FONT_DEFAULT);
    static char menuItemArray[6][20] = {
            {"Location Info"},
            {"Connect"},
            {"Disconnect"},
            {"Light Switch"},
            {"Power Down"},
            {"Reset Sim800L"}
    };
    for (uint8_t i = 0; i < 6; i++) {
        if (i == menuNumber) {
            fillBlockN5110(0xFF, i);
            setTextColorN5110(WHITE);
            goToXYN5110(0, i);
            printStringN5110(menuItemArray[i]);
        } else {
            setTextColorN5110(BLACK);
            goToXYN5110(0, i);
            printStringN5110(menuItemArray[i]);
        }
    }
    setTextColorN5110(BLACK);
}

void testMenu() {
    for (int i = 0; i < 6; ++i) {
        menu(i);
        LL_mDelay(1000);
    }
    LL_mDelay(5000);
}

void testDrawLines() {
    clearN5110();
    printStringN5110("Draw Lines");
    LL_mDelay(1000);

    for (uint8_t col = 3; col < 71; col++) {
        setPixelN5110(col, 23);
        setPixelN5110(col, 31);
    }
    LL_mDelay(5000);
}

void testCustomCharacters() {
    clearN5110();
    printStringN5110("Custom Char");
    goToXYN5110(40, 2);
    printCustomCharacter(POWER_ICON, ARRAY_SIZE(POWER_ICON), PADDING_ALL);
    goToXYN5110(40, 4);
    printCustomCharacter(LIGHTING_SYMBOL, ARRAY_SIZE(LIGHTING_SYMBOL), PADDING_ALL);
    LL_mDelay(5000);
}

void design1() {
    clearN5110();
    setFontN5110(N5110_FONT_TINY);
    goToXYN5110(12, 0);
    printStringN5110("FREQUENCY: KHZ");

    goToXYN5110(0, 1);
    for (uint8_t col = 3; col < 81; col++) {
        setPixelN5110(col, 12);
    }

    goToXYN5110(0, 2);
    setFontN5110(N5110_FONT_MEGA);
    printStringN5110("15.93");
    LL_mDelay(5000);
}

void design2() {
    clearN5110();
    fillBlockN5110(0x3, 0);    // pattern: 0b00000011 -> 2px fat line
    setFontN5110(N5110_FONT_WIDE);
    goToXYN5110(0, 1);
    printStringN5110("VOLTAGE");
    goToXYN5110(65, 1);
    printCustomCharacter(POWER_ICON, ARRAY_SIZE(POWER_ICON), PADDING_LEFT);
    goToXYN5110(0, 3);
    setFontN5110(N5110_FONT_HUGE);
    printStringN5110("5.034");
    LL_mDelay(5000);
}

void images() {
    clearN5110();
    printImageN5110(Apple_Logo);
    LL_mDelay(5000);
    printImageN5110(Tesla_Logo);
    LL_mDelay(5000);

}

int main(void) {
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

    NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_0);

    SystemClock_Config();

    MX_GPIO_Init();
    MX_SPI1_Init();

    initN5110(SPI1);

    while (1) {
        testFont0();
        testFont1();
        testFont2();
        testFont3();
        testFont4();

        testMenu();

        testDrawLines();
        testCustomCharacters();

        design1();
        design2();

        images();
    }
}

/* USER CODE END 0 */


void SystemClock_Config(void) {
    LL_FLASH_SetLatency(LL_FLASH_LATENCY_2);
    while (LL_FLASH_GetLatency() != LL_FLASH_LATENCY_2) {
    }
    LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE2);
    LL_RCC_HSI_SetCalibTrimming(16);
    LL_RCC_HSI_Enable();

    /* Wait till HSI is ready */
    while (LL_RCC_HSI_IsReady() != 1) {

    }
    LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSI, LL_RCC_PLLM_DIV_16, 336, LL_RCC_PLLP_DIV_4);
    LL_RCC_PLL_Enable();

    /* Wait till PLL is ready */
    while (LL_RCC_PLL_IsReady() != 1) {

    }
    LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
    LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
    LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
    LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

    /* Wait till System clock is ready */
    while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL) {

    }
    LL_Init1msTick(84000000);
    LL_SetSystemCoreClock(84000000);
    LL_RCC_SetTIMPrescaler(LL_RCC_TIM_PRESCALER_TWICE);
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void) {

    /* USER CODE BEGIN SPI1_Init 0 */

    /* USER CODE END SPI1_Init 0 */

    LL_SPI_InitTypeDef SPI_InitStruct = {0};

    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* Peripheral clock enable */
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1);

    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    /**SPI1 GPIO Configuration
    PA5   ------> SPI1_SCK
    PA6   ------> SPI1_MISO
    PA7   ------> SPI1_MOSI
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_5 | LL_GPIO_PIN_6 | LL_GPIO_PIN_7;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USER CODE BEGIN SPI1_Init 1 */

    /* USER CODE END SPI1_Init 1 */
    /* SPI1 parameter configuration*/
    SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
    SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
    SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
    SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_LOW;
    SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
    SPI_InitStruct.NSS = LL_SPI_NSS_SOFT;
    SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV8;
    SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
    SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
    SPI_InitStruct.CRCPoly = 10;
    LL_SPI_Init(SPI1, &SPI_InitStruct);
    LL_SPI_SetStandard(SPI1, LL_SPI_PROTOCOL_MOTOROLA);
    /* USER CODE BEGIN SPI1_Init 2 */

    /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void) {
    LL_EXTI_InitTypeDef EXTI_InitStruct = {0};
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);

    /**/
    LL_GPIO_ResetOutputPin(GPIOC, N5110_RST_Pin | N5110_DC_Pin);

    /**/
    LL_GPIO_ResetOutputPin(CHIP_SELECT_GPIO_Port, CHIP_SELECT_Pin);

    /**/
    LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTC, LL_SYSCFG_EXTI_LINE13);

    /**/
    EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_13;
    EXTI_InitStruct.LineCommand = ENABLE;
    EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
    EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_FALLING;
    LL_EXTI_Init(&EXTI_InitStruct);

    /**/
    LL_GPIO_SetPinPull(B1_GPIO_Port, B1_Pin, LL_GPIO_PULL_NO);

    /**/
    LL_GPIO_SetPinMode(B1_GPIO_Port, B1_Pin, LL_GPIO_MODE_INPUT);

    /**/
    GPIO_InitStruct.Pin = N5110_RST_Pin | N5110_DC_Pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /**/
    GPIO_InitStruct.Pin = CHIP_SELECT_Pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(CHIP_SELECT_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void) {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1) {
    }
    /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
