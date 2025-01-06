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
	u8 button1,button2,button3,button4;  
	

// MPORT_enuSetPinDirection(PINA0 , MPORT_OUTPUT);
// MPORT_enuSetPinDirection(PINA1 , MPORT_INPUT);

MPORT_enuSetPortConfigration(MPORT_PORTA, PORT_OUTPUT);
MPORT_enuSetPinConfigration(MPORT_PORTB, MPORT_PIN0, INPUT_PULLUP); 
MPORT_enuSetPinConfigration(MPORT_PORTB, MPORT_PIN1, INPUT_PULLUP); 
MPORT_enuSetPinConfigration(MPORT_PORTB, MPORT_PIN2, INPUT_PULLUP); 
MPORT_enuSetPinConfigration(MPORT_PORTB, MPORT_PIN3, INPUT_PULLUP); 


while(1)
    { 

		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN0, &button1);

		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN1, &button2);
		
		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN2, &button3);

		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN3, &button4);
		
		if (button1 == HIGH)
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,LOW);
		}
		else
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,HIGH);
		}
		if (button2 == HIGH)
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN1,LOW);
		}
		else
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN1,HIGH);
		}
		if (button3 == HIGH)
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN2,LOW);
		}
		else
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN2,HIGH);
		}
		if (button4 == LOW)
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,LOW);
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN1,LOW);
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN2,LOW);
		}
		else
		{
	
		}
    }
}
