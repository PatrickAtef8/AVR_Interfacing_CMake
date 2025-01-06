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
	u8 button1,button2,button3;
	
	MPORT_vInit();

	while(1)
	{
		
		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN0, &button1);

		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN1, &button2);
		
		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN2, &button3);
		
		if (button1 == HIGH)
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,HIGH);
		}
		else
		{
		    MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,LOW);
		
		}
		if (button2 == HIGH)
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN1,HIGH);
		}
		else
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN1,LOW);
			
		}
		if (button3 == HIGH)
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN2,HIGH);
		}
		else
		{
MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN2,LOW);
		}

	}
}
