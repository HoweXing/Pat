#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buf[10000];
int n;
double tmp,sum=0;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%s",buf);
        buf[10]='\0';
        tmp=atof(buf);
        sum+=tmp*(i+1)*(n-i);
    }
    printf("%.2f\n",sum);
    return 0;
}
