#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,m,k;
vector<int> Map[1001];
int visited[1001];

void bfs(int city)
{
    queue<int> q;
    q.push(city);
    visited[city]=1;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(int i=0;i<Map[cur].size();++i)
        {
            if(visited[Map[cur][i]]!=1)
            {
                q.push(Map[cur][i]);
                visited[Map[cur][i]]=1;
            }
        }
    }
}

void dfs(int city)
{
    if(visited[city]==0)
    {
        visited[city]=1;
        for(int i=0;i<Map[city].size();++i)
        {
            if(visited[Map[city][i]]==0)
                dfs(Map[city][i]);
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<m;++i)
    {
        int s,e;
        cin>>s>>e;
        Map[s].push_back(e);
        Map[e].push_back(s);
    }
    for(int i=0;i<k;++i)
    {
        int dis;
        cin>>dis;
        memset(visited,0,sizeof(int)*(n+1));
        visited[dis]=1;
        int cnt=0;
        for(int j=1;j<=n;++j)
        {
            if(visited[j]==0)
            {
                ++cnt;
                //bfs(j);
                dfs(j);
            }
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}
