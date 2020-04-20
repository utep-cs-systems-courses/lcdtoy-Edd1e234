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
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);

  // drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);

  //fillRectangle(0,1, 15, 15, COLOR_ORANGE);

  drawPixel(0, 0, COLOR_RED);

  char row = 0;
  char col = 0;
  for (int i = 0; i < 15; i++) {
    drawPixel(row, col, COLOR_RED);
    row++;
    col++;
  }

  row = 0;
  for (int i = 0; i < 15; i++) {
    drawPixel(0, row, COLOR_RED);
    row++; 
  }
  col = 0; 
  for (int i = 0; i < 15; i++) {
    drawPixel(col,15, COLOR_RED);
    col++;
  }
}
