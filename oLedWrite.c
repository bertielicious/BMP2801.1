#include "config.h"
#include "i2cStart.h"
#include "i2cWrite.h"
#include "i2cStop.h"
void oLedWrite(uchar oLedAdd, uchar ctrlByte, uchar dataByte)
{
    i2cStart();
    i2cWrite(oLedAdd);                 
    i2cWrite(ctrlByte);      // 0x00 = command, 0x40 = display data          
    i2cWrite(dataByte);                 
    i2cStop();
}
