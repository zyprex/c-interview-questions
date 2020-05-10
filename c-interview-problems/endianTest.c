#include <stdio.h>
#include <stdint.h>
#define BIGENDIAN 1
#define LITTLEENDIAN 2

int endianTest(void)
{
    union {
        int i;
        char ch;
    }test;
    test.i = 0x12345678;
    return test.ch == 0x78 ? LITTLEENDIAN : BIGENDIAN;
}

int endianTest2()
{
    uint32_t endian = 0x12345678;
    return (((uint8_t)endian == 0x78) ? LITTLEENDIAN : BIGENDIAN);
}


int main(void)
{
    endianTest() == BIGENDIAN ? 
        printf("BIGENDIAN\n") : printf("LITTLEEN\n");
    endianTest2() == BIGENDIAN ?
        printf("BIGENDIAN\n") : printf("LITTLEEN\n");
    return 0;
}
