#include <stdio.h>
#define MAXLEN 1024
int num[MAXLEN];

/*find max consecutive sum in num , whose length is len
 * the max consecutive sequence is from start to end
 * sum of the max consecutive sequence is returned
 * */
int find_mcs(const int *num, int len, int *start, int *end);

int main(int argc, char *argv[])
{
    int len=0, start, end, mcs;
    while(scanf("%d",num+len)!=EOF) len++;

    mcs = find_mcs(num, len, &start, &end);
    while(start<=end)
        printf("%d ",num[start++]);
    printf("\nSum is %d\n",mcs);
    
    return 0;
}

int find_mcs(const int *num, int len, int *start, int *end)
{
    int i, last, cur, mcs, maxsuf[2];
    /*compute the max suffix of each prefix of num*/
    mcs = maxsuf[0] = num[0];
    *start = *end = 0;
    for(i=1 ; i<len; i++){
        last = (i-1)&1;
        cur = i&1;
        if(maxsuf[last] <= 0){
            maxsuf[cur]= num[i];
            if(mcs < maxsuf[cur]) {
                mcs = maxsuf[cur];
                *start = *end = i;
            } 
        } else {
            maxsuf[cur] = maxsuf[last]+num[i];
            if(mcs < maxsuf[cur] ) {
                mcs = maxsuf[cur];
                *end = i;
            } 
        }
    }
    return mcs;
}
