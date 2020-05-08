#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT() {
  static char blink_count = 0;
  /* 'blink_count_end' is set by current state,
   check stateMachine.c for more info.*/
  if (++blink_count==blink_count_end) {
    state_advance();
    blink_count = 0;
  }
}
