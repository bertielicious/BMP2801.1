#include "config.h"
#include "readBMP280.h"
#include "writeBMP280.h"
#include "setPageAddress.h"
#include "setColumnAddress.h"
#include "split0To99.h"
#include "write8x8ToOled.h"
void configBMP280(void)
{
    uint8_t returnedValue;
    returnedValue = readBMP280(CHIP_ID_REG);// chip ID read should be d'88
    if(returnedValue == FALSE)
    {
        setPageAddress(4);
        setColumnAddress(58);
        write8x8ToOled('F');
    }
    else
    {
        setPageAddress(4);
        setColumnAddress(58);
        write8x8ToOled('T');
        
        writeBMP280(RESET_REG, 0xB6);   // software reset of BMP280
       
        
       // if((STATUS_REG & 0x09) == 0)
       // {
            writeBMP280(CTRL_MEAS_REG, 0x2F);
            
            writeBMP280(CONFIG_REG, 0x0C);
       // }
    }
}
