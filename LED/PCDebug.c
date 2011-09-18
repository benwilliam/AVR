/*
 * PCDebug.c
 *
 *  Created on: 07.09.2011
 *      Author: rdo
 */

#include "LEDMatrix.h"
#include "PCDebug.h"

//for debugging only
void printWorkingBuffer()
{
	unsigned char x, y;
	printf("--------------------------------------------------------------------------------\n");
	for(y = 0; y<(HEIGHT); y++)
	{
		for(x = 0; x<(WIDTH); x++)
		{
			printf("%d", getWorkingBufferBit(x,y));
		}
		printf("\n");
	}
	printf("--------------------------------------------------------------------------------\n");
}

