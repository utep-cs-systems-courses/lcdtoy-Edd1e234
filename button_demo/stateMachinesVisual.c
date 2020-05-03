#include "switches.h"
#include "buzzer.h"
#include "stateMachinesVisual.h"
#include "stateMachines.h"
#include "visualLayers.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include <shape.h>
#include <abCircle.h>

const int background_screen_state[] = {COLOR_RED, COLOR_WHITE, COLOR_BLUE, COLOR_WHITE};
static char visual_state_2=1;
unsigned int bgColor = COLOR_WHITE;

// State machine 1 layers for that.
void state_1_visual() {
  drawString5x7(20,20, "State_1", COLOR_BLUE, COLOR_RED);
}

void draw_neck() {
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
void state_2_visual() {
  drawString5x7(20,20, "State 2", COLOR_BLUE, COLOR_GREEN);

  if (visual_state_2) {
    bgColor = background_screen_state[state];
    layerInit(&fieldLayer);
    layerDraw(&fieldLayer);

    layerGetBounds(&fieldLayer, &fieldFence);
    drawFace(); 
  }

   visual_state_2=0;
}
void state_3_visual() {
  // drawString5x7(20,20, "State 3", COLOR_GREEN, COLOR_RED);
}
void state_4_visual() {
  drawString5x7(20, 20, "State 4", COLOR_BLUE, COLOR_WHITE);
}
