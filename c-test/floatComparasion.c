/*
 * test float compare
 */
#include <stdio.h>
int main(int argc, const char *argv[])
{
    float fnum1 = 0.1;
    float fnum2 = 0.2;
    fnum1 < fnum2 ? puts("true") : puts("false");

    fnum1 = 0.3;
    fnum1 < 0.4   ? puts("true") : puts("false");

    float fnum3 = 0.3;
    fnum1 == fnum3   ? puts("true") : puts("false");
    fnum1 == 0.3     ? puts("true") : puts("false");       // false
    fnum1 == 0.3f    ? puts("true") : puts("false");
    ((double)fnum1) == 0.3 ? puts("true") : puts("false"); // false

    long double dnum1 = 0.4;
    dnum1 == 0.4     ? puts("true") : puts("false");
    return 0;
}

