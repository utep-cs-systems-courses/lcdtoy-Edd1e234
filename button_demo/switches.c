#include <msp430.h>
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include "stateMachines.h"
#include "stateMachinesUtil.h"
#include "stateMachinesVisual.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include <shape.h>
#include <abCircle.h> 

static char prev_state; 
char switch_state_down_button_1, switch_state_down_button_2, switch_state_down_button_3;
char switch_state_down_button_4, switch_state_changed; /* effectively boolean */
char p2val, switches_last_reported;

static char 
switch_update_interrupt_sense()
{
  p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  state = 2; 
  led_update_switch();
}

/* Returns a word where:
 * the high-order byte is the buttons that have changed.
 * The low-order byte is the current state of the buttons.
 */

// TODO change p2val to switches_current
unsigned int p2sw_read() {
  unsigned int sw_changed = p2val ^ switches_last_reported;
  switches_last_reported = p2val;
  return p2val | (sw_changed << 8);
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  
  state = (p2val & SW1) ? state: 0;
  state = (p2val & SW2) ? state: 1;
  state = (p2val & SW3) ? state: 2;
  state = (p2val & SW4) ? state: 3;
}
