#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node{
    int id,level;
};

map<int,vector<int> > Map;
map<int,int> nochild;
int n,m;

int main()
{
    cin>>n>>m;
    int id,k,child;
    for(int i=0;i<m;++i)
    {
        cin>>id>>k;
        for(int j=0;j<k;++j)
        {
            cin>>child;
            Map[id].push_back(child);
        }
    }
    queue<Node> q;
    Node node ;
    node.id=1;
    node.level=0;
    q.push(node);
    int maxlevel=0;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        if(node.level>maxlevel)
            maxlevel=node.level;
        if(Map[node.id].size()==0)
            nochild[node.level]++;
        for(int i=0;i<Map[node.id].size();++i)
        {
            Node tmp;
            tmp.id=Map[node.id][i];
            tmp.level=node.level+1;
            q.push(tmp);
        }
    }
    for(int i=0;i<=maxlevel;++i)
    {
        if(i!=0)
            printf(" ");
        printf("%d",nochild[i]);
    }
    printf("\n");
    return 0;
}
