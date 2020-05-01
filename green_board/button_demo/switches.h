#ifndef switches_included
#define switches_included

#define SW1 BIT0 /* switch1 is P2.0 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)		/* only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();


/* Boolean statements */
extern char switch_state_down_button_1, switch_state_down_button_2, switch_state_down_button_3;
extern char switch_state_down_button_4, switch_state_changed;

#endif // included
