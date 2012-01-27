/*
 * LEDMatrix.c
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

#include "LEDMatrix.h"
#include <avr/interrupt.h>


unsigned char outPutBufferArray[BUFFER_WIDTH][HEIGHT];
unsigned char workingBufferArray[BUFFER_WIDTH][HEIGHT];

unsigned char (*outPutBuffer)[HEIGHT] = outPutBufferArray; //pointer auf puffer der an die LED matrix zeilenweise �bertragen wird
unsigned char (*workingBuffer)[HEIGHT] = workingBufferArray; //pointer auf den gezeichnet wird

//gibt den wert eines bestimtmen bits eines bytes wieder
//(kann evtl. noch optimiert werden)
unsigned char getBitOfByte(unsigned char byte, unsigned char bit)
{
	byte = byte >> (7-(bit%8));
	byte = byte&0x01;
	return byte;
}

//setzt den wert eines bestimtmen bits in einem byte
unsigned char setBitOfByte(unsigned char byte, unsigned char bit, unsigned char value)
{

	unsigned ret;
	if(value)
	{
		ret = byte | (1 << (7-(bit%8)));
	}
	else
	{
		ret = byte & ~(1 << (7-(bit%8)));
	}
	return ret;
}

void switchBuffer()
{
	cli();
	unsigned char (*temp)[HEIGHT] = outPutBuffer;
	outPutBuffer = workingBuffer;
	workingBuffer = temp;
	sei();
}



unsigned char getWorkingBufferBit(unsigned char x, unsigned char y)
{
	if(x<WIDTH && y < HEIGHT)
	{
		return getBitOfByte(workingBuffer[getBytePos(x)][y], x);
	}
	return LED_OFF;
}

unsigned char setWorkingBufferBit(unsigned char x, unsigned char y, unsigned char value)
{
	if(x<WIDTH && y < HEIGHT)
	{
		workingBuffer[getBytePos(x)][y] = setBitOfByte(workingBuffer[getBytePos(x)][y], x, value);
		return workingBuffer[getBytePos(x)][y];
	}
	return LED_OFF;
}

void clearWorkingBuffer()
{
	unsigned char x, y;

		for(y = 0; y<(HEIGHT); y++)
		{
			for(x = 0; x<(BUFFER_WIDTH); x++)
			{
				workingBuffer[x][y] = LED_OFF;
			}
		}
}
