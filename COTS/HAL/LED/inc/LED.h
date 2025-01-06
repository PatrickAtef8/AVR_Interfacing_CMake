#ifndef LED_CFG_H  
#define LED_CFG_H  


#include "STD_TYPES.h"
#include "LED_cfg.h"

typedef struct{
    u8 port;
    u8 pin;
} LedCfg_t;

typedef enum
{
	LED_OK=0x00,
	LED_NOK,
	}LED_enuErrorStatus_t;

typedef enum{
	LED_LOW=0,
	LED_HIGH
}LED_DIO_PinVoltage_type;


void LED_init(void);
extern const LedCfg_t ledCfg[NUM_OF_LEDS];
LED_enuErrorStatus_t LED_enuSetLedState(u8 Copy_u8LedName, u8 Copy_u8State);
#endif 