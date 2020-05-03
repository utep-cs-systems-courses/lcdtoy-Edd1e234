#include "switches.h"
#include "buzzer.h"
#include "stateMachinesVisual.h"
#include "stateMachines.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include <shape.h>
#include <abCircle.h>

const int background_screen_state[] = {COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_WHITE};
static char visual_state_1; 


// State machine 1 layers for that.
void state_1_visual() {
  drawString5x7(20,20, "State_1", COLOR_BLUE, COLOR_RED); 
}
void state_2_visual() {
  drawString5x7(20,20, "State 2", COLOR_BLUE, COLOR_GREEN);
}
void state_3_visual() {
  // drawString5x7(20,20, "State 3", COLOR_GREEN, COLOR_RED);
}
void state_4_visual() {
  drawString5x7(20, 20, "State 4", COLOR_BLUE, COLOR_WHITE); 
}
