/*
 * find longest numeric string
 */
#include <stdio.h>
#include <ctype.h>

/********************************************************************
 * @fn      maxNumStr
 * @brief   return longest numeric string and save it
 * @param   outputstr - store numeric string
 *          inputstr  - source string
 * @return  (int) : the length of longest numeric string
 *******************************************************************/
int maxNumStr(char* outputstr, char* inputstr)
{
    int mxlen = 0;
    int i=0;
    int post[2];
    int post_t[2];
    while(*inputstr) {
        if( !isdigit(*inputstr) && isdigit(*(inputstr+1)) ) {
            post[0] = i;
        }
        if( isdigit(*inputstr) && !isdigit(*(inputstr+1)) ) {
            post[1] = i;
        }
        if( post[1] - post[0] > mxlen  ) {
            post_t[0] = post[0];
            post_t[1] = post[1];
            mxlen = post[1] - post[0];
        }
        i++;
        inputstr++;
    }
    inputstr -= i;
    sprintf(outputstr, "%.*s", mxlen, inputstr + post_t[0] + 1 );
    printf("%s\n", outputstr); // show result
    return mxlen;
}

// "abcd12345ed125ss123456789" 9 "123456789"
int main(int argc,const char *argv[])
{
    char* str = "abcd1234567890ed125ss123456789";// 9 "123456789"
    char* out;
    printf("%d\n", maxNumStr(out, str));
    return 0;
}

