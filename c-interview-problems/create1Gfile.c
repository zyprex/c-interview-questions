/*
 * use c language to create 1G file
 */
#include <stdio.h>

int main(int argc,const char *argv[])
{
    int i;
    FILE* fp;
    fp = fopen("testFile1G.txt", "w");
    for( i = 0; i < (1024*1024*1024); i += 1 ) {
        fprintf( fp, "C" );
    }
    fclose(fp);
    return 0;
}

