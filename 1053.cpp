#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int Map[101][101],weight[101],path[101],result[101],pos=0;
int n,m,s;
int stack[101],top=-1;

struct Node{
    int id,weightsum=0;
};

struct CompNode{
    int len=0,seq[101];
};

bool comp(const CompNode &a, const CompNode &b)
{
    int len=a.len;
    if(b.len<len)
        len=b.len;
    for(int i=0;i<len;++i)
    {
        if(a.seq[i]!=b.seq[i])
            return a.seq[i]>b.seq[i];
    }
    return false;
}

vector<CompNode> vc;

int main()
{
    for(int i=0;i<101;++i)
    {
        for(int j=0;j<101;++j)
            Map[i][j]=0;
    }
    path[0]=-1;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<n;++i)
        scanf("%d",&weight[i]);
    int pa,cnum;
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&pa,&cnum);
        Map[pa][0]=cnum;
        for(int j=1;j<=cnum;++j)
            scanf("%d",&Map[pa][j]);
    }
    queue<Node> q;
    Node node;
    node.id=0;
    node.weightsum=weight[0];
    q.push(node);
    while(!q.empty())
    {
        Node cur=q.front();
        q.pop();
        if(cur.weightsum==s && Map[cur.id][0]==0)
            result[pos++]=cur.id;
        else if(cur.weightsum<s)
        {
            for(int i=1;i<=Map[cur.id][0];++i)
            {
                node.id=Map[cur.id][i];
                path[node.id]=cur.id;
                node.weightsum=cur.weightsum+weight[node.id];
                q.push(node);
            }
        }
    }
    for(int i=0;i<pos;++i)
    {
        int walk=result[i];
        while(walk!=-1)
        {
            stack[++top]=weight[walk];
            walk=path[walk];
        }
        CompNode cn;
        while(top!=-1)
            cn.seq[cn.len++]=stack[top--];
        vc.push_back(cn);
    }
    sort(vc.begin(),vc.end(),comp);
    for(int i=0;i<vc.size();++i)
    {
        for(int j=0;j<vc[i].len;++j)
        {
            if(j>0)
                printf(" ");
            printf("%d",vc[i].seq[j]);
        }
        printf("\n");
    }
    return 0;
}
