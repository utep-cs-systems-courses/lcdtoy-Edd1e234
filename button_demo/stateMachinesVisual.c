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
void state_2_visual() {
  drawString5x7(20,20, "State 2", COLOR_BLUE, COLOR_GREEN);

  if (visual_state_2) {
    bgColor = background_screen_state[state]; 
    layerInit(&fieldLayer);
    layerDraw(&fieldLayer);

    layerGetBounds(&fieldLayer, &fieldFence);
  }
    
   visual_state_2=0; 
}
void state_3_visual() {
  // drawString5x7(20,20, "State 3", COLOR_GREEN, COLOR_RED);
}
void state_4_visual() {
  drawString5x7(20, 20, "State 4", COLOR_BLUE, COLOR_WHITE); 
}
