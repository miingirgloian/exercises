#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZ 1024

char p[MAXSIZ],q[MAXSIZ],s[MAXSIZ];
int tab[MAXSIZ][MAXSIZ];

int lcs(const char *p, const char *q);

int main(int argc, char *argv[])
{
    while(scanf("%s %s",p,q)!=EOF){
        printf("%d\n",lcs(p,q));
    }
    return 0;
}

int lcs(const char *p, const char *q)
{
    int m = strlen(p), n = strlen(q);
    int flag = 0, i, j;

    for(i=0; i<n; i++){
        if(!flag && p[0]==q[i]) flag=1;
        tab[0][i] = flag;
    }
    for(i=1,flag=tab[0][0]; i<m; i++){
        if(!flag && q[0]==p[i]) flag=1;
        tab[i][0] = flag;
    }

    for(i=1; i<m; i++)
        for(j=1; j<n; j++){
            if(p[i]==q[j]) tab[i][j]=tab[i-1][j-1]+1;
            else if(tab[i-1][j]>tab[i][j-1])
                tab[i][j]=tab[i-1][j];
            else 
                tab[i][j]=tab[i][j-1];
        }
    return tab[m-1][n-1];
}
