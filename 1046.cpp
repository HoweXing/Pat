#include <stdio.h>

int n,m;
int dist[100001],distsum[100001]={0};

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&dist[i]);
        if(i>1)
            distsum[i]=distsum[i-1]+dist[i-1];
    }
    scanf("%d",&m);
    for(int i=0;i<m;++i)
    {
        int s,e;
        scanf("%d%d",&s,&e);
        if(s>e)
        {
            s^=e;
            e^=s;
            s^=e;
        }
        if(s==e)
            printf("0\n");
        else
        {
            int dist1=distsum[e]-distsum[s];
            int dist2=distsum[n]-distsum[e]+dist[n]+distsum[s];
            printf("%d\n",(dist1<dist2)?dist1:dist2);
        }
    }
    return 0;
}
