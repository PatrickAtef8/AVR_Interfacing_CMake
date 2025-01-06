#include "MPORT.h"
#include "MPORT_cfg.h"
#include "MemMap.h"
#include "BIT_MATH.h"

MPORT_enuErrorStatus_t MPORT_RET_enuError =MPORT_OK;

MPORT_enuErrorStatus_t MPORT_enuSetPinConfigration(MPort_Num Copy_enuPortNum,MPORT_Pin_Num Copy_enuPinNum,MPORT_PinStatus Copy_enuConfigration)
{
	MPORT_enuErrorStatus_t MPORT_RET_enuError =MPORT_OK;
	if(Copy_enuPortNum > MPORT_PORTD)
	{
	        MPORT_RET_enuError=MPORT_NOK;
	} 
	else if (Copy_enuPinNum > 7)
	{
			MPORT_RET_enuError=MPORT_NOK;
	}
	
	else
	switch(Copy_enuConfigration)
	{
		
	case OUTPUT:
	
	switch(Copy_enuPortNum)
	{
		
	case MPORT_PORTA:
	
	SET_BIT(DDRA,Copy_enuPinNum);
	
	break;
	
	case MPORT_PORTB:
	
	SET_BIT(DDRB,Copy_enuPinNum);
	
	break;
	
	case MPORT_PORTC:
	SET_BIT(DDRC,Copy_enuPinNum);
	
	break;
	
	case MPORT_PORTD:
	SET_BIT(DDRD,Copy_enuPinNum);
	break;
}
break;

case INPUT_PULLUP:
switch(Copy_enuPortNum)
{
	case MPORT_PORTA:
	
	CLR_BIT(DDRA,Copy_enuPinNum);
	SET_BIT(PORTA,Copy_enuPinNum);
	break;
	
	case MPORT_PORTB:
	
	CLR_BIT(DDRB,Copy_enuPinNum);
	SET_BIT(PORTB,Copy_enuPinNum);
	break;
	
	case MPORT_PORTC:
	
	CLR_BIT(DDRC,Copy_enuPinNum);
	SET_BIT(PORTC,Copy_enuPinNum);
	break;
	case MPORT_PORTD:
	
	CLR_BIT(DDRD,Copy_enuPinNum);
	SET_BIT(PORTD,Copy_enuPinNum);
	break;
	}
	break;
	
	
	case INPUT_PULLDOWN:
	switch(Copy_enuPortNum)
	{
		case MPORT_PORTA:
		
		CLR_BIT(DDRA,Copy_enuPinNum);
		CLR_BIT(PORTA,Copy_enuPinNum);
		break;
		
		case MPORT_PORTB:
		
		CLR_BIT(DDRB,Copy_enuPinNum);
		CLR_BIT(PORTB,Copy_enuPinNum);
		break;
		
		case MPORT_PORTC:
		
		CLR_BIT(DDRC,Copy_enuPinNum);
		CLR_BIT(PORTC,Copy_enuPinNum);
		break;
		case MPORT_PORTD:
		
		CLR_BIT(DDRD,Copy_enuPinNum);
		CLR_BIT(PORTD,Copy_enuPinNum);
		break;
		
	}
	break;
	}
	return MPORT_RET_enuError;
}
	
MPORT_enuErrorStatus_t MPORT_enuSetPortConfigration(MPort_Num Copy_enuPortNum,MPORT_PortStatus Copy_enuConfigration)
{ 
	MPORT_enuErrorStatus_t MPORT_RET_enuError =MPORT_OK;
	if(Copy_enuPortNum > MPORT_PORTD)
	{
		MPORT_RET_enuError=MPORT_NOK;
	}
else if ((Copy_enuConfigration != PORT_OUTPUT) && (Copy_enuConfigration != PORT_INPUT))
{
	MPORT_RET_enuError= MPORT_NOK;
	
}
	else
	
	switch (Copy_enuPortNum)
	{
		case MPORT_PORTA:
		DDRA = Copy_enuConfigration;
		break;

		case MPORT_PORTB:
		DDRB = Copy_enuConfigration;
		break;

		case MPORT_PORTC:
		DDRC = Copy_enuConfigration;
		break;

		case MPORT_PORTD:
		DDRD = Copy_enuConfigration;
		break;
	}
	
return MPORT_RET_enuError;
}

void MPORT_vInit(void)
 {
	for (int pin = 0; pin < MPORT_TOTAL_PIN; pin++) 
	{
		MPort_Num port = pin / 8;  // Determine the port (0 -> PORTA, 1 -> PORTB, etc.)
		u8 pin_num = pin % 8;          // Determine the pin number (0 -> 7)

		// Get the pin status from the PinCfg_array
		
		MPORT_PinStatus status = PinCfg_array[pin];

		// Set the pin configuration based on the status
		MPORT_enuSetPinConfigration(port, pin_num, status);
	}
}


MPORT_enuErrorStatus_t MPORT_enuSetPinDirection( u8 Copy_enuPinNum  ,  u8 Copy_enuPinDirection )
{  
  // Extract port number from the pin number
    u8 port = Copy_enuPinNum >> 4; // High nibble represents the port
    u8 pin = Copy_enuPinNum & 0x0F;  // Extract the pin number (lower nibble)

    // Based on the port, configure the pin direction
    switch (port)
    {
        case MPORT_PORTA:
            if (Copy_enuPinDirection == MPORT_OUTPUT)
                SET_BIT(DDRA, pin);  // Set the pin as output
            else
                CLR_BIT(DDRA, pin);  // Set the pin as input
            break;

        case MPORT_PORTB:
            if (Copy_enuPinDirection == MPORT_OUTPUT)
                SET_BIT(DDRB, pin);  // Set the pin as output
            else
                CLR_BIT(DDRB, pin);  // Set the pin as input
            break;

        case MPORT_PORTC:
            if (Copy_enuPinDirection == MPORT_OUTPUT)
                SET_BIT(DDRC, pin);  // Set the pin as output
            else
                CLR_BIT(DDRC, pin);  // Set the pin as input
            break;

        case MPORT_PORTD:
            if (Copy_enuPinDirection == MPORT_OUTPUT)
                SET_BIT(DDRD, pin);  // Set the pin as output
            else
                CLR_BIT(DDRD, pin);  // Set the pin as input
            break;
    }

    return MPORT_OK;  // Successful operation
}



MPORT_enuErrorStatus_t MPORT_enuSetPinMode( u8 Copy_enuPinNum  ,  MPORT_PinStatus Copy_enuPinMode )
{
 // Extract port and pin number from the combined value (assuming same format as before)
    u8 port = Copy_enuPinNum >> 4;           // High nibble represents the port
    u8 pin = Copy_enuPinNum & 0x0F;          // Extract the pin number (low nibble)


    // Handle the specific pin mode configuration
    switch (port)
    {
        case MPORT_PORTA:
            switch (Copy_enuPinMode)
            {
                case INPUT_PULLUP:
                    CLR_BIT(DDRA, pin); // Set pin as input
                    SET_BIT(PORTA, pin); // Enable pull-up resistor
                    break;

                case INPUT_PULLDOWN:
                    CLR_BIT(DDRA, pin); // Set pin as input
                    CLR_BIT(PORTA, pin); // Disable pull-up resistor (enable pull-down if possible)
                    break;

            }
            break;

        case MPORT_PORTB:
            switch (Copy_enuPinMode)
            {
                case INPUT_PULLUP:
                    CLR_BIT(DDRB, pin); // Set pin as input
                    SET_BIT(PORTB, pin); // Enable pull-up resistor
                    break;

                case INPUT_PULLDOWN:
                    CLR_BIT(DDRB, pin); // Set pin as input
                    CLR_BIT(PORTB, pin); // Disable pull-up resistor
                    break; 
            }
         

        case MPORT_PORTC:
            switch (Copy_enuPinMode)
            {
                case INPUT_PULLUP:
                    CLR_BIT(DDRC, pin); // Set pin as input
                    SET_BIT(PORTC, pin); // Enable pull-up resistor
                    break;

                case INPUT_PULLDOWN:
                    CLR_BIT(DDRC, pin); // Set pin as input
                    CLR_BIT(PORTC, pin); // Disable pull-up resistor
                    break;
            }

        case MPORT_PORTD:
            switch (Copy_enuPinMode)
            {
                case INPUT_PULLUP:
                    CLR_BIT(DDRD, pin); // Set pin as input
                    SET_BIT(PORTD, pin); // Enable pull-up resistor
                    break;

                case INPUT_PULLDOWN:
                    CLR_BIT(DDRD, pin); // Set pin as input
                    CLR_BIT(PORTD, pin); // Disable pull-up resistor
                    break;

            }
    }

   
}

