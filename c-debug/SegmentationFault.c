/*
    段错误的原因:
    1. 坏指针
    2. 堆栈空间用尽
*/
#include <stdio.h>
int main(int argc, const char *argv[])
{
    // ulimit -c unlimited
    // gdb executable-file core-file
    // 用GDB的list命令可以查看附近的源代码。 l 5

//     int *a = NULL;
//     *a = 0x1;
    
    return 0;
}

