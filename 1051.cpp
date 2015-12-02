#include <stdio.h>
#include <string.h>

int m,n,k;
int stack[1001],top=0,seq[1001];

int main()
{
    scanf("%d%d%d",&m,&n,&k);
    for(int i=0;i<k;++i)
    {
        top=0;
        bool flag=true;
        int maxnum=0,tmp;
        memset(stack,0,sizeof(int)*1001);
        for(int j=0;j<n;++j)
            scanf("%d",&seq[j]);
        for(int j=0;j<n;++j)
        {
            if(seq[j]<stack[top])
            {
                flag=false;
                break;
            }
            else if(seq[j]==stack[top])
                --top;
            else
            {
                for(int l=maxnum+1;l<seq[j];++l)
                    stack[++top]=l;
                maxnum=seq[j];
                if(top+1>m)
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag && top==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
