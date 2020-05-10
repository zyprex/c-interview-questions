#include <stdio.h>


/********************************************************************
 * @fn      str_count
 * @brief   计算子字符串出现的次数
 * @param   str      - 目标字符串
 *          char_str - 子字符串
 * @return  子字符串出现的次数
 *******************************************************************/
int substrCount(char* str, char* char_str)
{
    int i, j, k, num=0;
    for( i = 0; str[i] != '\0'; i+=1 ) {
        for( j = i, k = 0; char_str[k] == str[j]; k++, j++ ) {
            if( char_str[k+1] == '\0' ) {
                num++;
                break;
            }
        }
    }
    return num;
}

int main(int argc, const char *argv[])
{
    printf("%d", substrCount("12312312312311", "1") );
    return 0;
}

