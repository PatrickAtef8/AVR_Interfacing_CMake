#include "STD_TYPES.h"
#include "MPORT.h"
#include "MDIO.h"
#include "SWITCH.h"
#include "SWITCH_cfg.h"

void SWITCH_init(void)
{
    u8 currPinPort = 0;
    u8 iter;

    for (iter = 0; iter < NUM_OF_SWITCHES; iter++)
    {
        currPinPort = (switchCfg[iter].port << 4) + switchCfg[iter].pin;
        MPORT_enuSetPinDirection(currPinPort , MPORT_INPUT);  // Set pins as input for switches
    }
}

SWITCH_enuErrorStatus_t SWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State)
{
   SWITCH_enuErrorStatus_t SWITCH_RET_enuError = SWITCH_NOK;

    if (Copy_u8SwitchName >= NUM_OF_SWITCHES)
    {
        SWITCH_RET_enuError = SWITCH_NOK;  // Invalid switch name
    }
    else
    {
        // Using MDIO_enuGetPinValue to get the switch state
        MDIO_enuErrorStatus_t MDIO_RET_enuError = MDIO_enuGetPinValue(switchCfg[Copy_u8SwitchName].port,switchCfg[Copy_u8SwitchName].pin, Add_pu8State);

        if (MDIO_RET_enuError == MDIO_OK)
        {
            SWITCH_RET_enuError = SWITCH_OK;  // Successfully retrieved the state
        }
        else
        {
            SWITCH_RET_enuError = SWITCH_NOK;  // Error reading the pin
        }
    }

    return SWITCH_RET_enuError;
}

