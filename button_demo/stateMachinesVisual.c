#include "switches.h"
#include "buzzer.h"
#include "stateMachinesVisual.h"
#include "stateMachines.h"
#include "visualLayers.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include <shape.h>
#include <abCircle.h>

static char visual_state_2=1;
unsigned int bgColor = COLOR_WHITE;

// State machine 1 layers for that.
void state_1_visual() {
  clearScreen(COLOR_WHITE); 
  drawString5x7(10,20, "Button 1 Main Menu", COLOR_RED, COLOR_WHITE);
  drawString5x7(10,40, "Button 2 Layers", COLOR_RED, COLOR_WHITE);
  drawString5x7(10,60, "Button 3 BREAK", COLOR_RED, COLOR_WHITE);
  drawString5x7(10,80, "Button 4 Song/FACE", COLOR_RED, COLOR_WHITE);
  // drawFace(); 
}

void state_2_visual() {
  layerInit(&fieldLayer);
  layerDraw(&fieldLayer);
  layerGetBounds(&fieldLayer, &fieldFence);
}
void state_3_visual() {
  //clearScreen(COLOR_WHITE);
  //drawFace(); 
  // drawString5x7(20,20, "State 3", COLOR_GREEN, COLOR_RED);
}
void state_4_visual() {
  //clearScreen(COLOR_WHITE); 
  //drawString5x7(20, 20, "State 4", COLOR_BLUE, COLOR_WHITE);
  drawFace(); 
}
