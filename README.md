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

<img src="https://github.com/ximtech/Nokia5110_LCD/blob/main/example/pinout.PNG" alt="image" width="300"/>

## Usage

- Polling SPI LCD usage example: [link](https://github.com/ximtech/HD44780_I2C/blob/main/example/example.c)
- Interrupt SPI LCD usage example: [link](https://github.com/ximtech/HD44780_I2C/blob/main/example/example_IT.c)
- Interrupt handler: [link](https://github.com/ximtech/HD44780_I2C/blob/main/example/stm32f4xx_it.c)

Image Converter: [link](https://github.com/ximtech/HD44780_I2C/blob/main/example//Image2GLCD)

- <img src="https://github.com/ximtech/Nokia5110_LCD/blob/main/example/Image2GLCD/Image_Converter.PNG" alt="image" width="300"/>
- <img src="https://github.com/ximtech/Nokia5110_LCD/blob/main/example/Image2GLCD/Image_Converter2.PNG" alt="image" width="300"/>
