#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZ 1024

char p[MAXSIZ],q[MAXSIZ],s[MAXSIZ];

void lcs(const char *p, const char *q, char *s);

int main(int argc, char *argv[])
{
    scanf("%s %s",p,q);
    lcs(p,q,s);
    printf("Longest Common Sequence:%s\n",s);
    return 0;
}

void lcs(const char *p, const char *q, char *s)
{
    assert(p!=NULL && q!=NULL && s!=NULL);

    int m = strlen(p), n = strlen(q);
    assert(m!=0 && n!=0);
    int tab[MAXSIZ][MAXSIZ];
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

    int k = 0;
    for(i=m-1,j=n-1; i>0&&j>0;){
        if(p[i]==q[j]){
            s[k++]=p[i];
            i--;
            j--;
        } else if(tab[i-1][j]>tab[i][j-1])
            i--;
        else j--;
    }
    if(tab[i][j])
    if(!i) s[k++] = p[i];
    else s[k++] = q[j];

    s[k]='\0';

    char c;
    for(i=0,j=k-1; i<j; i++,j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
