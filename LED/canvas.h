/*
 * canvas.h
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
