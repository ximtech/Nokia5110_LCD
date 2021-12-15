# Nokia5110_LCD

**STM32** Low Layer(LL) library. At the heart of the module is a powerful single-chip low power CMOS LCD driver
controller from Philips – PCD8544. The chip is designed to drive a graphic display of 84×48 pixels. It interfaces to
microcontrollers through a serial bus interface SPI.

### Features

- Small code footprint
- Interrupt and Polling LCD SPI versions
- Lot of predefined fonts
- Display printf function
- No HAL dependencies

<img src="https://github.com/ximtech/Nokia5110_LCD/blob/main/example/nokia5110.PNG" alt="image" width="300"/>

### Add as CPM project dependency

How to add CPM to the project, check the [link](https://github.com/cpm-cmake/CPM.cmake)

```cmake
CPMAddPackage(
        NAME Nokia5110_LCD
        GITHUB_REPOSITORY ximtech/Nokia5110_LCD
        GIT_TAG origin/main)
```

### Project configuration

1. Start project with STM32CubeMX:
    * [SPI configuration](https://github.com/ximtech/Nokia5110_LCD/blob/main/example/spi_no_nvic.PNG)
    * [GPIO configuration](https://github.com/ximtech/Nokia5110_LCD/blob/main/example/gpio.PNG)
2. Select: Project Manager -> Advanced Settings -> SPI -> LL
3. Generate Code
4. Add sources to project:

- **Polling LCD SPI**

```cmake
add_subdirectory(${STM32_CORE_SOURCE_DIR}/SPI/Polling)  # add SPI dependency

include_directories(${includes}
        ${NOKIA5110_LCD_DIRECTORY})   # source directories

file(GLOB_RECURSE SOURCES ${sources}
        ${NOKIA5110_LCD_SOURCES})    # source files
```

- ***Interrupt based LCD***

```cmake
add_subdirectory(${STM32_CORE_SOURCE_DIR}/SPI/IT)  # add for interrupt version

include_directories(${includes}
        ${NOKIA5110_LCD_IT_DIRECTORY})   # source directories

file(GLOB_RECURSE SOURCES ${sources}
        ${NOKIA5110_LCD_IT_SOURCES})    # source files
```

3. Then Build -> Clean -> Rebuild Project

## Wiring

<img src="https://github.com/ximtech/Nokia5110_LCD/blob/main/example/pinout.png" alt="image" width="300"/>

## Demo video

[![Image](https://img.youtube.com/vi/kKUFJGqaLlI/0.jpg)](https://www.youtube.com/watch?v=kKUFJGqaLlI)

## Usage

In `main.h` set configuration defines or use defaults from `Nokia5110_LCD.h`
```c
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
```

- Polling SPI LCD usage example: [link](https://github.com/ximtech/Nokia5110_LCD/blob/main/example/example.c)
- Interrupt SPI LCD usage example: [link](https://github.com/ximtech/Nokia5110_LCD/blob/main/example/example_IT.c)
- Interrupt handler: [link](https://github.com/ximtech/Nokia5110_LCD/blob/main/example/stm32f4xx_it.c)

Image Converter: [link](https://github.com/ximtech/Nokia5110_LCD/blob/main/example//Image2GLCD)

- <img src="https://github.com/ximtech/Nokia5110_LCD/blob/main/example/Image2GLCD/Image_Converter.PNG" alt="image" width="300"/>
- <img src="https://github.com/ximtech/Nokia5110_LCD/blob/main/example/Image2GLCD/Image_Converter2.PNG" alt="image" width="300"/>
