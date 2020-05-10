#include <stdio.h>

char* my_strcpy(char *str_dest, char *str_src)
{
    char* tmp = str_dest;
    while ((*str_dest++ = *str_src++) != '\0');
    return tmp;
}

int main( int argc, char *argv[] )
{
    char dest[19] = "llllllllllllllllll";
    char src[20] = "copycopycopy";
    my_strcpy(dest, src);
    printf( "%s ", dest );
    return 0;
}
