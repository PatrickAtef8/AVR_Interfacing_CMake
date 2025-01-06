#ifndef SWITCH_CFG_H  
#define SWITCH_CFG_H  


#include "STD_TYPES.h"
#include "SWITCH_cfg.h"


typedef struct{
    u8 port;
    u8 pin;
} SwitchCfg_t;

typedef enum
{
    SWITCH_OK = 0x00,
    SWITCH_NOK,
} SWITCH_enuErrorStatus_t;

typedef enum {
    SWITCH_LOW = 0,
    SWITCH_HIGH
} SWITCH_DIO_PinVoltage_type;

void SWITCH_init(void);
extern const SwitchCfg_t switchCfg[NUM_OF_SWITCHES];
SWITCH_enuErrorStatus_t SWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State);
#endif 