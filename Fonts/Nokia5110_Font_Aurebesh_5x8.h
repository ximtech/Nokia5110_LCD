#pragma once

// ASCII font file : AUREBESH FONT 5 by 8

// Define the AUREBESH/ASCII table as Data array
// cols left to right 0x00 is  off 0xFF is all on
// each character is five bits wide one byte height. 
// so ! is 0 0 5F 0 0

static const unsigned char ASCII_AUREBESH[][5] = {
        {0x00, 0x00, 0x00, 0x00, 0x00}, // 20
        {0x00, 0x00, 0x5f, 0x00, 0x00}, // 21 !
        {0x00, 0x07, 0x00, 0x07, 0x00}, // 22 ?
        {0x14, 0x7f, 0x14, 0x7f, 0x14}, // 23 #
        {0x24, 0x2a, 0x7f, 0x2a, 0x12}, // 24 $
        {0x23, 0x13, 0x08, 0x64, 0x62}, // 25 %
        {0x36, 0x49, 0x55, 0x22, 0x50}, // 26 &
        {0x00, 0x05, 0x03, 0x00, 0x00}, // 27 ?
        {0x00, 0x1c, 0x22, 0x41, 0x00}, // 28 (
        {0x00, 0x41, 0x22, 0x1c, 0x00}, // 29 )
        {0x14, 0x08, 0x3e, 0x08, 0x14}, // 2a *
        {0x08, 0x08, 0x3e, 0x08, 0x08}, // 2b +
        {0x00, 0x50, 0x30, 0x00, 0x00}, // 2c ,
        {0x08, 0x08, 0x08, 0x08, 0x08}, // 2d ?
        {0x00, 0x60, 0x60, 0x00, 0x00}, // 2e .
        {0x20, 0x10, 0x08, 0x04, 0x02}, // 2f /
        {0x3e, 0x22, 0x2A, 0x22, 0x3e}, // 30 0
        {0x00, 0x41, 0x7f, 0x40, 0x00}, // 31 1
        {0x4A, 0x4A, 0x4A, 0x4A, 0x4E}, // 32 2
        {0x49, 0x49, 0x49, 0x41, 0x7F}, // 33 3
        {0x0F, 0x08, 0x08, 0x08, 0x7F}, // 34 4
        {0x49, 0x49, 0x49, 0x49, 0x79}, // 35 5
        {0x79, 0x49, 0x49, 0x49, 0x79}, // 36 6
        {0x01, 0x01, 0x01, 0x01, 0x7F}, // 37 7
        {0x7F, 0x49, 0x49, 0x49, 0x7F}, // 38 8
        {0x4F, 0x49, 0x49, 0x49, 0x4F}, // 39 9
        {0x00, 0x36, 0x36, 0x00, 0x00}, // 3a :
        {0x00, 0x56, 0x36, 0x00, 0x00}, // 3b ;
        {0x08, 0x14, 0x22, 0x41, 0x00}, // 3c <
        {0x14, 0x14, 0x14, 0x14, 0x14}, // 3d =
        {0x00, 0x41, 0x22, 0x14, 0x08}, // 3e >
        {0x02, 0x01, 0x51, 0x09, 0x06}, // 3f ?
        {0x32, 0x49, 0x79, 0x41, 0x3e}, // 40 @
        {0x66, 0x24, 0x24, 0x42, 0x42}, // 41 A
        {0x22, 0x49, 0x49, 0x49, 0x22}, // 42 B
        {0x70, 0x00, 0x10, 0x00, 0x1C}, // 43 C
        {0x25, 0x15, 0x0D, 0x07, 0x01}, // 44 D
        {0x03, 0x0C, 0x30, 0x0C, 0x7f}, // 45 E
        {0x3C, 0x24, 0x3E, 0x24, 0x22}, // 46 F
        {0x3f, 0x10, 0x09, 0x05, 0x03}, // 47 G
        {0x41, 0x49, 0x49, 0x49, 0x41}, // 48 H
        {0x00, 0x02, 0x7f, 0x00, 0x00}, // 49 I
        {0x44, 0x44, 0x44, 0x72, 0x0F}, // 4a J
        {0x41, 0x41, 0x41, 0x41, 0x7F}, // 4b K
        {0x04, 0x08, 0x10, 0x20, 0x7F}, // 4c L
        {0x60, 0x50, 0x48, 0x44, 0x44}, // 4d M
        {0x3E, 0x41, 0x38, 0x06, 0x78}, // 4e N
        {0x60, 0x5C, 0x44, 0x5C, 0x60}, // 4f O
        {0x3E, 0x41, 0x40, 0x40, 0x7F}, // 50 P
        {0x7f, 0x41, 0x41, 0x01, 0x03}, // 51 Q
        {0x21, 0x11, 0x09, 0x05, 0x03}, // 52 R
        {0x12, 0x24, 0x48, 0x10, 0x7F}, // 53 S
        {0x10, 0x20, 0x3f, 0x20, 0x10}, // 54 T
        {0x7f, 0x40, 0x42, 0x41, 0x7f}, // 55 U
        {0x02, 0x04, 0x78, 0x04, 0x02}, // 56 V
        {0x7f, 0x41, 0x41, 0x41, 0x7f}, // 57 W
        {0x1C, 0x12, 0x11, 0x12, 0x1C}, // 58 X
        {0x07, 0x19, 0x62, 0x18, 0x07}, // 59 Y
        {0x68, 0x44, 0x42, 0x42, 0x7F}, // 5a Z
        {0x00, 0x7f, 0x41, 0x41, 0x00}, // 5b [
        {0x02, 0x04, 0x08, 0x10, 0x20}, // 5c forward slash
        {0x00, 0x41, 0x41, 0x7f, 0x00}, // 5d ]
        {0x04, 0x02, 0x01, 0x02, 0x04}, // 5e ^
        {0x40, 0x40, 0x40, 0x40, 0x40}, // 5f _
        {0x00, 0x01, 0x02, 0x04, 0x00}, // 60 `
        {0x66, 0x24, 0x24, 0x42, 0x42}, // 41 A
        {0x28, 0x54, 0x54, 0x54, 0x28}, // 42 B
        {0x70, 0x00, 0x10, 0x00, 0x1C}, // 43 C
        {0x25, 0x15, 0x0D, 0x07, 0x01}, // 44 D
        {0x03, 0x0C, 0x30, 0x0C, 0x7f}, // 45 E
        {0x3C, 0x24, 0x3E, 0x24, 0x22}, // 46 F
        {0x3f, 0x10, 0x09, 0x05, 0x03}, // 47 G
        {0x41, 0x49, 0x49, 0x49, 0x41}, // 48 H
        {0x00, 0x02, 0x7f, 0x00, 0x00}, // 49 I
        {0x44, 0x44, 0x44, 0x72, 0x0F}, // 4a J
        {0x41, 0x41, 0x41, 0x41, 0x7F}, // 4b K
        {0x04, 0x08, 0x10, 0x20, 0x7F}, // 4c L
        {0x60, 0x50, 0x48, 0x44, 0x44}, // 4d M
        {0x3E, 0x41, 0x38, 0x06, 0x78}, // 4e N
        {0x60, 0x5C, 0x44, 0x5C, 0x60}, // 4f O
        {0x3E, 0x41, 0x40, 0x40, 0x7F}, // 50 P
        {0x7f, 0x41, 0x41, 0x01, 0x03}, // 51 Q
        {0x21, 0x11, 0x09, 0x05, 0x03}, // 52 R
        {0x12, 0x24, 0x48, 0x10, 0x7F}, // 53 S
        {0x10, 0x20, 0x3f, 0x20, 0x10}, // 54 T
        {0x7f, 0x40, 0x42, 0x41, 0x7f}, // 55 U
        {0x02, 0x04, 0x78, 0x04, 0x02}, // 56 V
        {0x7f, 0x41, 0x41, 0x41, 0x7f}, // 57 W
        {0x1C, 0x12, 0x11, 0x12, 0x1C}, // 58 X
        {0x07, 0x19, 0x62, 0x18, 0x07}, // 59 Y
        {0x68, 0x44, 0x42, 0x42, 0x7F} // 5a Z
};