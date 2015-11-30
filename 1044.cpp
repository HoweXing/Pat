#include <stdio.h>
#define INF 0x7f7f7f7f
using namespace std;

int n,m;
int chain[100001];
int startpos[100001],endpos[100001],top=-1;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&chain[i]);
    int minpay=INF,p=n;
    int head=1,rare=1,sum=chain[1];
    while(head>=rare&&head<=n)
    {
        //printf("## %d %d sum %d\n",rare,head,sum);
        if(sum>=m && sum<minpay)
        {
            top=-1;
            minpay=sum;
            startpos[++top]=rare;
            endpos[top]=head;
        }
        else if(sum==minpay)
        {
            startpos[++top]=rare;
            endpos[top]=head;
        }
        if(sum>=m)
        {
            sum-=chain[rare];
            ++rare;
            if(rare>head)
            {
                ++head;
                sum+=chain[head];
            }
        }
        else
        {
            ++head;
            sum+=chain[head];
        }
    }
    for(int i=0;i<=top;++i)
        printf("%d-%d\n",startpos[i],endpos[i]);
    return 0;
}
