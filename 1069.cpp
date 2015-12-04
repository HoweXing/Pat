#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

char src[5],first[5],second[5],dst[5];

bool comp (const char &a, const char &b)
{
    return a>b;
}

bool notallsame(char *s)
{
    for(int i=1;i<strlen(s);++i)
    {
        if(s[i]!=s[i-1])
            return true;
    }
    return false;
}

char* sub(char *first, char *second)
{
    int n1=atoi(first);
    int n2=atoi(second);
    n1-=n2;
    char re[5];
    sprintf(re,"%04d",n1);
    return re;
}

int main()
{
    gets(src);
    if(strlen(src)!=4)
    {
        int n=atoi(src);
        sprintf(src,"%04d",n);
    }
    if(!notallsame(src))
    {
        printf("%04s - %04s = 0000\n",src,src);
        return 0;
    }
    while(1)
    {
        strcpy(first,src);
        strcpy(second,src);
        sort(first,first+4,comp);
        sort(second,second+4);
        strcpy(dst,sub(first,second));
        printf("%04s - %04s = %04s\n",first,second,dst);
        if(strcmp("6174",dst)==0)
            break;
        strcpy(src,dst);
    }
    return 0;
}
