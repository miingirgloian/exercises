#include <stdio.h>
#define MAXLEN 1024
int num[MAXLEN];
struct maxsuffix{
    int sum;
    int index;
} maxsuf[MAXLEN];
int fmcs(const int *num, struct maxsuffix *maxsuf, int n);

int main(int argc, char *argv[])
{
    int i = 0;
    while(scanf("%d",num+i)!=EOF) i++;

    int j = fmcs(num, maxsuf, i);
    for(i=maxsuf[j-1].index; i<=j; i++)
        printf("%d ",num[i]);
    printf("\n");
    
    return 0;
}
int fmcs(const int *num, struct maxsuffix *maxsuf, int n)
{
    int i,mcs_index = 0;
    /*compute the max suffix of each prefix of num*/
    maxsuf[0].sum = num[0];
    maxsuf[0].index = 0;
    for(i=1 ; i<n; i++){
        if(maxsuf[i-1].sum <= 0){
            maxsuf[i].sum = num[i];
            maxsuf[i].index = i;
        } else {
            maxsuf[i].sum = maxsuf[i-1].sum+num[i];
            maxsuf[i].index = maxsuf[i-1].index;
        }

        if(maxsuf[mcs_index].sum<maxsuf[i].sum) mcs_index = i;
    }

    return mcs_index;
}
