#include <stdio.h>

int rec[100001];
int bets[100001],pep=0;

int main()
{
    for(int i=1;i<100001;++i)
        rec[i]=0;
    int n,tmp;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&tmp);
        rec[tmp]++;
        bets[pep++]=tmp;
    }
    int k=-1;
    for(int i=0;i<n;++i)
    {
        if(rec[bets[i]]==1)
        {
            k=bets[i];
            break;
        }
    }
    if(k==-1)
        printf("None\n");
    else
        printf("%d\n",k);
}
