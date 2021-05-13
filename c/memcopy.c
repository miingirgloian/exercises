#include <stdio.h>
#include <assert.h>

void *memcopy(void *dest, const void *src, size_t n);

int main(int argc, char *argv[])
{
    int a = 0x1278, b;
    memcopy(&a, &a, sizeof(a));
    printf("a=%d,b=%d\n",a,b);

    return 0;
}

void *memcopy(void *dest, const void *src, size_t n)
{
    assert(dest!=NULL && src!=NULL);

    char *pdst = (char *)dest;
    const char *psrc = (const char *)src;

    assert(!(pdst<=psrc && pdst+n>psrc));
    assert(!(pdst>=psrc && psrc+n>pdst));

    while(n--){
        *pdst = *psrc;
        pdst++;
        psrc++;
    }
    return dest;
}
