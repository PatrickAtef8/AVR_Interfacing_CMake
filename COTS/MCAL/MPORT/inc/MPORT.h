#ifndef MPORT_H_
#define MPORT_H_

#include "STD_TYPES.h"
#include "MPORT_cfg.h"

// Define pins for Port A
#define PINA0  0x00
#define PINA1  0x01
#define PINA2  0x02
#define PINA3  0x03
#define PINA4  0x04
#define PINA5  0x05
#define PINA6  0x06
#define PINA7  0x07

// Define pins for Port B
#define PINB0  0x10
#define PINB1  0x11
#define PINB2  0x12
#define PINB3  0x13
#define PINB4  0x14
#define PINB5  0x15
#define PINB6  0x16
#define PINB7  0x17

// Define pins for Port C
#define PINC0  0x20
#define PINC1  0x21
#define PINC2  0x22
#define PINC3  0x23
#define PINC4  0x24
#define PINC5  0x25
#define PINC6  0x26
#define PINC7  0x27

// Define pins for Port D
#define PIND0  0x30
#define PIND1  0x31
#define PIND2  0x32
#define PIND3  0x33
#define PIND4  0x34
#define PIND5  0x35
#define PIND6  0x36
#define PIND7  0x37



#define MPORT_OUTPUT 1
#define MPORT_INPUT 0

typedef enum
{
	MPORT_OK=0x00,
	MPORT_NOK,
	MPORT_INVALID_PIN,
	MPORT_INVALID_PORT,
	MPORT_NULL_PTR,
	}MPORT_enuErrorStatus_t;


typedef enum
{
	MPORT_PORTA=0x00,
	MPORT_PORTB,
	MPORT_PORTC,
	MPORT_PORTD
}MPort_Num;


typedef enum
{
	MPORT_PIN0=0x00,
	MPORT_PIN1,
	MPORT_PIN2,
	MPORT_PIN3,
	MPORT_PIN4,
	MPORT_PIN5,
    MPORT_PIN6,
    MPORT_PIN7,
	MPORT_TOTAL_PIN	
	}MPORT_Pin_Num;

typedef enum{ 
	 OUTPUT,
	 INPUT_PULLUP,
	 INPUT_PULLDOWN
}MPORT_PinStatus;


typedef enum
{
	PORT_OUTPUT = 0xFF,
	PORT_INPUT = 0x00,
}MPORT_PortStatus;



void MPORT_vInit(void);
extern const MPORT_PinStatus PinCfg_array[MPORT_TOTAL_PIN];
MPORT_enuErrorStatus_t MPORT_enuSetPinConfigration(MPort_Num Copy_enuPortNum,MPORT_Pin_Num Copy_enuPinNum,MPORT_PinStatus Copy_enuConfigration);
MPORT_enuErrorStatus_t MPORT_enuSetPortConfigration(MPort_Num Copy_enuPortNum,MPORT_PortStatus Copy_enuConfigration);

MPORT_enuErrorStatus_t MPORT_enuSetPinDirection( u8 Copy_enuPinNum  ,  u8 Copy_enuPinDirection  );
MPORT_enuErrorStatus_t MPORT_enuSetPinMode( u8 Copy_enuPinNum  ,  MPORT_PinStatus Copy_enuPinMode );

#endif /* MPORT_H_ */