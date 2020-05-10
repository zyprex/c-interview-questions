#include <stdio.h>
#include <assert.h>
#define NDEBUG // 使用assert() 需注释此句

int main( int argc, char *argv[] )
{
    assert(0); // 程序不该运行到此处
    return 0;
}
