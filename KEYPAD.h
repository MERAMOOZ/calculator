
#define KEYPAD_H_
#define NOTPRESSED 0xff
#include "DIO.h"
void KEYPAD_Init();
unsigned char KEYPAD_u8GetButton(void);

