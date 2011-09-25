/*
 * LEDMatrix.h
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Created on: 07.09.2011
 *      Author: Roland Domke
 *   Copyright: 2011 Roland Domke
 */

#ifndef LEDMATRIX_H_
#define LEDMATRIX_H_

#include "main.h"
/*
 * User defines for LED matrix size
 */
//----------------------------------
#define WIDTH 80		//width of the LED matrix / amount of coloumns
#define HEIGHT 7		//height of the LED matrix / amout of rows
#define LED_ON 0x00		// the logical singal for LED on
#define LED_OFF 0xFF	// the logical singal for LED off
#define FRAMERATE 100 	//Frames per second
//----------------------------------


#define CLOCK_COUNTS 300 //grobe abschätzung der bneötigten ticks zur ausgabe einer zeile (erfahrungs wert) (bei voller optimierung)
#define LINERATE FRAMERATE*HEIGHT
#define COUNTER (F_CPU/(LINERATE*CLOCK_COUNTS))
#if (COUNTER == 0)
	#error Framerate ist definitiv zu hoch!! (oder CPU zu langsam :-p)
#endif

#if (COUNTER > 0xff)
    #error Framerate ist zu langsam (WTF?)!! (oder CPU zu schnell :-p)
#endif


/*
 * internal Buffer defines
 */
//--------------------------------------------------------------
#define BUFFER_WIDTH (WIDTH % 8 == 0) ? WIDTH/8 : (WIDTH/8) + 1
#define getBytePos(Y) Y/8

extern unsigned char outPutBufferArray[BUFFER_WIDTH][HEIGHT];
extern unsigned char workingBufferArray[BUFFER_WIDTH][HEIGHT];

extern unsigned char (*outPutBuffer)[HEIGHT];
extern unsigned char (*workingBuffer)[HEIGHT];
//--------------------------------------------------------------

//methods
unsigned char getBitOfByte(unsigned char byte, unsigned char bit);
unsigned char setBitOfByte(unsigned char byte, unsigned char bit, unsigned char value);
void switchBuffer();
unsigned char getWorkingBufferBit(unsigned char x, unsigned char y);
unsigned char setWorkingBufferBit(unsigned char x, unsigned char y, unsigned char value);
void clearWorkingBuffer();


#endif /* LEDMATRIX_H_ */
