/*
 * canvas.c
 *
 *  Created on: 07.09.2011
 *      Author: rdo
 */
#include "LEDMatrix.h"
#include "fastMath.h"
#include "characters.h"
#include <avr/pgmspace.h>
#include <string.h>

//void line(unsigned char xstart,unsigned char ystart,unsigned char xend,unsigned char yend)
//{
//	char x, y, t, dx, dy, incx, incy, pdx, pdy, ddx, ddy, es, el, err;
//
///* Entfernung in beiden Dimensionen berechnen */
//   dx = xend - xstart;
//   dy = yend - ystart;
//
///* Vorzeichen des Inkrements bestimmen */
//   incx = sgn(dx);
//   incy = sgn(dy);
//   if(dx<0) dx = -dx;
//   if(dy<0) dy = -dy;
//
///* feststellen, welche Entfernung größer ist */
//   if (dx>dy)
//   {
//      /* x ist schnelle Richtung */
//      pdx=incx; pdy=0;    /* pd. ist Parallelschritt */
//      ddx=incx; ddy=incy; /* dd. ist Diagonalschritt */
//      es =dy;   el =dx;   /* Fehlerschritte schnell, langsam */
//   } else
//   {
//      /* y ist schnelle Richtung */
//      pdx=0;    pdy=incy; /* pd. ist Parallelschritt */
//      ddx=incx; ddy=incy; /* dd. ist Diagonalschritt */
//      es =dx;   el =dy;   /* Fehlerschritte schnell, langsam */
//   }
//
///* Initialisierungen vor Schleifenbeginn */
//   x = xstart;
//   y = ystart;
//   err = el/2;
//   setWorkingBufferBit(x,y, LED_ON);
//
///* Pixel berechnen */
//   for(t=0; t<el; ++t) /* t zaehlt die Pixel, el ist auch Anzahl */
//   {
//      /* Aktualisierung Fehlerterm */
//      err -= es;
//      if(err<0)
//      {
//          /* Fehlerterm wieder positiv (>=0) machen */
//          err += el;
//          /* Schritt in langsame Richtung, Diagonalschritt */
//          x += ddx;
//          y += ddy;
//      } else
//      {
//          /* Schritt in schnelle Richtung, Parallelschritt */
//          x += pdx;
//          y += pdy;
//      }
//      setWorkingBufferBit(x,y, LED_ON);
//   }
//}
//
//void rectangle(unsigned char xstart,unsigned char ystart,unsigned char xend,unsigned char yend)
//{
//	line(xstart, ystart, xstart, yend);
//	line(xstart, ystart, xend, ystart);
//	line(xend, yend, xstart, yend);
//	line(xend, yend, xend, ystart);
//}
//
//void rectangleFilled(unsigned char xstart,unsigned char ystart,unsigned char xend,unsigned char yend)
//{
//	unsigned char i;
//	for(i = 0; i<=(min((xend-xstart), (yend-ystart))/2); i++)
//	{
//		rectangle(xstart+i, ystart+i, xend-i, yend-i);
//	}
//}
//
//void circle(int x0, int y0, int radius)
//  {
//    int f = 1 - radius;
//    int ddF_x = 0;
//    int ddF_y = -2 * radius;
//    int x = 0;
//    int y = radius;
//
//    setWorkingBufferBit(x0, y0 + radius, LED_ON);
//    setWorkingBufferBit(x0, y0 - radius, LED_ON);
//    setWorkingBufferBit(x0 + radius, y0, LED_ON);
//    setWorkingBufferBit(x0 - radius, y0, LED_ON);
//
//    while(x < y)
//    {
//      if(f >= 0)
//      {
//        y--;
//        ddF_y += 2;
//        f += ddF_y;
//      }
//      x++;
//      ddF_x += 2;
//      f += ddF_x + 1;
//
//      setWorkingBufferBit(x0 + x, y0 + y, LED_ON);
//      setWorkingBufferBit(x0 - x, y0 + y, LED_ON);
//      setWorkingBufferBit(x0 + x, y0 - y, LED_ON);
//      setWorkingBufferBit(x0 - x, y0 - y, LED_ON);
//      setWorkingBufferBit(x0 + y, y0 + x, LED_ON);
//      setWorkingBufferBit(x0 - y, y0 + x, LED_ON);
//      setWorkingBufferBit(x0 + y, y0 - x, LED_ON);
//      setWorkingBufferBit(x0 - y, y0 - x, LED_ON);
//    }
// }
//
//void circlefilled(int x0, int y0, int radius)
//  {
//    int f = 1 - radius;
//    int ddF_x = 0;
//    int ddF_y = -2 * radius;
//    int x = 0;
//    int y = radius;
//
//    line(x0, y0 + radius, x0, y0 - radius);
//    line(x0 + radius, y0,x0 - radius, y0);
//
//    while(x < y)
//    {
//      if(f >= 0)
//      {
//        y--;
//        ddF_y += 2;
//        f += ddF_y;
//      }
//      x++;
//      ddF_x += 2;
//      f += ddF_x + 1;
//
//      line(x0 + x, y0 + y, x0 - x, y0 + y);
//      line(x0 + x, y0 - y, x0 - x, y0 - y);
//      line(x0 + y, y0 + x, x0 - y, y0 + x);
//      line(x0 + y, y0 - x, x0 - y, y0 - x);
//    }
// }
//
//void shiftLeft(unsigned char count)
//{
//
//	if(count < WIDTH)
//	{
//		unsigned char x, y;
//		for(x=0; x<(WIDTH - count); x++)
//		{
//			for(y=0; y<HEIGHT; y++)
//			{
//				setWorkingBufferBit(x, y, getWorkingBufferBit(x+count, y));
//			}
//		}
//		for(x=(WIDTH-count); x<WIDTH; x++)
//		{
//			for(y=0; y<HEIGHT; y++)
//			{
//				setWorkingBufferBit(x, y, LED_OFF);
//			}
//		}
//
//	}
//	else
//	{
//		clearWorkingBuffer();
//	}
//}
//
//void shiftRight(unsigned char count)
//{
//	if(count < WIDTH)
//	{
//		unsigned char x, y;
//		for(x=WIDTH-1; x>=count; x--)
//		{
//			for(y=0; y<HEIGHT; y++)
//			{
//				setWorkingBufferBit(x, y, getWorkingBufferBit(x-count, y));
//			}
//		}
//		for(x=0; x<count; x++)
//		{
//			for(y=0; y<HEIGHT; y++)
//			{
//				setWorkingBufferBit(x, y, LED_OFF);
//			}
//		}
//
//	}
//	else
//	{
//		clearWorkingBuffer();
//	}
//}
//
//void shiftLeftRound(unsigned char count)
//{
//	if(count < WIDTH)
//	{
//		unsigned char x, y, temp, c;
//		for (c = 0; c < count; c++) {
//			for(y=0; y<HEIGHT; y++)
//			{
//				temp = getWorkingBufferBit(0,y);
//				for(x=0; x<(WIDTH-1); x++)
//				{
//					setWorkingBufferBit(x, y, getWorkingBufferBit(x+1, y));
//				}
//				setWorkingBufferBit(WIDTH-1, y, temp);
//			}
//		}
//
//
//	}
//	else
//	{
//		clearWorkingBuffer();
//	}
//}
//
//void shiftRightRound(unsigned char count)
//{
//	if(count < WIDTH)
//	{
//		unsigned char x, y, temp, c;
//		for (c = 0; c < count; c++) {
//			for(y=0; y<HEIGHT; y++)
//			{
//				temp = getWorkingBufferBit(WIDTH-1,y);
//				for(x=WIDTH-2; x<(WIDTH-1); x--)
//				{
//					setWorkingBufferBit(x+1, y, getWorkingBufferBit(x, y));
//				}
//				setWorkingBufferBit(0, y, temp);
//			}
//		}
//
//
//	}
//	else
//	{
//		clearWorkingBuffer();
//	}
//}
//
//void shiftUp(unsigned char count)
//{
//	if(count < HEIGHT)
//	{
//		unsigned char x, y;
//		for(x=0; x<(WIDTH); x++)
//		{
//			for(y=0; y<HEIGHT-count; y++)
//			{
//				setWorkingBufferBit(x, y, getWorkingBufferBit(x, y+count));
//			}
//		}
//		for(x=0; x<WIDTH; x++)
//		{
//			for(y=HEIGHT-count; y<HEIGHT; y++)
//			{
//				setWorkingBufferBit(x, y, LED_OFF);
//			}
//		}
//
//	}
//	else
//	{
//		clearWorkingBuffer();
//	}
//}
//
//void shiftDown(unsigned char count)
//{
//	if(count < HEIGHT)
//	{
//		unsigned char x, y;
//		for(x=0; x<WIDTH; x++)
//		{
//			for(y=HEIGHT-1; y>=count; y--)
//			{
//				setWorkingBufferBit(x, y, getWorkingBufferBit(x, y-count));
//			}
//		}
//		for(x=0; x<WIDTH; x++)
//		{
//			for(y=0; y<count; y++)
//			{
//				setWorkingBufferBit(x, y, LED_OFF);
//			}
//		}
//
//	}
//	else
//	{
//		clearWorkingBuffer();
//	}
//}
//void shiftUpRound(unsigned char count)
//{
//
//	if(count < HEIGHT)
//	{
//		unsigned char x, y, temp, c;
//		for (c = 0; c < count; c++) {
//			for(x=0; x<(WIDTH); x++)
//			{
//				temp = getWorkingBufferBit(x,0);
//				for(y=0; y<HEIGHT-1; y++)
//				{
//					setWorkingBufferBit(x, y, getWorkingBufferBit(x, y+1));
//				}
//				setWorkingBufferBit(x, HEIGHT-1, temp);
//			}
//		}
//
//
//	}
//	else
//	{
//		clearWorkingBuffer();
//	}
//}
//
//void shiftDownRound(unsigned char count)
//{
//
//	if(count < HEIGHT)
//	{
//		unsigned char x, y, temp, c;
//		for (c = 0; c < count; c++) {
//			for(x=0; x<(WIDTH); x++)
//			{
//				temp = getWorkingBufferBit(x,HEIGHT-1);
//				for(y=HEIGHT-2; y<HEIGHT-1; y--)
//				{
//					setWorkingBufferBit(x, y+1, getWorkingBufferBit(x, y));
//				}
//				setWorkingBufferBit(x, 0, temp);
//			}
//		}
//
//
//	}
//	else
//	{
//		clearWorkingBuffer();
//	}
//}
//
//void ellipse(int xm, int ym, int a, int b)
//{
//   int dx = 0, dy = b; /* im I. Quadranten von links oben nach rechts unten */
//   long a2 = a*a, b2 = b*b;
//   long err = b2-(2*b-1)*a2, e2; /* Fehler im 1. Schritt */
//
//   do {
//	   setWorkingBufferBit(xm+dx, ym+dy, LED_ON); /* I. Quadrant */
//	   setWorkingBufferBit(xm-dx, ym+dy, LED_ON); /* II. Quadrant */
//	   setWorkingBufferBit(xm-dx, ym-dy, LED_ON); /* III. Quadrant */
//	   setWorkingBufferBit(xm+dx, ym-dy, LED_ON); /* IV. Quadrant */
//
//       e2 = 2*err;
//       if (e2 <  (2*dx+1)*b2) { dx++; err += (2*dx+1)*b2; }
//       if (e2 > -(2*dy-1)*a2) { dy--; err -= (2*dy-1)*a2; }
//   } while (dy >= 0);
//
//   while (dx++ < a) { /* fehlerhafter Abbruch bei flachen Ellipsen (b=1) */
//	   setWorkingBufferBit(xm+dx, ym, LED_ON); /* -> Spitze der Ellipse vollenden */
//	   setWorkingBufferBit(xm-dx, ym, LED_ON);
//   }
//}
//
//void rectangleRotate(unsigned char xstart, unsigned char ystart, unsigned char xend, unsigned char yend, unsigned int angle)
//{
//	char ax, ay, bx, by, cx, cy, dx, dy, mx, my;
//	char tax, tay, tbx, tby, tcx, tcy, tdx, tdy;
//
//	//calculate degrees in radiant
//
//	//berechne Mittelpunkt
//	mx = ((xend - xstart)/2)+xstart;
//	my = ((yend - ystart)/2)+ystart;
//
//	//calculate new points
//	ax = xstart - mx;
//	ay = ystart - my;
//	bx = xend - mx;
//	by = ystart - my;
//	cx = xend - mx;
//	cy = yend - my;
//	dx = xstart - mx;
//	dy = yend - my;
//
//	double tcos, tsin;
//
//	tcos = getCos(angle);
//	tsin = getSin(angle);
//
//	tax = ax*tcos-ay*tsin;
//	tay = ax*tsin+ay*tcos;
//	tbx = bx*tcos-by*tsin;
//	tby = bx*tsin+by*tcos;
//	tcx = cx*tcos-cy*tsin;
//	tcy = cx*tsin+cy*tcos;
//	tdx = dx*tcos-dy*tsin;
//	tdy = dx*tsin+dy*tcos;
//
//	//calculate new points
//	tax += mx;
//	tay += my;
//	tbx += mx;
//	tby += my;
//	tcx += mx;
//	tcy += my;
//	tdx += mx;
//	tdy += my;
//
//	line(tax, tay, tbx, tby);
//	line(tbx, tby, tcx, tcy);
//	line(tcx, tcy, tdx, tdy);
//	line(tdx, tdy, tax, tay);
//}
//
//void rectangleRotateFilled(unsigned char xstart,unsigned char ystart,unsigned char xend,unsigned char yend, unsigned int angle)
//{
//	unsigned char i;
//	for(i = 0; i<=(min((xend-xstart), (yend-ystart))/2); i++)
//	{
//		rectangleRotate(xstart+i, ystart+i, xend-i, yend-i, angle);
//	}
//}

void printChar(unsigned char x, unsigned char  y, unsigned char c)
{
	if(x<WIDTH && y < HEIGHT)
	{
		unsigned char ix, iy;
		for(ix=0; ix<CHAR_WIDTH; ix++)
		{
		    unsigned char temp = pgm_read_byte(&chars[c][ix]);
			for(iy = 0; iy < HEIGHT-y; iy++)
			{
				//TODO: böse!! schlechte char lib! oberes bit ist 0 nicht unteres!!! könnte bei 8 nicht mehr funktionieren
				setWorkingBufferBit(x+ix, y+iy, ((getBitOfByte(temp,7-iy)&0x01)? LED_ON: LED_OFF));
			}
		}
	}
}

//needed for shiftoperations
void copyOutputToWorkingBuffer()
{
    memcpy(workingBuffer, outPutBuffer, sizeof(outPutBufferArray));
}
