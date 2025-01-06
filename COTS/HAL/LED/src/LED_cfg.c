#include "LED.h"
#include "LED_cfg.h"
#include "MPORT.h"

const LedCfg_t ledCfg[NUM_OF_LEDS]=
{
[LED_START] ={
.port = MPORT_PORTA,
.pin = MPORT_PIN0,
}
};