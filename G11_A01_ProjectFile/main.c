#include <stdint.h>
#include "tm4c123gh6pm.h"


int main(void)
{
    SYSCTL_RCGCGPIO_R |= 0x20;	// enable clock to GPIOF
    GPIO_PORTF_DIR_R |= 0x02;	// set PF1 as output
    GPIO_PORTF_DEN_R |= 0x02;	// enable digital function for PF1
    
    int i,x;
    x=SYSCTL_RCC_R;
    
    while(1)
    {
        GPIO_PORTF_DATA_R = 0x02; 	// Turn On PortF LED
       for(i = 0; i <800; i++){}	// delay for 1 millisecond
           GPIO_PORTF_DATA_R= 0x00;	// Turn Off PortF LED
       for(i = 0; i <800; i++){}	// delay for 1 millisecond
    }
}
