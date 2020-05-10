#include <stdio.h>

/********************************************************************
 * @fn      bitset
 * @brief   set binary position 1 or 0
 * @param   num - binary number
 *          pos - position 1~n
 *          c   - 1 set 1, 0 set 0
 * @return  (int) : changed number
 *******************************************************************/
int bitset(int num, int pos, int c){
  return c ?
      num | (1<<(pos-1)) : num & ~(1<<(pos-1));
}

int main(int argc, const char *argv[])
{
    printf( "%d\n", bitset(3,1,0) );
    return 0;
}

