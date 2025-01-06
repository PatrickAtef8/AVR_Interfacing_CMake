#include "STD_TYPES.h"
#include "MPORT.h"
#include "MDIO.h"
#include "LED.h"
#include "SWITCH.h"
#include "SWITCH_cfg.h"
#include "LED_cfg.h"

void main(void)
{
    u8 switchState;

    // Initialize LED and Switch
    LED_init();
    SWITCH_init();
    MPORT_enuSetPinDirection(PINA0, MPORT_OUTPUT);
    MPORT_enuSetPinMode(PINA1, INPUT_PULLUP );

    while (1)
    {
        // Get the state of the switch (pressed or not)
        SWITCH_enuGetSwitchState(SWITCH_START, &switchState);

        if (switchState == SWITCH_LOW)  // If switch is pressed
        {
            LED_enuSetLedState(LED_START, HIGH);  // Turn ON LED
        }
        else  // If switch is not pressed
        {
            LED_enuSetLedState(LED_START, LOW);   // Turn OFF LED
        }
    }
}
