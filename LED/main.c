/*
 * main.c
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

#include <stdio.h>
#include "main.h"
#include "LEDMatrix.h"
#include "canvas.h"
#include "SPI.h"
#include "PCDebug.h"

#include <avr/io.h>
#include <util/delay.h>

int main (void)
{



	switchBuffer();
    init();

    unsigned int i;

	//main programm
	while(1)
	{


        for(i=0; i<360; i+=15)
        {
            _delay_ms(10);
            clearWorkingBuffer();
            rectangleRotate(30,0,36,6,i);
            switchBuffer();
        }


	}
	return 0;
}
