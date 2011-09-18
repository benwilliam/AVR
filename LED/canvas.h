/*
 * canvas.h
 *
 *  Created on: 07.09.2011
 *      Author: rdo
 */

#ifndef CANVAS_H_
#define CANVAS_H_


//methods
void line(unsigned char xstart,unsigned char ystart,unsigned char xend,unsigned char yend);
void rectangle(unsigned char xstart,unsigned char ystart,unsigned char xend,unsigned char yend);
void rectangleFilled(unsigned char xstart,unsigned char ystart,unsigned char xend,unsigned char yend);
void rectangleRotate(unsigned char xstart,unsigned char ystart,unsigned char xend,unsigned char yend, unsigned int angle);
void rectangleRotateFilled(unsigned char xstart,unsigned char ystart,unsigned char xend,unsigned char yend, unsigned int angle);
void circle(int x0, int y0, int radius);
void circlefilled(int x0, int y0, int radius);
void shiftLeft(unsigned char count);
void shiftRight(unsigned char count);
void shiftLeftRound(unsigned char count);
void shiftRightRound(unsigned char count);
void shiftUp(unsigned char count);
void shiftDown(unsigned char count);
void shiftUpRound(unsigned char count);
void shiftDownRound(unsigned char count);
void ellipse(int xm, int ym, int a, int b);
void printChar(unsigned char x, unsigned char  y, unsigned char c);
void copyOutputToWorkingBuffer();

#endif /* CANVAS_H_ */
