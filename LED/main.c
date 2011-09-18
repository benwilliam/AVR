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
