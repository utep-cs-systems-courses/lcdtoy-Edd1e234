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

  or_sr(0x8); 

}

/** Watchdog timer interrupt handler. 15 interrupts/sec */
void wdt_c_handler()
{
  static short count = 0;
  count ++;
  if (count == 15) {
    //mlAdvance(&ml0, &fieldFence);
    if (p2sw_read()) {
         count = 0;
    }
  }
}
