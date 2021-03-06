#pragma once

// ASCII font file : large 12 by 16

// Define the ASCII table as Data array
// cols left to right, 0x00 is off, 0xFF is all on
// Each character is 12 bits wide, two byte height.

// NO LOWERCASE LETTERS

static const uint16_t ASCII_LARGE[][12] = {
        {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000}, //
        {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x39FE, 0x39FE, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000}, // !
        {0x0000, 0x0000, 0x0000, 0x00FC, 0x00FC, 0x0000, 0x0000, 0x00FC, 0x00FC, 0x0000, 0x0000, 0x0000}, // "
        {0x0000, 0x0000, 0x0810, 0x0810, 0x7FFE, 0x0810, 0x0810, 0x7FFE, 0x0810, 0x0810, 0x0000, 0x0000}, // #
        {0x0000, 0x0000, 0x0000, 0x3070, 0x18D8, 0x3FFE, 0x1B0C, 0x0618, 0x0030, 0x0000, 0x0000, 0x0000}, // $
        {0x0000, 0x3000, 0x1800, 0x0C3E, 0x0622, 0x033E, 0x0180, 0x00C0, 0x3E60, 0x2230, 0x3E18, 0x0000}, // %
        {0X0000, 0x007f, 0x007f, 0x006b, 0x0063, 0x0068, 0x0078, 0x0078, 0x0000, 0x0000, 0x0000, 0X0000}, // &
        {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x003F, 0x003F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000}, // '
        {0x0000, 0x0000, 0x1FFC, 0x3FFE, 0x2002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000}, // (
        {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2002, 0x3FFE, 0x1FFC, 0x0000, 0x0000}, // )
        {0x0000, 0x18C6, 0x0CCC, 0x06D8, 0x03F0, 0x7FFE, 0x7FFE, 0x03F0, 0x06D8, 0x0CCC, 0x18C6, 0x0000}, // *
        {0x0000, 0x0380, 0x0380, 0x0380, 0x7FFE, 0x7FFE, 0x7FFE, 0x0380, 0x0380, 0x0380, 0x0000, 0x0000}, // +
        {0x0000, 0x0000, 0x0000, 0x4000, 0x6000, 0x7E00, 0x7F00, 0x0380, 0x0000, 0x0000, 0x0000, 0x0000}, // ,
        {0x0000, 0x03C0, 0x03C0, 0x03C0, 0x03C0, 0x03C0, 0x03C0, 0x03C0, 0x03C0, 0x03C0, 0x03C0, 0x0000}, // -
        {0x0000, 0x0000, 0x0000, 0x7F00, 0x7F00, 0x7F00, 0x7F00, 0x7F00, 0x0000, 0x0000, 0x0000, 0x0000}, // .
        {0x0000, 0x7000, 0x3800, 0x1C00, 0x0E00, 0x0700, 0x0380, 0x01C0, 0x00E0, 0x0070, 0x0038, 0x0000}, // /
        {0x0000, 0x0000, 0x3FFF, 0x3FFF, 0x3103, 0x3083, 0x3043, 0x3023, 0x3FFF, 0x3FFF, 0x0000, 0x0000}, // 0
        {0x0000, 0x0000, 0x000C, 0x000C, 0x3006, 0x3006, 0x3FFF, 0x3FFF, 0x3FFF, 0x3000, 0x3000, 0x0000}, // 1
        {0x0000, 0x0000, 0x0000, 0x3FC3, 0x3FC3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30FF, 0x30FF, 0x0000}, // 2
        {0x0000, 0x0000, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x3FFF, 0x3FFF, 0x0000, 0x0000}, // 3
        {0x0000, 0x0000, 0x00FF, 0x00FF, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x3FFF, 0x3FFF, 0x0000, 0x0000}, // 4
        {0x0000, 0x0000, 0x30FF, 0x30FF, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x3FC3, 0x3FC3, 0x0000, 0x0000}, // 5
        {0x0000, 0x0000, 0x3FFF, 0x3FFF, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x3FC3, 0x3FC3, 0x0000, 0x0000}, // 6
        {0x0000, 0x0000, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x3FFF, 0x3FFF, 0x0000, 0x0000}, // 7
        {0x0000, 0x0000, 0x3FFF, 0x3FFF, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x3FFF, 0x3FFF, 0x0000, 0x0000}, // 8
        {0x0000, 0x0000, 0x30FF, 0x30FF, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x3FFF, 0x3FFF, 0x0000, 0x0000}, // 9
        {0x0000, 0x0000, 0x0000, 0x0000, 0x3E3E, 0x3E3E, 0x3E3E, 0x3E3E, 0x0000, 0x0000, 0x0000, 0x0000}, // :
        {0x0000, 0x0000, 0x0000, 0x3000, 0x1E3E, 0x0E3E, 0x063E, 0x023E, 0x0000, 0x0000, 0x0000, 0x0000}, // ;
        {0x0180, 0x0660, 0x0C30, 0x1818, 0x300C, 0x6006, 0x4002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000}, // <
        {0x0000, 0x0198, 0x0198, 0x0198, 0x0198, 0x0198, 0x0198, 0x0198, 0x0198, 0x0198, 0x0198, 0x0000}, // =
        {0x0000, 0x0000, 0x0000, 0x0000, 0x6006, 0x6006, 0x300C, 0x1818, 0x0C30, 0x0660, 0x0180, 0x0000}, // >
        {0x0000, 0x0018, 0x0018, 0x000C, 0x0006, 0x6706, 0x6706, 0x07FE, 0x00FE, 0x0000, 0x0000, 0x0000}, // ?
        {0x0000, 0x1F00, 0x3FF0, 0x307C, 0x27CE, 0x26C6, 0x06C6, 0x06C6, 0x0606, 0x07FE, 0x07FE, 0x0000}, // @
        {0x0000, 0x3FFE, 0x3FFF, 0x3FFF, 0x01C3, 0x01C3, 0x01C3, 0x01C3, 0x3FFF, 0x3FFF, 0x3FFE, 0x0000}, // A
        {0x0000, 0x2002, 0x3003, 0x3003, 0x3FFF, 0x3FFF, 0x30C3, 0x30C3, 0x3FFF, 0x3FFF, 0x3FFE, 0x0000}, // B
        {0x0000, 0x1FFE, 0x3FFF, 0x3FFF, 0x3807, 0x3807, 0x3807, 0x3807, 0x3807, 0x3003, 0x0000, 0x0000}, // C
        {0x0000, 0x1806, 0x3807, 0x3807, 0x3FFF, 0x3FFF, 0x3807, 0x3807, 0x3FFF, 0x3FFF, 0x3FFF, 0x0000}, // D
        {0x0000, 0x1FFE, 0x3FFF, 0x3FFF, 0x38C7, 0x38C7, 0x38C7, 0x38C7, 0x3807, 0x3003, 0x0000, 0x0000}, // E
        {0x0000, 0x1FFE, 0x3FFF, 0x3FFF, 0x01C7, 0x00C7, 0x00C7, 0x00C7, 0x0047, 0x0003, 0x0000, 0x0000}, // F
        {0x0000, 0x1FFE, 0x3FFF, 0x3FFF, 0x3807, 0x3807, 0x3987, 0x3987, 0x3987, 0x3F87, 0x1F03, 0x0000}, // G
        {0x0000, 0x1FFE, 0x3FFF, 0x3FFF, 0x00E0, 0x00E0, 0x00E0, 0x00E0, 0x3FFF, 0x3FFF, 0x1FFE, 0x0000}, // H
        {0x0000, 0x1806, 0x3807, 0x3807, 0x3807, 0x3FFF, 0x3FFF, 0x3807, 0x3807, 0x3807, 0x1806, 0x0000}, // I
        {0x0000, 0x1FC0, 0x3FC0, 0x3C00, 0x3800, 0x3800, 0x3800, 0x3800, 0x3FFF, 0x3FFF, 0x1FFE, 0x0000}, // J
        {0x0000, 0x1FFE, 0x3FFF, 0x3FFF, 0x01C0, 0x01C0, 0x01E0, 0x0330, 0x0618, 0x0C0C, 0x1806, 0x0000}, // K
        {0x0000, 0x1FFE, 0x3FFF, 0x3FFF, 0x3C00, 0x3800, 0x3800, 0x3800, 0x3800, 0x3800, 0x3800, 0x3000}, // L
        {0x0000, 0x1FFE, 0x3FFF, 0x1FFF, 0x000E, 0x0078, 0x0078, 0x000E, 0x1FFF, 0x3FFF, 0x1FFE, 0x0000}, // M
        {0x0000, 0x1FFE, 0x3FFF, 0x1FFF, 0x003E, 0x00F0, 0x03C0, 0x0780, 0x1FFF, 0x3FFF, 0x1FFE, 0x0000}, // N
        {0x0000, 0x1FFE, 0x3FFF, 0x3FFF, 0x3C0F, 0x3807, 0x3807, 0x3C0F, 0x3FFF, 0x3FFF, 0x1FFE, 0x0000}, // O
        {0x0000, 0x1FFE, 0x3FFF, 0x3FFF, 0x01C7, 0x00C7, 0x00C7, 0x00C7, 0x00FF, 0x00FF, 0x00FE, 0x0000}, // P
        {0x0000, 0x1FFE, 0x3FFF, 0x3FFF, 0x3C0F, 0x3987, 0x3B07, 0x3E0F, 0x3FFF, 0x3FFF, 0x1FFE, 0x0000}, // Q
        {0x0000, 0x1FFE, 0x3FFF, 0x3FFF, 0x03C7, 0x06C7, 0x0CC7, 0x18C7, 0x30FF, 0x007E, 0x0000, 0x0000}, // R
        {0x0000, 0x187E, 0x38FF, 0x38FF, 0x38C7, 0x38C7, 0x38C7, 0x3FC7, 0x3FC7, 0x1FC6, 0x0000, 0x0000}, // S
        {0x0000, 0x0003, 0x0007, 0x0007, 0x0007, 0x1FFF, 0x1FFF, 0x0007, 0x0007, 0x0007, 0x0003, 0x0000}, // T
        {0x0000, 0x1FFE, 0x3FFF, 0x3FFF, 0x3C00, 0x3800, 0x3800, 0x3C00, 0x3FFF, 0x3FFF, 0x1FFE, 0x0000}, // U
        {0x0000, 0x000F, 0x003F, 0x01FC, 0x03C0, 0x1E00, 0x1E00, 0x0FC0, 0x01FC, 0x003F, 0x000F, 0x0000}, // V
        {0x0000, 0x1FFE, 0x3FFF, 0x3FFF, 0x1E00, 0x07C0, 0x07C0, 0x1E00, 0x3FFF, 0x3FFF, 0x1FFE, 0x0000}, // W
        {0x0000, 0x0E07, 0x070E, 0x039C, 0x01F8, 0x01F0, 0x01F0, 0x01DC, 0x038E, 0x0707, 0x0E03, 0x0000}, // X
        {0x0000, 0x007E, 0x20FF, 0x30FF, 0x30E0, 0x30C0, 0x30C0, 0x30E0, 0x3FFE, 0x3FFF, 0x1FFE, 0x0000}, // Y
        {0x0000, 0x1C06, 0x3E07, 0x3F07, 0x3B87, 0x39C7, 0x38E7, 0x3877, 0x383F, 0x381F, 0x180E, 0x0000}  // Z
};