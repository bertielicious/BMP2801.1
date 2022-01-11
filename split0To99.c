/*This fuction takes an integer from 0 to 99
 and splits it into two numbers, tens and units eg 37 would be split into
 num.tens = 3 and num.units = 7. It returns these two values using a data structure variable*/
#include "config.h"

splitUchar split0To99(uchar number)
{
    splitUchar num;         // create a local struct variable of custom type splitUchar (defined in config.h)
    num.tens = number/10;   // calculate the tens number, and save it in the structure member num.tens
    num.units = number%10;  // calculate the units number, and save it in the structure member num.units
    return num;             // return the customer struct variable num to the calling function, which will then display them on the oLed display
}
