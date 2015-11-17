#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int Map[501][501]={-1};
int n,m,from,to;
vector<int> teams;
int visited[501];
int mindist=99999999,maxnum=0;
int cnt=0;

void dfs(int cur,int dist,int num)
{
    if(cur==to)
    {
        if(dist<mindist)
        {
            mindist=dist;
            cnt=1;
            maxnum=num;
        }
        else if(dist==mindist)
        {
            ++cnt;
            if(num>maxnum)
                maxnum=num;
        }
        return;
    }

    if(dist>mindist)
        return;

    for(int i=0;i<n;++i)
    {
        if(visited[i]==0&&Map[cur][i]>0)
        {
            visited[i]=1;
            dfs(i,dist+Map[cur][i],num+teams[i]);
            visited[i]=0;
        }
    }
}

int main()
{
    cin>>n>>m>>from>>to;
    for(int i=0;i<n;++i)
    {
        int tmp;
        cin>>tmp;
        teams.push_back(tmp);
    }
    for(int i=0;i<m;++i)
    {
        int a,b,cos;
        cin>>a>>b>>cos;
        Map[a][b]=cos;
        Map[b][a]=cos;
    }
    dfs(from,0,teams[from]);
    cout<<cnt<<" "<<maxnum<<endl;
}
