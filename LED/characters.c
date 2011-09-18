/*
 * characters.c
 *
 *  Created on: 08.09.2011
 *      Author: rdo
 */

#include <avr/pgmspace.h>

unsigned char  chars [144][5] PROGMEM = {
  {0x00, 0x00, 0x00, 0x00, 0x00}, {0x0e, 0x11, 0x2e, 0x10, 0xf8}, //NULL und SOH
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // STX und ETX
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // EOT und ENQ
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // ACK und BEL
  // Zeichen 8 bis 15
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // BS und HT
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // LF und VT
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // FF und CR
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // SO und SI
  // Zeichen 16 bis 23
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // DLE und DC1
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // DC2 und DC3
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // DC4 und NAK
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // SYN und ETB
  // Zeichen 24 bis 31
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // CAN und EM
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // SUB und ESC
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // FS und GS
  {0xff, 0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff, 0xff}, // RS und US
  // Zeichen 32 bis 39
  {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x5f, 0x00, 0x00}, // SPACE und !
  {0x00, 0x07, 0x00, 0x07, 0x00}, {0x14, 0x7f, 0x14, 0x7f, 0x14}, // " und #
  {0x24, 0x2a, 0x7f, 0x2a, 0x12}, {0x23, 0x13, 0x08, 0x64, 0x62}, // $ und %
  {0x36, 0x49, 0x55, 0x22, 0x50}, {0x00, 0x05, 0x03, 0x00, 0x00}, // & und '
  // Zeichen 40 bis 47
  {0x00, 0x1c, 0x22, 0x41, 0x00}, {0x00, 0x41, 0x22, 0x1c, 0x00}, // ( und )
  {0x14, 0x08, 0x3e, 0x08, 0x14}, {0x08, 0x08, 0x3e, 0x08, 0x08}, // * und +
  {0x00, 0x50, 0x30, 0x00, 0x00}, {0x10, 0x10, 0x10, 0x10, 0x10}, // , und -
  {0x00, 0x60, 0x60, 0x00, 0x00}, {0x20, 0x20, 0x08, 0x04, 0x02}, // . und /
  // Zeichen 48 bis 55
  {0x3e, 0x51, 0x49, 0x45, 0x3e}, {0x00, 0x42, 0x7f, 0x40, 0x00}, // 0 und 1
  {0x42, 0x61, 0x51, 0x49, 0x46}, {0x21, 0x41, 0x45, 0x4b, 0x31}, // 2 und 3
  {0x18, 0x14, 0x12, 0x7f, 0x10}, {0x27, 0x45, 0x45, 0x45, 0x39}, // 4 und 5
  {0x3c, 0x4a, 0x49, 0x49, 0x30}, {0x01, 0x01, 0x79, 0x05, 0x03}, // 6 und 7
  // Zeichen 56 bis 63
  {0x36, 0x49, 0x49, 0x49, 0x36}, {0x06, 0x49, 0x49, 0x29, 0x1e}, // 8 und 9
  {0x00, 0x36, 0x36, 0x00, 0x00}, {0x00, 0x56, 0x36, 0x00, 0x00}, // : und ,
  {0x08, 0x14, 0x22, 0x41, 0x00}, {0x14, 0x14, 0x14, 0x14, 0x14}, // < und =
  {0x41, 0x22, 0x14, 0x08, 0x00}, {0x02, 0x01, 0x51, 0x09, 0x06}, // > und ?
  // Zeichen 64 bis 71
  {0x32, 0x49, 0x79, 0x41, 0x3e}, {0x7e, 0x09, 0x09, 0x09, 0x7e}, // @ und A
  {0x7f, 0x49, 0x49, 0x49, 0x36}, {0x3e, 0x41, 0x41, 0x41, 0x22}, // B und C
  {0x7f, 0x41, 0x41, 0x22, 0x1c}, {0x7f, 0x49, 0x49, 0x49, 0x41}, // D und E
  {0x7f, 0x09, 0x09, 0x09, 0x01}, {0x3e, 0x41, 0x49, 0x49, 0x7a}, // F und G
  // Zeichen 72 bis 79
  {0x7f, 0x08, 0x08, 0x08, 0x7f}, {0x00, 0x41, 0x7f, 0x41, 0x00}, // H und I
  {0x20, 0x41, 0x41, 0x3f, 0x01}, {0x7f, 0x08, 0x14, 0x22, 0x41}, // J und K
  {0x7f, 0x40, 0x40, 0x40, 0x40}, {0x7f, 0x02, 0x0c, 0x02, 0x7f}, // L und M
  {0x7f, 0x04, 0x08, 0x10, 0x7f}, {0x3e, 0x41, 0x41, 0x41, 0x3e}, // N und O
  // Zeichen 80 bis 87
  {0x7f, 0x09, 0x09, 0x09, 0x06}, {0x3e, 0x41, 0x51, 0x21, 0x5e}, // P und Q
  {0x7f, 0x09, 0x19, 0x29, 0x46}, {0x46, 0x49, 0x49, 0x49, 0x31}, // R und S
  {0x01, 0x01, 0x7f, 0x01, 0x01}, {0x3f, 0x40, 0x40, 0x40, 0x3f}, // T und U
  {0x1f, 0x20, 0x40, 0x20, 0x1f}, {0x3f, 0x40, 0x38, 0x40, 0x3f}, // V und W
  // Zeichen 88 bis 95
  {0x63, 0x14, 0x08, 0x14, 0x63}, {0x07, 0x08, 0x70, 0x08, 0x07}, // X und Y
  {0x61, 0x51, 0x49, 0x45, 0x43}, {0x00, 0x7f, 0x41, 0x41, 0x00}, // Z und [
  {0x02, 0x04, 0x08, 0x10, 0x20}, {0x00, 0x41, 0x41, 0x7f, 0x00}, // \ und ]
  {0x04, 0x02, 0x01, 0x02, 0x04}, {0x80, 0x80, 0x80, 0x80, 0x80}, // ^ und _
  // Zeichen 96 bis 103
  {0x00, 0x01, 0x02, 0x04, 0x00}, {0x20, 0x54, 0x54, 0x54, 0x78}, // ` und a
  {0x7f, 0x48, 0x44, 0x44, 0x38}, {0x38, 0x44, 0x44, 0x44, 0x20}, // b und c
  {0x38, 0x44, 0x44, 0x48, 0x7f}, {0x38, 0x54, 0x54, 0x54, 0x18}, // d und e
  {0x08, 0xfe, 0x09, 0x09, 0x02}, {0x18, 0xa4, 0xa4, 0xa4, 0x7c}, // f und g
  // Zeichen 104 bis 111
  {0x7f, 0x08, 0x04, 0x04, 0x78}, {0x00, 0x44, 0x7d, 0x40, 0x00}, // h und i
  {0x40, 0x80, 0x84, 0x7d, 0x00}, {0x7f, 0x10, 0x28, 0x44, 0x00}, // j und k
  {0x00, 0x41, 0x7f, 0x40, 0x00}, {0x7c, 0x04, 0x18, 0x04, 0x78}, // l und m
  {0x7c, 0x08, 0x04, 0x04, 0x78}, {0x38, 0x44, 0x44, 0x44, 0x38}, // n und o
  // Zeichen 112 bis 119
  {0xfc, 0x24, 0x24, 0x24, 0x18}, {0x18, 0x24, 0x24, 0x28, 0xfc}, // p und q
  {0x7c, 0x08, 0x04, 0x04, 0x08}, {0x48, 0x54, 0x54, 0x54, 0x20}, // r und s
  {0x04, 0x3f, 0x44, 0x40, 0x20}, {0x3c, 0x40, 0x40, 0x20, 0x7c}, // t und u
  {0x1c, 0x20, 0x40, 0x20, 0x1c}, {0x3c, 0x40, 0x30, 0x40, 0x3c}, // v und w
  // Zeichen 120 bis 127
  {0x44, 0x28, 0x10, 0x28, 0x44}, {0x1c, 0xa0, 0xa0, 0xa0, 0x7c}, // x und y
  {0x44, 0x64, 0x54, 0x4c, 0x44}, {0x00, 0x08, 0x36, 0x41, 0x00}, // z und {
  {0x00, 0x00, 0x7f, 0x00, 0x00}, {0x00, 0x41, 0x36, 0x08, 0x00}, // | und ,
  {0x02, 0x01, 0x02, 0x04, 0x02}, {0x1f, 0x05, 0xf9, 0x28, 0x08}, // ~ und DEL
  // Zeichen 128 bis 135
  {0x14, 0x3E, 0x55, 0x55, 0x55}, {0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, // euro und ka
  {0x50, 0x30, 0x00, 0x00, 0x00}, {0x40, 0x44, 0x3E, 0x05, 0x01}, // , und funktion
  {0x00, 0x60, 0x00, 0x60, 0x00}, {0x00, 0x00, 0x40, 0x00, 0x40}, // " unten und ...
  {0x00, 0x02, 0x7F, 0x02, 0x00}, {0x00, 0x22, 0x7F, 0x22, 0x00}, // Kreuz und doppelkreuz
  // Zeichen 136 bis 143
  {0x02, 0x01, 0x02, 0x00, 0x00}, {0x13, 0x6B, 0x64, 0x1A, 0x19}, // Zirkumflex und Promille
  {0x00, 0x4D, 0x56, 0x65, 0x00}, {0x20, 0x50, 0x00, 0x00, 0x00}, // S mit Krone und kleines <
  {0x3E, 0x7F, 0x3E, 0x49, 0x49}, {0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, // OE unten und ka
  {0x44, 0x65, 0x56, 0x4D, 0x44}, {0x1E, 0x21, 0x46, 0x21, 0x1E} // Z mit Krone und Herz
};