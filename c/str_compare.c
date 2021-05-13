/*
 *9月8日，腾讯面试题：
 *假设两个字符串中所含有的字符和个数都相同我们就叫这两个字符串匹配，
 * 比如：abcda和adabc,由于出现的字符个数都是相同，只是顺序不同，
 * 所以这两个字符串是匹配的。要求高效！
 */
#include <stdio.h>
#include <assert.h>

int compare(const char *, const char *);

int main(int argc, char *argv[])
{
    char p[512],q[512];
    scanf("%s %s",p,q);

    if(!compare(p,q))
        printf("Same!\n");
    else 
        printf("Different!\n");

    return 0;
}

int compare(const char *s1, const char *s2)
{
    assert(s1!=NULL && s2!=NULL);

    int count[512] = {0}, sum = 0;

    while(*s1 != '\0'){
        count[*s1-'\0']++;
        s1++;
        sum++;
    }
    while(*s2 != '\0'){
        if(count[*s2-'\0']){
            count[*s2-'\0']--;
            s2++;
            sum--;
        } else return 1;
    }

    if(sum) return 1;
    return 0;
}
