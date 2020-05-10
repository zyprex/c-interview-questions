#include <stdio.h>
int main(int argc,const char *argv[])
{
    printf( "sizeof void %d\n"
            "sizeof char %d\n"
            "sizeof short int %d\n"
            "sizeof int %d\n"
            "sizeof long int %d\n"
            "sizeof long long int %d\n"
            "sizeof float %d\n"
            "sizeof double %d\n"
            "sizeof long double %d\n",
            sizeof(void),         // 1
            sizeof(char),         // 1
            sizeof(short int),    // 2
            sizeof(int),          // 4
            sizeof(long int),     // 4
            sizeof(long long int),// 8
            sizeof(float),        // 4
            sizeof(double),       // 8
            sizeof(long double)); // 16
    return 0;
}

