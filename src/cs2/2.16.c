                                            logical             arithmetic
    a                   a << 2              a >> 3              a >> 3
hex     binary      binary      hex     binary      hex     binary      hex
0xD4    1101 0100   0101 0000   0x50    0001 1010   0x1A    1111 1010   0xFA
0x64    0110 0100   1001 0000   0x90    0000 1100   0xC     0000 1100   0xC
0x72    0111 0010   1100 1000   0xC8    0000 1110   0xE     0000 1110   0xE
0x44    0100 0100   0001 0000   0x10    0000 1000   0x8     0000 1000   0x8

solution                        0x50                0x1A    1111 1010   0xFA
                                0x90                0x0C    1110 1100   0xEC ??
                                0xC8                0x0E    0000 1110   0x0E
                                0x10                0x08    1110 1000   0xE9 ??
