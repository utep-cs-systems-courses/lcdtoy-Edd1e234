#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachines.h"
#include "stateMachinesVisual.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <shape.h>
#include <abCircle.h>

char cpu =0;
static char prev_state = 6;

void draw() {
  if (prev_state==state) return;
  
  switch(state) {
  case 0:
    state_1_visual();
    break;
  case 1:
    state_2_visual();
    break;
  case 2:
    state_3_visual();
    break;
  case 3:
    state_4_visual();
    break;
  }
  prev_state = state; 
}

void main(void)
{
  configureClocks();
  led_init();
  switch_init();
  buzzer_init();
  lcd_init();
  shapeInit();

  clearScreen(COLOR_RED);

  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */


  for(;;) {
    while (!cpu) { /**< Pause CPU if screen doesn't need updating */
      clearScreen(COLOR_BLUE);
      or_sr(0x10);	      /**< CPU OFF */
    }
    clearScreen(COLOR_GREEN);
    cpu = 0;
    draw();
  }
}

/** Watchdog timer interrupt handler. 15 interrupts/sec */
void wdt_c_handler()
{
  static short count = 0;
  P1OUT |= LED_GREEN;		      /**< Green LED on when cpu on */
  count ++;
  if (count == 15) {
    if (p2sw_read()) {
      cpu = 1; 
    }
    count = 0;
  }
  P1OUT &= ~LED_GREEN;		    /**< Green LED off when cpu off */
}
