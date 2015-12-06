#include <stdio.h>
#include <queue>
using namespace std;

int Map[1001][1001];
int n,l;

struct Node
{
    int ui,level;
};

int BFS(int ui)
{
    int visited[1001];
    for(int i=1;i<=n;++i)
        visited[i]=0;
    queue<Node> q;
    Node node;
    node.ui=ui;
    node.level=0;
    q.push(node);
    visited[ui]=1;
    int cnt=0;
    while(!q.empty())
    {
        Node cur=q.front();
        q.pop();
        ++cnt;
        if(cur.level<l)
        {
            for(int i=1;i<=Map[cur.ui][0];++i)
            {
                if(visited[Map[cur.ui][i]]==0)
                {
                    node.ui=Map[cur.ui][i];
                    node.level=cur.level+1;
                    q.push(node);
                    visited[node.ui]=1;
                }
            }
        }
    }
    return cnt-1;
}

int main()
{
    scanf("%d%d\n",&n,&l);
    for(int i=1;i<=n;++i)
    {
        int num,ui;
        scanf("%d",&num);
        for(int j=0;j<num;++j)
        {
            scanf("%d",&ui);
            Map[ui][++Map[ui][0]]=i;
        }
    }
    int m,ui;
    scanf("%d",&m);
    for(int i=0;i<m;++i)
    {
        scanf("%d",&ui);
        printf("%d\n",BFS(ui));
    }
    return 0;
}
