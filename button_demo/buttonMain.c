#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "stateMachinesVisual.h"
#include "stateMachines.h"
#include "buzzer.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <shape.h>
#include <abCircle.h>

char cpu = 0; 

void draw(); 

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

  enableWDTInterrupts();
  or_sr(0x8);

  buzzer_set_period(1000);
  for (;;) {
    while (!cpu) {
      P1OUT &= (0xff - LEDS) | LED_GREEN;
      P1OUT |= ~LED_GREEN;
      buzzer_set_period(900); 
      or_sr(0x18); 
    }
    //state_advance(); 
    cpu = 0;
    P1OUT |= LED_GREEN;
    //draw(); 
  }
}

void draw() {
  buzzer_set_period(1000); 
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
  default:
    state_4_visual();
  }
}

/** Watchdog timer interrupt handler. 15 interrupts/sec */
void wdt_c_handler()
{
  buzzer_set_period(200); 
  static short count = 0;
  count++;
  P1OUT |= LED_GREEN;
  if (count==15) {
    if (p2sw_read()) {
      cpu=1; 
    }
    count = 0; 
  }
  P1OUT &= ~LED_GREEN;
}
