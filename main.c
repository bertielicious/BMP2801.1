/*
 * File:   main.c
 * Author: User
 *
 * Created on 06 December 2021, 14:11
 */


#include "config.h"
#include "configOsc.h"
#include "configPorts.h"
#include "configEUSART.h"
#include "configBaud.h"
#include "configI2C.h"
#include "i2cStart.h"
#include "i2cWrite.h"
#include "i2cRead.h"
#include "i2cReStart.h"
#include "i2cStop.h"
#include "oLedWrite.h"
#include "configSH1106.h"
#include "setPageAddress.h"
#include "setColumnAddress.h"
#include "clearSH1106.h"
#include "selectDigit.h"
#include "split0To99.h"
#include "write8x8ToOled.h"
#include "configBMP280.h"
void main(void) 
{
    static uint8_t temp_xlsb, temp_lsb, temp_msb;
    static uint8_t press_xlsb, press_lsb, press_msb;
    
    configOsc();
    configPorts();
    configEUSART();
    configBaud();
    configI2C();
    printf("Hola\n");
    configSH1106();
    __delay_ms(100);
    clearSH1106();          // writes 0x00 to each column from 0 to 131, of each page 0 to 7 of the oled display, to clear random data held in display RAM
    configBMP280();
    
    
   /***************burst read read pressure and temp from reg address 0xf7 to 0xfc************************/
    i2cStart();     // issue start condition to begin i2c exchange
    i2cWrite(0xec); // send slave address write mode
    i2cWrite(0xfa); // send device id register address
    i2cReStart();   // repeated start condition generated
    //i2cStop();
    //i2cStart();
    i2cWrite(0xed); // send slave address read mode
    temp_msb = i2cRead(0); // burst read the temp_msb data byte from register 0xfa of the slave 
    temp_lsb = i2cRead(0); // burst read the temp_lsb data byte from register 0xfb of the slave 
    temp_xlsb = i2cRead(1); // burst read the temp_xlsb data byte from register 0xfc of the slave 
    // __delay_ms(5);
     i2cStop();      // issue the stop condition so that master can communicate to another i2c device on the bus
     
     
  //  printf("pmsb %d plsb %d  pxlsb %d\n", press_msb, press_lsb, press_xlsb);
    printf("tmsb %d tlsb %d  txlsb %d\n", temp_msb, temp_lsb, temp_xlsb);
    
    while(1)
    {
        DIAGNOSTIC_LED = HI;
        __delay_ms(100);
        DIAGNOSTIC_LED = LO;
        __delay_ms(100);
    }
}
