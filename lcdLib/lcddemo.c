/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();

  clearScreen(COLOR_WHITE);

  // drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);

  //fillRectangle(0,1, 15, 15, COLOR_ORANGE);

  // drawPixel(0, 0, COLOR_RED);

  u_char length = 20;

  u_char x = 2;
  u_char y = 2;

  //  drawSquare(x, y, length, COLOR_RED);

  /*
  // Two triangles facing eachother.
  u_char size = 15;
  u_char x_offset = 0;
  u_char y_offset = 0;
  for (u_char r = 0; r <=size; r+=2) {
    u_char colLeft = size-r;
    u_char colRight = size;
    for (u_char c = colLeft; c <= colRight; c+=2) {
      drawPixel(c+x_offset, y_offset+r, COLOR_RED); // base shape
      drawPixel(x_offset-c, y_offset+r, COLOR_RED); // mirroring col
      
      drawPixel(c+x_offset, y_offset-r, COLOR_RED); // mirroring base shape, row.
      drawPixel(x_offset-c, y_offset-r, COLOR_RED); // left corner. 
    }
  }
  */
  
  /*
  int x_offset =10;
  int y_offset = 10;
  int width_ = 20;
  int size = 10;
  for (int i=0; i <= size; i++) {
    int colLeft = size-i;
    for (int j=0; j <=i; j++) {
      //drawPixel(x_offset+colLeft, y_offset-j, COLOR_BLUE);
      drawPixel(x_offset-colLeft, y_offset-j, COLOR_BLUE); 
      
      //drawPixel(x_offset+colLeft, y_offset+j, COLOR_RED);
      //drawPixel(x_offset-colLeft, y_offset+j, COLOR_GREEN);
    }
  }
  */

  
  u_int color = COLOR_BLUE; 
  u_int x_offset = 40;
  u_int y_offset = 40;
  u_int top_length = 10;
  u_int bottom_length = 15;
  u_int actual_length = bottom_length-top_length; 

  for (int i = 0; i<=top_length; i++) {
    // Square loop
    
    for (int c = 0; c < top_length; c++) {
      drawPixel(c+x_offset, i+y_offset, color);  
    }
    drawPixel(x_offset, y_offset+i, COLOR_BLACK);
    drawPixel(x_offset+top_length, y_offset+i, COLOR_BLACK);
    drawPixel(x_offset+i, y_offset, COLOR_BLACK);
    drawPixel(x_offset+i, y_offset+top_length, COLOR_BLACK);
  }

  x_offset -= 1;
  for (int i=0; i<=top_length; i++) {
    u_int colLeft = top_length-i; 
    for (int j=0; j<=i; j++) {
      drawPixel(x_offset+i-top_length, y_offset+top_length-j, color); 
    }
    drawPixel(0+x_offset, i+y_offset, COLOR_BLACK);
    drawPixel(i+x_offset-top_length, y_offset+top_length, COLOR_BLACK);
    drawPixel(x_offset+i-top_length, y_offset+top_length-i, COLOR_BLACK); 
  }
}
