// AraMedDigits.c
// Font type    : Numeric (10 characters)
// Font size    : 24x29 pixels
// Memory usage : 874 bytes

#if defined(__AVR__)
    #include <avr/pgmspace.h>
    #define fontdatatype const uint8_t
#elif defined(__PIC32MX__)
    #define PROGMEM
    #define fontdatatype const unsigned char
#elif defined(__arm__)
    #define PROGMEM
    #define fontdatatype const unsigned char
#endif

fontdatatype AraMedDigits[874] PROGMEM={
0x18,0x1D,0x30,0x0A,
0x00,0x00,0x00,0x01,0xFF,0x00,0x03,0xFF,0xC0,0x07,0xFF,0xE0,0x0F,0xC7,0xE0,0x0F,0x81,0xF0,0x1F,0x01,0xF0,0x1F,0x00,0xF0,0x1E,0x00,0xF0,0x1E,0x00,0xF8,0x1E,0x00,0xF8,0x1E,0x00,0xF8,0x1E,0x00,0xF8,0x1E,0x00,0xF8,0x1E,0x00,0xF8,0x1E,0x00,0xF8,0x1E,0x00,0xF8,0x1E,0x00,0xF8,0x1E,0x00,0xF8,0x1E,0x00,0xF0,0x1E,0x00,0xF0,0x1F,0x00,0xF0,0x1F,0x01,0xF0,0x0F,0x81,0xF0,0x0F,0xC7,0xE0,0x07,0xFF,0xC0,0x03,0xFF,0xC0,0x01,0xFF,0x00,0x00,0x00,0x00,  // 0
0x00,0x00,0x00,0x00,0x0E,0x00,0x00,0x7E,0x00,0x01,0xFE,0x00,0x0F,0xFE,0x00,0x0F,0xFE,0x00,0x0F,0x9E,0x00,0x0E,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x00,0x00,  // 1
0x00,0x00,0x00,0x03,0xFE,0x00,0x0F,0xFF,0x80,0x1F,0xFF,0xC0,0x3F,0x8F,0xC0,0x3E,0x07,0xE0,0x3C,0x03,0xE0,0x7C,0x01,0xE0,0x7C,0x01,0xE0,0x7C,0x01,0xE0,0x00,0x03,0xE0,0x00,0x03,0xC0,0x00,0x07,0xC0,0x00,0x0F,0x80,0x00,0x0F,0x80,0x00,0x1F,0x00,0x00,0x3E,0x00,0x00,0x7C,0x00,0x00,0xF8,0x00,0x01,0xF0,0x00,0x03,0xE0,0x00,0x07,0xC0,0x00,0x0F,0x80,0x00,0x1F,0x00,0x00,0x3F,0x00,0x00,0x3F,0xFF,0xF0,0x3F,0xFF,0xF0,0x3F,0xFF,0xF0,0x00,0x00,0x00,  // 2
0x00,0x00,0x00,0x01,0xFF,0x00,0x07,0xFF,0x80,0x0F,0xFF,0xC0,0x0F,0xC7,0xE0,0x1F,0x01,0xE0,0x1E,0x01,0xF0,0x1E,0x01,0xF0,0x1E,0x00,0xF0,0x00,0x01,0xF0,0x00,0x01,0xF0,0x00,0x03,0xE0,0x00,0x0F,0xE0,0x00,0xFF,0xC0,0x00,0xFF,0x80,0x00,0xFF,0xC0,0x00,0x07,0xE0,0x00,0x01,0xF0,0x00,0x01,0xF0,0x00,0x00,0xF0,0x3E,0x00,0xF0,0x3E,0x00,0xF0,0x3E,0x00,0xF0,0x1F,0x01,0xF0,0x1F,0xC7,0xE0,0x0F,0xFF,0xE0,0x07,0xFF,0xC0,0x01,0xFF,0x00,0x00,0x00,0x00,  // 3
0x00,0x00,0x00,0x00,0x07,0xC0,0x00,0x07,0xC0,0x00,0x0F,0xC0,0x00,0x1F,0xC0,0x00,0x1F,0xC0,0x00,0x3F,0xC0,0x00,0x7F,0xC0,0x00,0x7B,0xC0,0x00,0xFB,0xC0,0x01,0xF3,0xC0,0x01,0xE3,0xC0,0x03,0xE3,0xC0,0x07,0xC3,0xC0,0x07,0x83,0xC0,0x0F,0x83,0xC0,0x0F,0x03,0xC0,0x1E,0x03,0xC0,0x3E,0x03,0xC0,0x3F,0xFF,0xFC,0x3F,0xFF,0xFC,0x3F,0xFF,0xFC,0x00,0x03,0xC0,0x00,0x03,0xC0,0x00,0x03,0xC0,0x00,0x03,0xC0,0x00,0x03,0xC0,0x00,0x03,0xC0,0x00,0x00,0x00,  // 4
0x00,0x00,0x00,0x0F,0xFF,0xC0,0x0F,0xFF,0xC0,0x1F,0xFF,0xC0,0x1F,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x1F,0xFE,0x00,0x1F,0xFF,0x00,0x1F,0xFF,0x80,0x3F,0x1F,0xC0,0x1E,0x07,0xE0,0x00,0x03,0xE0,0x00,0x01,0xE0,0x00,0x01,0xE0,0x00,0x01,0xE0,0x00,0x01,0xE0,0x7C,0x01,0xE0,0x3C,0x01,0xE0,0x3C,0x03,0xE0,0x3E,0x07,0xE0,0x1F,0x8F,0xC0,0x1F,0xFF,0x80,0x0F,0xFF,0x00,0x03,0xFE,0x00,0x00,0x00,0x00,  // 5
0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0xFF,0x00,0x03,0xFF,0x00,0x07,0xF8,0x00,0x07,0xC0,0x00,0x0F,0x80,0x00,0x0F,0x00,0x00,0x1F,0x00,0x00,0x1E,0x00,0x00,0x1E,0xFF,0x00,0x3F,0xFF,0x80,0x3F,0xFF,0xC0,0x3F,0xCF,0xE0,0x3F,0x03,0xE0,0x3E,0x01,0xF0,0x3C,0x01,0xF0,0x3C,0x00,0xF0,0x3C,0x00,0xF0,0x3C,0x00,0xF0,0x3E,0x00,0xF0,0x3E,0x01,0xF0,0x1F,0x01,0xE0,0x1F,0x03,0xE0,0x0F,0xCF,0xE0,0x07,0xFF,0xC0,0x03,0xFF,0x80,0x01,0xFE,0x00,0x00,0x00,0x00,  // 6
0x00,0x00,0x00,0x3F,0xFF,0xF8,0x3F,0xFF,0xF8,0x3F,0xFF,0xF8,0x00,0x00,0xF8,0x00,0x00,0xF0,0x00,0x01,0xF0,0x00,0x01,0xE0,0x00,0x03,0xE0,0x00,0x03,0xC0,0x00,0x07,0xC0,0x00,0x07,0x80,0x00,0x07,0x80,0x00,0x0F,0x80,0x00,0x0F,0x00,0x00,0x1F,0x00,0x00,0x1E,0x00,0x00,0x3E,0x00,0x00,0x3C,0x00,0x00,0x7C,0x00,0x00,0x78,0x00,0x00,0xF8,0x00,0x00,0xF8,0x00,0x01,0xF0,0x00,0x01,0xF0,0x00,0x01,0xE0,0x00,0x03,0xE0,0x00,0x07,0xC0,0x00,0x00,0x00,0x00,  // 7
0x00,0x00,0x00,0x01,0xFF,0x00,0x03,0xFF,0xC0,0x07,0xFF,0xE0,0x0F,0xC7,0xE0,0x0F,0x83,0xF0,0x1F,0x01,0xF0,0x1F,0x00,0xF0,0x1F,0x00,0xF0,0x1F,0x00,0xF0,0x0F,0x01,0xF0,0x0F,0x81,0xE0,0x0F,0xC7,0xE0,0x07,0xFF,0xC0,0x01,0xFF,0x80,0x07,0xFF,0xC0,0x0F,0xC7,0xE0,0x1F,0x01,0xF0,0x1F,0x00,0xF0,0x1E,0x00,0xF8,0x1E,0x00,0xF8,0x1E,0x00,0xF8,0x1E,0x00,0xF8,0x1F,0x01,0xF0,0x1F,0xC7,0xF0,0x0F,0xFF,0xE0,0x07,0xFF,0xC0,0x01,0xFF,0x00,0x00,0x00,0x00,  // 8
0x00,0x00,0x00,0x01,0xFE,0x00,0x07,0xFF,0x80,0x0F,0xFF,0xC0,0x0F,0xCF,0xE0,0x1F,0x03,0xE0,0x1F,0x01,0xE0,0x1E,0x01,0xF0,0x3E,0x00,0xF0,0x3E,0x00,0xF0,0x3E,0x00,0xF0,0x3E,0x00,0xF0,0x1E,0x00,0xF0,0x1F,0x01,0xF0,0x1F,0x03,0xF0,0x0F,0xCF,0xF0,0x0F,0xFF,0xF0,0x07,0xFF,0xF0,0x01,0xFC,0xF0,0x00,0x01,0xF0,0x00,0x01,0xE0,0x00,0x03,0xE0,0x00,0x03,0xE0,0x00,0x0F,0xC0,0x00,0x7F,0x80,0x03,0xFF,0x00,0x03,0xFE,0x00,0x03,0xF8,0x00,0x00,0x00,0x00,  // 9
};