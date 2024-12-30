#include "MDIO.h"
#include "MDIO_cfg.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"


int main(void)
{
	u8 counter = 0; //char counter
	u8 button;  
	//MDIO_vInit();
	
	
MDIO_enuSetPortConfigration(MDIO_PORTA, PORT_OUTPUT);//FOR TASK 1
MDIO_enuSetPortConfigration(MDIO_PORTD, PORT_OUTPUT); //FOR TASK 2
MDIO_enuSetPinConfigration(MDIO_PORTB, MDIO_PIN1, INPUT_PULLUP); //FOR TASK 1
MDIO_enuSetPinConfigration(MDIO_PORTB, MDIO_PIN2, INPUT_PULLUP); //FOR TASK 2


while(1)
    { 
		MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN1,HIGH);
		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN1, &button);
		if (button == HIGH)
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN1,HIGH);
			_delay_ms(200);
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN1,LOW);
			_delay_ms(200);
		}
		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN2, &button);
		if (button == HIGH)
		{
				MDIO_enuSetPortValue(MDIO_PORTD, counter);
				counter++;
				_delay_ms(700);
		}
		
    }

}
