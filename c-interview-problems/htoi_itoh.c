// 编写函数 htoi(s)，把由十六进制数字组成的字符串（包含可选的前缀 0x 或 0X）转换为与之等价的整型值。字符串中允许包含的数字包括：0～9、a～f 以及 A～F
#include <stdio.h>
#include <string.h>
#include <math.h>


/********************************************************************
 * @fn      htoi
 * @brief   hexadecimal convert to integer
 * @param   hexstr - string of hexadecimal
 * @return  int val
 *******************************************************************/
int htoi(char* hexstr)
{
    char* start = hexstr - 1;
    char* end = hexstr;
    int val = 0, i = 0;
    if( *start == '0' ) {
        if( *(start+1) == 'X'  || *(start+1) == 'x' ) {
            start += 2;
        }
    }
    while( *(end+1) != '\0' ) end++; 
    while( start != end ) {
        int mut = pow(16, i);
        switch( *end ) {
            case 'A': case 'a': val += mut * 10; break;
            case 'B': case 'b': val += mut * 11; break;
            case 'C': case 'c': val += mut * 12; break;
            case 'D': case 'd': val += mut * 13; break;
            case 'E': case 'e': val += mut * 14; break;
            case 'F': case 'f': val += mut * 15; break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                val += mut * (*end - '0');
            default:
                break;
        }
        i++;
        end--;
    }
    printf( "val:%d\n", val );
    return val;
}

void itoh(int num)
{
    char s[]="0123456789abcdef";
    char buf[48];
    int i = 0;
    while( num ){
        int rem = num % 16;
        buf[i++] = s[rem];
        num /= 16;
    }
    i--;
    while(i >= 0)
        printf( "%c", buf[i--] );
    putchar(10);
}

int main(int argc, const char *argv[])
{
    char hex[] = "0XaB";
    htoi(hex);
    itoh(171);
    return 0;
}

