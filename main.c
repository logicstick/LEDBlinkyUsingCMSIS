#include <LPC17xx.H>
// do some include here
#include <lpc17xx_gpio.h>


// do some defines here
#define PORT0	0
#define PORT1 1
#define PORT2 2
#define PORT3 3

#define LED  (1<<29)

#define ENABLE_OUTPUT  1
#define ENABLE_INPUT   0
#define MAX_TIME_TRIGGER 10000000


int main(void){
	int i = 0;
	
	// Enable output on the following pin
	GPIO_SetDir(PORT1, LED, ENABLE_OUTPUT);
	
	// Clear the Port
	GPIO_ClearValue(PORT1, LED);
	for(i = 0; i < MAX_TIME_TRIGGER; i++);
	
	while(1){
		// Glow the LED 
		GPIO_SetValue(PORT1, LED);
		// waste some time
		for(i = 0; i < MAX_TIME_TRIGGER; i++);
		// write timer function
		GPIO_ClearValue(PORT1, LED);
		for(i = 0; i < MAX_TIME_TRIGGER; i++);
	}
	
}
