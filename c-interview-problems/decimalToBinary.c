#include <stdio.h>
#include <math.h>

/********************************************************************
 * @fn      decimalToBinary
 * @brief   convert decimal to binary string upto k-precision after
 *          decimal point
 * @param   num - decimal numder
 *          k   - precision
 * @return  none
 *******************************************************************/
void decimalToBinary(double num, int k)
{
    int Integral = num;
    double Fractional = num - Integral;
    int i, temp;
    for( i = -1, temp = Integral; temp; temp /= 2, i += 1);
    while( i >= 0 ) {
        if(Integral >= (int)pow(2, i)) {
            Integral -= (int)pow(2, i);
            printf( "1" );
        }
        else {
            printf( "0" );
        }
        i--;
    }
    printf( "." );
//     while( Integral ) {
//         int rem = Integral % 2;
//         printf( "%d\n", rem );
//         Integral /= 2;
//     }
    while( k-- ) {
        Fractional *= 2;
        int fract_bit = Fractional;
        if( fract_bit == 1 ) {
            Fractional -= 1;
            printf( "1" );
        }
        else {
            printf( "0" );
        }
    }
    putchar(10);
}


int main(int argc,const char *argv[])
{
    decimalToBinary(123.58876, 18);
    return 0;
}

