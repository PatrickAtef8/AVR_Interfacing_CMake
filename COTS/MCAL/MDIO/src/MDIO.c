#include "MDIO.h"
#include "MDIO_cfg.h"
#include "MemMap.h"
#include "BIT_MATH.h"


MDIO_enuErrorStatus_t RET_enuError =MDIO_OK;

// MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(Port_Num Copy_enuPortNum,Pin_Num Copy_enuPinNum,DIO_PinStatus Copy_enuConfigration)
// {
// 	MDIO_enuErrorStatus_t RET_enuError =MDIO_OK;
// 	if(Copy_enuPortNum > MDIO_PORTD)
// 	{
// 	        RET_enuError=MDIO_NOK;
// 	}
// 	else if (Copy_enuPinNum > 7)
// 	{
// 			RET_enuError=MDIO_NOK;
// 	}
	
// 	else
// 	switch(Copy_enuConfigration)
// 	{
		
// 	case OUTPUT:
	
// 	switch(Copy_enuPortNum)
// 	{
		
// 	case MDIO_PORTA:
	
// 	SET_BIT(DDRA,Copy_enuPinNum);
	
// 	break;
	
// 	case MDIO_PORTB:
	
// 	SET_BIT(DDRB,Copy_enuPinNum);
	
// 	break;
	
// 	case MDIO_PORTC:
// 	SET_BIT(DDRC,Copy_enuPinNum);
	
// 	break;
	
// 	case MDIO_PORTD:
// 	SET_BIT(DDRD,Copy_enuPinNum);
// 	break;
// }
// break;

// case INPUT_PULLUP:
// switch(Copy_enuPortNum)
// {
// 	case MDIO_PORTA:
	
// 	CLR_BIT(DDRA,Copy_enuPinNum);
// 	SET_BIT(PORTA,Copy_enuPinNum);
// 	break;
	
// 	case MDIO_PORTB:
	
// 	CLR_BIT(DDRB,Copy_enuPinNum);
// 	SET_BIT(PORTB,Copy_enuPinNum);
// 	break;
	
// 	case MDIO_PORTC:
	
// 	CLR_BIT(DDRC,Copy_enuPinNum);
// 	SET_BIT(PORTC,Copy_enuPinNum);
// 	break;
// 	case MDIO_PORTD:
	
// 	CLR_BIT(DDRD,Copy_enuPinNum);
// 	SET_BIT(PORTD,Copy_enuPinNum);
// 	break;
// 	}
// 	break;
	
	
// 	case INPUT_PULLDOWN:
// 	switch(Copy_enuPortNum)
// 	{
// 		case MDIO_PORTA:
		
// 		CLR_BIT(DDRA,Copy_enuPinNum);
// 		CLR_BIT(PORTA,Copy_enuPinNum);
// 		break;
		
// 		case MDIO_PORTB:
		
// 		CLR_BIT(DDRB,Copy_enuPinNum);
// 		CLR_BIT(PORTB,Copy_enuPinNum);
// 		break;
		
// 		case MDIO_PORTC:
		
// 		CLR_BIT(DDRC,Copy_enuPinNum);
// 		CLR_BIT(PORTC,Copy_enuPinNum);
// 		break;
// 		case MDIO_PORTD:
		
// 		CLR_BIT(DDRD,Copy_enuPinNum);
// 		CLR_BIT(PORTD,Copy_enuPinNum);
// 		break;
		
// 	}
// 	break;
// 	}
// 	return RET_enuError;
// }
	
// MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(Port_Num Copy_enuPortNum,DIO_PortStatus Copy_enuConfigration)
// { 
// 	MDIO_enuErrorStatus_t RET_enuError =MDIO_OK;
// 	if(Copy_enuPortNum > MDIO_PORTD)
// 	{
// 		RET_enuError=MDIO_NOK;
// 	}
// else if ((Copy_enuConfigration != PORT_OUTPUT) && (Copy_enuConfigration != PORT_INPUT))
// {
// 	RET_enuError= MDIO_NOK;
	
// }
// 	else
	
// 	switch (Copy_enuPortNum)
// 	{
// 		case MDIO_PORTA:
// 		DDRA = Copy_enuConfigration;
// 		break;

// 		case MDIO_PORTB:
// 		DDRB = Copy_enuConfigration;
// 		break;

// 		case MDIO_PORTC:
// 		DDRC = Copy_enuConfigration;
// 		break;

// 		case MDIO_PORTD:
// 		DDRD = Copy_enuConfigration;
// 		break;
// 	}
	
// return RET_enuError;
// }

MDIO_enuErrorStatus_t MDIO_enuSetPinValue(Port_Num Copy_enuPortNum, Pin_Num Copy_enuPinNum,DIO_PinVoltage_type Copy_enuState)
{
		MDIO_enuErrorStatus_t RET_enuError =MDIO_OK;

	if (Copy_enuPortNum > MDIO_PIN7)
	{
		RET_enuError = MDIO_NOK;
	}

	else if (Copy_enuPinNum > MDIO_PORTD)
	{
		RET_enuError= MDIO_NOK;
	
	}

	else if ((Copy_enuState != HIGH) && (Copy_enuState != LOW))
	{
		RET_enuError = MDIO_NOK;
	}
	
	else
	switch (Copy_enuPortNum)
	{
		case MDIO_PORTA:
		if (Copy_enuState == HIGH)
		{
			SET_BIT(PORTA, Copy_enuPinNum);
		}
		else if (Copy_enuState == LOW)
		{
			CLR_BIT(PORTA, Copy_enuPinNum);
		}
		break;

		case MDIO_PORTB:
		if (Copy_enuState == HIGH)
		{
			SET_BIT(PORTB, Copy_enuPinNum);
		}
		else if (Copy_enuState == LOW)
		{
			CLR_BIT(PORTB, Copy_enuPinNum);
		}
		break;

		case MDIO_PORTC:
		if (Copy_enuState == HIGH)
		{
			SET_BIT(PORTC, Copy_enuPinNum);
		}
		else if (Copy_enuState == LOW)
		{
			CLR_BIT(PORTC, Copy_enuPinNum);
		}
		break;

		case MDIO_PORTD:
		if (Copy_enuState == HIGH)
		{
			SET_BIT(PORTD, Copy_enuPinNum);
		}
		else if (Copy_enuState == LOW)
		{
			CLR_BIT(PORTD, Copy_enuPinNum);
		}
		break;
	}
	
	return RET_enuError;
}
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(Port_Num Copy_enuPortNum,DIO_PortVoltage_type Copy_enuPortState)
{
	MDIO_enuErrorStatus_t RET_enuError = MDIO_OK;

	if (Copy_enuPortNum > MDIO_PORTD)
	{
		RET_enuError = MDIO_NOK;
		
	}

	else if ((Copy_enuPortState > ALL_HIGH) || (Copy_enuPortState < ALL_LOW))
	{
		RET_enuError = MDIO_NOK;
	}
	
else
	switch (Copy_enuPortNum)
	{
		case MDIO_PORTA:
		PORTA = Copy_enuPortState;
		break;

		case MDIO_PORTB:
		PORTB = Copy_enuPortState;
		break;

		case MDIO_PORTC:
		PORTC = Copy_enuPortState;
		break;

		case MDIO_PORTD:
		PORTD = Copy_enuPortState;
		break;
	}

	return RET_enuError;
}

MDIO_enuErrorStatus_t MDIO_enuGetPinValue(Port_Num  Copy_enuPortNum,Pin_Num Copy_enuPinNum,u8* Add_pu8PinValue)
{
	MDIO_enuErrorStatus_t RET_enuError = MDIO_OK;

	if (Copy_enuPortNum > MDIO_PIN7) 
	{
		RET_enuError =MDIO_NOK;
		
	}

	else if (Copy_enuPinNum > MDIO_PORTD) 
	{
		RET_enuError = MDIO_NOK;
		
	}

	else if (Add_pu8PinValue == NULL)
	{
		RET_enuError = MDIO_NULL_PTR;
		
	}
	else

	switch (Copy_enuPortNum)
	{
		case MDIO_PORTA:
		(*Add_pu8PinValue) = GET_BIT(PINA, Copy_enuPinNum);
		break;

		case MDIO_PORTB:
		(*Add_pu8PinValue) = GET_BIT(PINB, Copy_enuPinNum);
		break;

		case MDIO_PORTC:
		(*Add_pu8PinValue) = GET_BIT(PINC, Copy_enuPinNum);
		break;

		case MDIO_PORTD:
		(*Add_pu8PinValue) = GET_BIT(PIND, Copy_enuPinNum);
		break;
	}
	
	return RET_enuError;
}

// void MDIO_vInit(void)
//  {
// 	for (int pin = 0; pin < TOTAL_PIN; pin++) 
// 	{
// 		Port_Num port = pin / 8;  // Determine the port (0 -> PORTA, 1 -> PORTB, etc.)
// 		u8 pin_num = pin % 8;          // Determine the pin number (0 -> 7)

// 		// Get the pin status from the PinCfg_array
		
// 		DIO_PinStatus status = PinCfg_array[pin];

// 		// Set the pin configuration based on the status
// 		MDIO_enuSetPinConfigration(port, pin_num, status);
// 	}
// }

//ar -x libMdio.a









