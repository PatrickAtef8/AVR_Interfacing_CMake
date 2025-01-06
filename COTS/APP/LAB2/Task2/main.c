#include "MDIO.h"
#include "MDIO_cfg.h"
#include "MPORT.h"
#include "MPORT_cfg.h"
#include "STD_TYPES.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{


	u8 counter = 0; //char counter
	u8 button;  
	
MPORT_enuSetPortConfigration(MPORT_PORTD, MPORT_OUTPUT); 
MPORT_enuSetPinConfigration(MPORT_PORTB, MPORT_PIN2, INPUT_PULLUP); 


while(1)
    { 

		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN2, &button);
        
		if (button == LOW)
		{
				MDIO_enuSetPortValue(MDIO_PORTD, counter);
				counter++;
				_delay_ms(700);
		}
		
    }

}
