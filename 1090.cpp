#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

vector<int> v[100005];

int main()
{
    int n;
    double srcp,r;
    cin>>n>>srcp>>r;
    int tmp,root;
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        if(tmp!=-1)
            v[tmp].push_back(i);
        else
            root=i;
    }
    pair<int,int> cur,rootp;
    rootp.first=root;
    rootp.second=0;
    queue<pair<int,int> > q;
    q.push(rootp);
    int maxdep=0;
    map<int,int> m;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        m[cur.second]++;
        if(cur.second>maxdep)
            maxdep=cur.second;
        for(int i=0;i<v[cur.first].size();++i)
        {
            rootp.first=v[cur.first][i];
            rootp.second=cur.second+1;
            q.push(rootp);
        }
    }
    printf("%.2f %d\n",srcp*pow(1+r/100,maxdep),m[maxdep]);
}
