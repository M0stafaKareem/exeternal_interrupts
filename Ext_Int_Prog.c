#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../03-EXT_INTERRUPT/Ext_Int_Config.h"
#include "../03-EXT_INTERRUPT/Ext_Int_Register.h"

void ExtI0_vidEnable(){
#if SENSE_CONTROL== 0					/*case low level*/
	CLR_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

#elif SENSE_CONTROL== 1					/*case any change*/
	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

#elif SENSE_CONTROL== 2					/*case falling edge*/
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

#elif SENSE_CONTROL== 3					/*case rising edge*/
	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
#endif
	SET_BIT(GICR,GICR_INT0);

	SET_BIT(DDRD, 2);		/*configuring pin as pull up status*/
	SET_BIT(PORTD,2);

}

void ExtI1_vidEnable(){
#if SENSE_CONTROL== 0                    /*case low level*/
	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

	#elif SENSE_CONTROL== 1              /*case any change*/
	CLR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

	#elif SENSE_CONTROL== 2              /*case falling edge*/
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

#elif SENSE_CONTROL== 3                  /*case rising edge*/
	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);
#endif
	SET_BIT(GICR,GICR_INT1);

	SET_BIT(DDRD, 3);				/*configuring pin as pull up status*/
	SET_BIT(PORTD,3);
}

void ExtI2_vidEnable(){
#if SENSE_CONTROL == 2					/*case falling edge*/
	CLR_BIT(MCUCSR,MCUCSR_ISC2);
#elif SENSE_CONTROL == 3				/*case rising edge*/
	SET_BIT(MCUCSR,MCUCSR_ISC2);
#endif
	SET_BIT(GICR,GICR_INT2);

	SET_BIT(DDRB, 2);
	SET_BIT(PORTB,2);				/*configuring pin as pull up status*/
}



u8 ExtI0_vidReadInterruptFlag()    { return GET_BIT(GIFR,GIFR_INT0);}
u8 ExtI1_vidReadInterruptFlag()    { return GET_BIT(GIFR,GIFR_INT1);}
u8 ExtI2_vidReadInterruptFlag()    { return GET_BIT(GIFR,GIFR_INT2);}

void ExtI0_vidSetInterruptFlag()   { SET_BIT(GIFR,GIFR_INT0);}
void ExtI1_vidSetInterruptFlag()   { SET_BIT(GIFR,GIFR_INT1);}
void ExtI2_vidSetInterruptFlag()   { SET_BIT(GIFR,GIFR_INT2);}

void ExtI0_vidClearInterruptFlag() { CLR_BIT(GIFR,GIFR_INT0);}
void ExtI1_vidClearInterruptFlag() { CLR_BIT(GIFR,GIFR_INT1);}
void ExtI2_vidClearInterruptFlag() { CLR_BIT(GIFR,GIFR_INT2);}
