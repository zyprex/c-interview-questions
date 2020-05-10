#include<stdio.h>

union {
    char a[10];
    int i;
} u;

int main(void)
{
#if defined(__GNUC__)
# if defined(__i386__)
    /* Enable Alignment Checking on x86 */
    __asm__("pushf\norl $0x40000,(%esp)\npopf");
# elif defined(__x86_64__)
    /* Enable Alignment Checking on x86_64 */
    __asm__("pushf\norl $0x40000,(%rsp)\npopf");
# endif
#endif

    int *p = (int *) (&(u.a[1]));

    /**
     * p中未对齐的地址将会引起总线错误，
     * 因为数组和int的联合确保了a是按照int的4字节来对齐的，
     * 所以“a+1”肯定不是int对齐的
     */
    *p = 17;
    printf("%d %p %p %p\n", *p, &(u.a[0]), &(u.a[1]), &(u.i));
    printf("%lu %lu\n", sizeof(char), sizeof(int));
    return 0;
}
/*
https://juejin.im/post/5afd8d00f265da0b745261e0
 总线错误几乎都是由于未对齐的读或写引起的。它之所以称为总线错误，是因为出现未对齐的内存访问请求时，被阻塞(block)的组件就是地址总线。对齐(alignment)的意思就是数据项只能存储在地址是数据项大小的整数倍的内存上。在现代的计算机架构中，尤其是RISC架构，都需要数据对齐，因为与任意的对齐有关的有关的额外逻辑会使整个内存系统更大且更慢。通过迫使每个内存访问局限在一个cache行或一个单独的页面内，可以极大地简化并加速如cache控制器和内存管理单元(MMU)这样的硬件。
我们用地址对齐这个术语来陈述这个问题，而不是直截了当地说是禁止内存跨页访问，但它们说但是同一回事。例如，访问一个8字节的double数据时，地址只允许是8的整数倍。所以一个double数据可以存储于地址24，地址8008或32768，但不能存储于地址1006(因为它无法被8整除)。
页和cache的大小都是经过精心设计的，这样只要遵守对齐规则就可以保证一个原子数据项不会跨过一个页或cache块的边界。

*/
