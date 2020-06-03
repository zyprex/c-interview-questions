#include <stdio.h>
/********************************************************************
 * @fn      strinstr
 * @brief   searches for a given occurrence of a string
 * @param   src - the string whose content is searched
 *          ind - the string to search
 * @return  1 - the string was found
 *          0 - the string was not found
 *******************************************************************/
int strinstr(char* src, char* ind)
{
    if( !*src && !*ind ) {
        return 1;
    }
    int i, j, k;
    for( i = 0; *(src+i) != '\0' ; i+=1 ) {
        if( *(src+i) == *(ind) ) {
            k = 1;
            for( j = 0; *(ind+j) != '\0'; j+=1 ) {
                if( *(src+i+j) != *(ind+j) ) {
                    k = 0;
                    break;
                }
            }
        }
    }
    return k;
}



int main(int argc,const char *argv[])
{
    printf( "%d\n", strinstr("", "3") );
    return 0;
}

