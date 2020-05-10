#include <stdio.h>

void* my_memcpy(void* dst, const void* src, size_t len)
{
    if(NULL == dst || NULL == src) return NULL;

    void* ret = dst;

    if( dst <= src || (char*)src + len <= (char*)dst ){
        while( len-- ) {
            *(char*)dst = *(char*)src;
            dst++;
            src++;
        }
    }
    else{
        src = (char*)src + len - 1;
        dst = (char*)dst + len - 1;
        while( len-- ) {
            *(char *)dst = *(char *)src;
            dst--;
            src--;
        }
    }
    return ret;
}

int main(int argc, const char *argv[])
{
    char s1[] = "listInConst";
    char s2[20];
    my_memcpy(s2, s1, 11);
    printf( "%s\n", (char*)s2 );
    return 0;
}

