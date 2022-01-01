#ifndef EXT_INT_CONFIG
#define EXT_INT_CONFIG

#define LOW_LEVEL 0
#define ANY_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

#define SENSE_CONTROL RISING_EDGE

#define PORTB	 *(volatile u8*)0x38    /*EXT_Interrupt 2 pin address*/
#define DDRB 	 *(volatile u8*)0x37

#define PORTD	 *(volatile u8*)0x32	/*EXT_Interrupt 0 & 1 pins address*/
#define DDRD 	 *(volatile u8*)0x31


#endif
