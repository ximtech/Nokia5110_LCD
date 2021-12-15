cmake_minimum_required(VERSION 3.20)
project(NOKIA5110_LCD C)

set(CMAKE_C_STANDARD 99)

include(cmake/CPM.cmake)

CPMAddPackage(
        NAME STM32Core
        GITHUB_REPOSITORY ximtech/STM32Core
        GIT_TAG origin/main)

set(NOKIA5110_LCD_DIRECTORY
        ${SPI_POLLING_DIRECTORY}
        ${NOKIA5110_LCD_SOURCE_DIR}
        ${NOKIA5110_LCD_SOURCE_DIR}/Fonts
        ${NOKIA5110_LCD_SOURCE_DIR}/include
        CACHE STRING "NOKIA5110 LCD directories include to the main project" FORCE)

set(NOKIA5110_LCD_SOURCES
        ${SPI_POLLING_SOURCES}
        ${NOKIA5110_LCD_SOURCE_DIR}/Fonts/*.h
        ${NOKIA5110_LCD_SOURCE_DIR}/Nokia5110_LCD.c
        ${NOKIA5110_LCD_SOURCE_DIR}/include/Nokia5110_LCD.h
        CACHE STRING "NOKIA5110 LCD source files include to the main project" FORCE)

set(NOKIA5110_LCD_IT_DIRECTORY
        ${SPI_IT_DIRECTORY}
        ${NOKIA5110_LCD_SOURCE_DIR}
        ${NOKIA5110_LCD_SOURCE_DIR}/Fonts
        ${NOKIA5110_LCD_SOURCE_DIR}/include
        CACHE STRING "NOKIA5110 LCD IT directories include to the main project" FORCE)

set(NOKIA5110_LCD_IT_SOURCES
        ${SPI_IT_SOURCES}
        ${NOKIA5110_LCD_SOURCE_DIR}/Fonts/*.h
        ${NOKIA5110_LCD_SOURCE_DIR}/Nokia5110_LCD_IT.c
        ${NOKIA5110_LCD_SOURCE_DIR}/include/Nokia5110_LCD_IT.h
        CACHE STRING "NOKIA5110 LCD IT source files include to the main project" FORCE)