#include <stdio.h>
#include <iostream>
#include <vector>
#define INF 0x7f7f7f7f
using namespace std;

int Map[501][501],Cost[501][501];
int visited[501];
int n,m,s,d;
int mindistance,mincost=INF;
int path[501];
vector<int> p;

int dijkstra()
{
    int lowcost[501],inv[501];
    for(int i=0;i<n;++i)
    {
        lowcost[i]=Map[s][i];
        inv[i]=0;
    }
    inv[s]=1;
    for(int i=1;i<n;++i)
    {
        int u=-1,mindist=INF;
        for(int j=0;j<n;++j)
        {
            if(inv[j]==0 && lowcost[j]<mindist)
            {
                mindist=lowcost[j];
                u=j;
            }
        }
        inv[u]=1;
        for(int j=0;j<n;++j)
        {
            if(inv[j]==0 && mindist+Map[u][j]<lowcost[j])
            {
                lowcost[j]=mindist+Map[u][j];
            }
        }
    }
    return lowcost[d];
}

void DFS(int cur, int dist, int cost, int k)
{
    if(cur==d && dist==mindistance)
    {
        if(cost<mincost)
        {
            mincost=cost;
            p.clear();
            for(int i=0;i<k;++i)
                p.push_back(path[i]);
        }
        return;
    }
    if(dist>=mindistance)
        return;
    for(int i=0;i<n;++i)
    {
        if(visited[i]==0 && Map[cur][i]<INF)
        {
            visited[cur]=1;
            dist+=Map[cur][i];
            cost+=Cost[cur][i];
            path[k]=i;
            DFS(i,dist,cost,k+1);
            cost-=Cost[cur][i];
            dist-=Map[cur][i];
            visited[cur]=0;
        }
    }
}

int main()
{
    cin>>n>>m>>s>>d;
    for(int i=0;i<n;++i)
    {
        visited[i]=0;
        for(int j=0;j<n;++j)
        {
            Map[i][j]=INF;
            Cost[i][j]=INF;
        }
    }
    for(int i=0;i<m;++i)
    {
        int city1,city2,dist,cost;
        cin>>city1>>city2>>dist>>cost;
        Map[city1][city2]=dist;
        Map[city2][city1]=dist;
        Cost[city1][city2]=cost;
        Cost[city2][city1]=cost;
    }
    mindistance=dijkstra();
    DFS(s,0,0,0);
    printf("%d",s);
    for(int i=0;i<p.size();++i)
    {
        printf(" %d",p[i]);
    }
    printf(" %d %d\n",mindistance,mincost);
    return 0;
}
