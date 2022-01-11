#include "config.h"
void i2cCheckBusIdle(void)
{
   while((SSPCON2 & 0b00011111) || (SSPSTAT & 0b00000100)); // wait here until bus is idle (SDA = SCL = 1)
}
