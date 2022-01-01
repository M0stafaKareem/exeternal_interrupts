#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

void ExtI0_vidEnable();
void ExtI1_vidEnable();
void ExtI2_vidEnable();

u8 ExtI0_vidReadInterruptFlag();
u8 ExtI1_vidReadInterruptFlag();
u8 ExtI2_vidReadInterruptFlag();

void ExtI0_vidSetInterruptFlag();
void ExtI1_vidSetInterruptFlag();
void ExtI2_vidSetInterruptFlag();

void ExtI0_vidClearInterruptFlag();
void ExtI1_vidClearInterruptFlag();
void ExtI2_vidClearInterruptFlag();

#endif
