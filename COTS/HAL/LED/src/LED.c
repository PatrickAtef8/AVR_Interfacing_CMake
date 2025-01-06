#include "STD_TYPES.h"
#include "MPORT.h"
#include "MDIO.h"
#include "LED.h"
#include "LED_cfg.h"

void LED_init(void)
{
u8 currPinPort = 0;
u8 iter;

for(iter=0;iter<NUM_OF_LEDS;iter++)
{
currPinPort = (ledCfg[iter].port<<4) + ledCfg[iter].pin;

MPORT_enuSetPinDirection(currPinPort , MPORT_OUTPUT);
}

}


LED_enuErrorStatus_t LED_enuSetLedState(u8 Copy_u8LedName, u8 Copy_u8State)
{

LED_enuErrorStatus_t LED_RET_enuError = LED_NOK;

if(Copy_u8LedName > NUM_OF_LEDS)
{
    LED_RET_enuError = LED_NOK; 
}
else if(Copy_u8State > LED_HIGH)
{
    LED_RET_enuError = LED_NOK;
}
else
{
LED_RET_enuError= LED_OK;
LED_RET_enuError = MDIO_enuSetPinValue(ledCfg[Copy_u8LedName].port, ledCfg[Copy_u8LedName].pin, Copy_u8State);
}
return LED_RET_enuError ;
}
