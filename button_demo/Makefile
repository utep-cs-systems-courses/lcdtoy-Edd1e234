# makfile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf

#additional rules for files
button.elf: ${COMMON_OBJECTS} p2_interrupt_handler.o led.o switches.o buttonMain.o buzzer.o stateMachines.o stateMachinesUtil.o stateMachinesVisual.o visualLayers.o wdInterruptHandler.o ../lib/libTimer.a ../lib/libShape.a ../lib/libLcd.a ../lib/libCircle.a 
	${CC} ${CFLAGS} ${LDFLAGS} $^ -L../lib -lLcd -o $@

load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf *~ *# *.#

wdInterruptHandler.o: stateMachines.h wdInterruptHandler.s

led.o: led.c led.h

stateMachines.o: led.h stateMachines.h switches.h stateMachinesUtil.h

stateMachinesUtil.o: stateMachinesUtil.h buzzer.h

buzzer.c: buzzer.h
