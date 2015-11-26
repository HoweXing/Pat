#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int Map[2001][2001],visited[2001];
map<string,int> name_id;
string id_name[2001];

int n,k,people=0;
int curmax=-1,total=0,cnt=0;
string curhead;
set<int> visit;

struct Node{
    string head;
    int num;
};

bool comp(const Node &a, const Node &b)
{
    return a.head<b.head;
}

void DFS(int cur)
{
    visit.insert(cur);
    visited[cur]=1;
    for(int i=1;i<=people;++i)
    {
        if(visited[i]==0 && Map[cur][i]>0)
        {
            //cout<<id_name[cur]<<" & "<<id_name[i]<<" "<<total<<endl;
            DFS(i);
        }
    }
}

int main()
{
    cin>>n>>k;
    string c1,c2;
    int n1,n2;
    int time;
    for(int i=0;i<=2*n;++i)
    {
        visited[i]=0;
        for(int j=0;j<=2*n;++j)
            Map[i][j]=0;
    }
    for(int i=0;i<n;++i)
    {
        cin>>c1>>c2>>time;
        if(name_id[c1]==0)
        {
            name_id[c1]=++people;
            id_name[people]=c1;
        }
        if(name_id[c2]==0)
        {
            name_id[c2]=++people;
            id_name[people]=c2;
        }
        n1=name_id[c1];
        n2=name_id[c2];
        Map[n1][n2]+=time;
        Map[n2][n1]+=time;
    }
    vector<Node> gangs;
    for(int i=1;i<=people;++i)
    {
        if(visited[i]==0)
        {
            curmax=-1;
            total=0;
            DFS(i);
            cnt=visit.size();
            //cout<<cnt<<" "<<curhead<<" "<<total<<endl;
            for(set<int>::iterator it=visit.begin();it!=visit.end();++it)
            {
                int curtotal=0;
                for(int j=1;j<=people;++j)
                {
                    curtotal+=Map[*it][j];
                    total+=Map[*it][j];
                }
                if(curtotal>curmax)
                {
                    curmax=curtotal;
                    curhead=id_name[*it];
                }
            }
            visit.clear();
            if(cnt>2 && total/2>k)
            {
                Node node;
                node.head=curhead;
                node.num=cnt;
                gangs.push_back(node);
            }
        }
    }
    sort(gangs.begin(),gangs.end(),comp);
    printf("%d\n",gangs.size());
    for(int i=0;i<gangs.size();++i)
        printf("%s %d\n",gangs[i].head.c_str(),gangs[i].num);
    return 0;
}
