#include <stdio.h>
int main(int argc,const char *argv[])
{
    FILE* file;
    if( file = fopen("testFileExist.c","r") ) {
        fclose(file);
        puts("file exist");
    }
    else {
        puts("file not exist");
    }
    return 0;
}

