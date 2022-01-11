/*return the address of the first array selected to main() using an int pointer*/

#include "config.h"
int*  selectDigit(uchar digit)
{
    static const int zero[8] = {0x00,0x7c,0x82,0x82,0x82,0x78,0x00,0x00};   // static definition as address of array passed back to caller
    static const int uno[8] = {0x00,0x00,0x88,0x84,0x82,0xfe,0x80,0x00};    // after the function has been left. static effectively keeps the 
    static const int dos[8] = {0x00,0x00,0xc4,0xa2,0x92,0x8a,0x86,0x00};    // the array address alive even when we have left the function
    static const int treis[8] = {0x00,0x00,0x42,0x82,0x92,0xaa,0x66,0x00};
    static const int cuatro[8] = {0x00,0x00,0x30,0x28,0x24,0xf2,0x20,0x00};
    static const int cinco[8] = {0x00,0x00,0x5e,0x92,0x8a,0x8a,0x72,0x00};
    static const int seis[8] = {0x00,0x00,0x38,0x54,0x92,0x92,0x60,0x00};
    static const int siete[8] = {0x00,0x00,0xc6,0x22,0x12,0x0a,0x06, 0x00};
    static const int ocho[8] = {0x00,0x60,0x96,0x9a,0x92,0x9a,0x96,0x60};
    static const int nueve[8] = {0x00,0x00,0x0c,0x92,0x52,0x24,0x18,0x00};
    static const int F[8] = {0x00, 0xfe, 0x11,0x11,0x11,0x01,0x00,0x00};
    static const int T[8] = {0x00, 0x00, 0x02,0x02,0xfe,0x02,0x02,0x00};
    switch (digit)
    {
        case 0:
            return zero;    // return a pointer to the address of zero or uno or...nueve arrays
            break;
            
        case 1:
            return uno;
            break;
            
        case 2:
            return dos;
            break;
            
        case 3:
            return treis;
            break;
            
        case 4:
            return cuatro;
            break;
            
        case 5:
            return cinco;
            break;
            
        case 6:
            return seis;
            break;
            
        case 7:
            return siete;
            break;
            
        case 8:
            return ocho;
            break;
            
        case 9:
            return nueve;
            break;
            
        case 'F':
            return F;
            break;
            
        case 'T':
            return T;
            break;
            
    }
}
