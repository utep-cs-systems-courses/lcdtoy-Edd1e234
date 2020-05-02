#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <shape.h>
#include <abCircle.h>

void main(void)
{
  configureClocks();
  led_init();
  switch_init();
  enableWDTInterrupts();
  buzzer_init();
  lcd_init();
  shapeInit();

  clearScreen(COLOR_BLUE); 

  or_sr(0x8);  // CPU off, GIE on
}

