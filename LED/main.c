#include <stdio.h>
#include "main.h"
#include "LEDMatrix.h"
#include "canvas.h"
#include "SPI.h"
#include "PCDebug.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

typedef struct
{
    unsigned char hour;
    unsigned char min;
    unsigned char sec;
    unsigned char hsec;
} time;

time TIME;

void incrementTime()
{
   TIME.hsec +=1;
   if(TIME.hsec >= 100)
   {
       TIME.hsec = 0;
       TIME.sec +=1;
       if(TIME.sec >= 60)
       {
           TIME.sec = 0;
           TIME.min +=1;
           if(TIME.min >= 60)
           {
               TIME.min = 0;
               TIME.hour +=1;
               if(TIME.hour >= 24)
               {
                   TIME.hour = 0;
               }
           }
       }
   }

}
void printNumber(unsigned char x, unsigned char value)
{
    if(value < 10)
    {
        printChar(x, 0, '0');
        printChar(x+6, 0, value+48);
    }
    else
    {
        printChar(x, 0, (value/10)+48);
        printChar(x+6, 0, (value%10)+48);
    }
}
void printClock()
{
    printNumber(0, TIME.hour);
    printChar(12, 0, ':');
    printNumber(18, TIME.min);
    printChar(30, 0, ':');
    printNumber(36, TIME.sec);
    printChar(48, 0, '.');
    printNumber(54, TIME.hour);

}

ISR(TIMER1_COMPA_vect)
{
	cli();
    incrementTime(&TIME);
	sei();
}

int main (void)
{

    //set prescaler 256 Timer1
	// TCCR1A |= (0 << WGM11) | (1 << WGM10);
    TCCR1B |= (1<<WGM12) | (1<<CS11) | (1<<CS10);
    //set compare 8MHz/256
    OCR1A = 1250;

	//enable interrupt
	TIMSK |= (1<<OCIE1A);


    init();


	//main programm
	while(1)
	{

		clearWorkingBuffer();
        printClock();
        switchBuffer();
        incrementTime();

	}
	return 0;
}
