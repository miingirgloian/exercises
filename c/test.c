#include <stdio.h>
int main(int argc, char *argv[])
{
    int n = 2,i=1;
    int a[2]={0},b[2]={0},c[2]={1,1};
    a[i&1]=b[i]=c[--i];
    printf("a[0]=%d,a[1]=%d\n",a[0],a[1]);
    printf("b[0]=%d,b[1]=%d\n",b[0],b[1]);
    printf("c[0]=%d,c[1]=%d\n",c[0],c[1]);
    return 0;
}
