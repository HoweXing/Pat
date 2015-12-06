#include <stdio.h>

long long int n1,n2,n3,sum;
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld%lld%lld",&n1,&n2,&n3);
        sum=n1+n2;
        printf("Case #%d: ",i);
        if(n1>0&&n2>0&&sum<=0)
            printf("true\n");
        else if(n1<0&&n2<0&&sum>=0)
            printf("false\n");
        else if(sum>n3)
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}
