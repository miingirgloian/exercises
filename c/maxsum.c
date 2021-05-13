/*POJ 2479: Maxmimum Sum*/
#include <stdio.h>
#define MAXSIZ (1024*64)
int num[MAXSIZ],mcssuf[MAXSIZ],mcspre[MAXSIZ];

int maxsum(int m);

int main(int argc, char *argv[])
{
    int n,m,i;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        for(i=0; i<m; i++){
            scanf("%d",num+i);
        }
        printf("%d\n",maxsum(m));
    }
    return 0;
}

int maxsum(int m)
{
    int i, l, r, max[2];
    max[0] = mcspre[0] = num[0];
    for(i=1; i<m; i++){
        l = (i-1)&1;
        r = i&1;
        if(max[l]>0) max[r] = max[l]+num[i];
        else max[r] = num[i];

        if(max[r]>mcspre[i-1]) mcspre[i]=max[r];
        else mcspre[i]=mcspre[i-1];
    }

    i--;
    max[i&1] = mcssuf[i] = num[i]; 
    do{
        l = (i-1)&1;
        r = i&1;
        if(max[r]>0) max[l] = max[r]+num[i-1];
        else max[l] = num[i-1];

        if(max[l]>mcssuf[i]) mcssuf[i-1]=max[l];
        else mcssuf[i-1]=mcssuf[i];
    }while(--i);

    max[0]=mcspre[0]+mcssuf[1];
    for(i=1; i<m-1; i++){
        if(max[0]<mcspre[i]+mcssuf[i+1])
            max[0]=mcspre[i]+mcssuf[i+1];
    }

    return max[0];
}
