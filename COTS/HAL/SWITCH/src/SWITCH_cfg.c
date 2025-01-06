#include "SWITCH.h"
#include "SWITCH_cfg.h"
#include "MPORT.h"

const SwitchCfg_t switchCfg[NUM_OF_SWITCHES] =
{
  
    [SWITCH_START] = {
        .port = MPORT_PORTA,
        .pin = MPORT_PIN1,
    }
};
