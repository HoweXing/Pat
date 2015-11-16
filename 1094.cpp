#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stdlib.h>
using namespace std;

vector<int> v[101];

int main()
{
    int n,m;
    cin>>n>>m;
    int id,k,child;
    int root,sum=0;
    for(int i=0;i<m;++i)
    {
        cin>>id>>k;
        for(int j=0;j<k;++j)
        {
            cin>>child;
            sum+=child;
            v[id].push_back(child);
        }
    }
    root=1;
    queue<pair<int,int> > q;
    pair<int,int> node;
    node.first=root;
    node.second=1;
    q.push(node);
    pair<int,int> cur;
    map<int,int> popu;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        popu[cur.second]++;
        id=cur.first;
        for(int i=0;i<v[id].size();++i)
        {
            node.first=v[id][i];
            node.second=cur.second+1;
            q.push(node);
        }
    }
    int maxpopu=0,gen;
    for(map<int,int>::iterator it=popu.begin();it!=popu.end();++it)
    {
        if(it->second>maxpopu)
        {
            maxpopu=it->second;
            gen=it->first;
        }
    }
    cout<<maxpopu<<" "<<gen<<endl;
    return 0;
}
