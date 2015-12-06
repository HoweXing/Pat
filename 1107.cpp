#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>>
using namespace std;

int Map[2001][2001],visited[2001];
int n,total,maxhb=-1,cnt=0;

bool comp(const int a, const int b)
{
    return a>b;
}

void DFS(int cur)
{
    visited[cur]=1;
    if(cur<=n)
        ++cnt;
    for(int i=1;i<=total;++i)
    {
        if(Map[cur][i]==1 && visited[i]==0)
            DFS(i);
    }
}

int main()
{
    scanf("%d",&n);
    char buf[10];
    for(int i=1;i<=n;++i)
    {
        scanf("%s",buf);
        buf[strlen(buf)-1]='\0';
        int num=atoi(buf);
        int hb;
        for(int j=0;j<num;++j)
        {
            scanf("%d",&hb);
            Map[i][hb+n]=1;
            Map[hb+n][i]=1;
            if(maxhb<hb)
                maxhb=hb;
        }
    }
    total=n+maxhb;
    vector<int> v;
    for(int i=1;i<=total;++i)
    {
        cnt=0;
        if(visited[i]==0)
            DFS(i);
        if(cnt>0)
            v.push_back(cnt);
    }
    sort(v.begin(),v.end(),comp);
    printf("%d\n",v.size());
    for(int i=0;i<v.size();++i)
    {
        if(i>0)
            printf(" ");
        printf("%d",v[i]);
    }
    return 0;
}
