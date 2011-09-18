/*
 * LEDMatrix.c
 *
 *  Created on: 07.09.2011
 *      Author: rdo
 */

#include "LEDMatrix.h"
#include <avr/interrupt.h>

unsigned char outPutBufferArray[BUFFER_WIDTH][HEIGHT];
unsigned char workingBufferArray[BUFFER_WIDTH][HEIGHT];

unsigned char (*outPutBuffer)[HEIGHT] = outPutBufferArray;
unsigned char (*workingBuffer)[HEIGHT] = workingBufferArray;

unsigned char getBitOfByte(unsigned char byte, unsigned char bit)
{
	byte = byte >> (7-(bit%8));
	byte = byte&0x01;
	return byte;
}

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
