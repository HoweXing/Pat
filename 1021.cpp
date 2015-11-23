#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

int n;
int visited[10001],glovisited[10001];
vector<int> Map[10001];
int maxhight[10001];
int comp=0;

int DFS(int root)
{
    //cout<<root<<endl;
    if(glovisited[root]==0)
        glovisited[root]=1;
   if(visited[root]==0)
   {
       visited[root]=1;
       int maxh=-1;
       /*for(int i=1;i<=n;++i)
       {
           if(Map[root][i]==1&&visited[i]==0)
           {
               int tmp=DFS(i);
               if(tmp>maxh)
                maxh=tmp;
           }
       }*/
       for(int i=0;i<Map[root].size();++i)
       {
           int cur=Map[root][i];
           if(visited[cur]==0)
           {
               int tmp=DFS(cur);
               if(tmp>maxh)
                maxh=tmp;
           }
       }
       if(maxh>maxhight[root])
            maxhight[root]=maxh;
       return maxh+1;
   }
   else
        return -1;
}

int main()
{
    cin>>n;
    int n1,n2;
    for(int i=1;i<=n;++i)
    {
        visited[i]=0;
        maxhight[i]=0;
        glovisited[i]=0;
        //for(int j=1;j<=n;++j)
        //    Map[i][j]=0;
    }
    for(int i=1;i<n;++i)
    {
        cin>>n1>>n2;
        //Map[n1][n2]=1;
        //Map[n2][n1]=1;
        Map[n1].push_back(n2);
        Map[n2].push_back(n1);
    }
    for(int i=1;i<=n;++i)
    {
        if(glovisited[i]==0)
            ++comp;
        memset(visited,0,sizeof(int)*(n+1));
        int tmp=DFS(i);
        if(tmp>maxhight[i])
            maxhight[i]=tmp;
    }
    if(comp>1)
        printf("Error: %d components\n",comp);
    else
    {
        int maxh=0;
        vector<int> re;
        for(int i=1;i<=n;++i)
        {
            if(maxhight[i]>maxh)
            {
                maxh=maxhight[i];
                re.clear();
                re.push_back(i);
            }
            else if(maxhight[i]==maxh)
                re.push_back(i);
        }
        for(int i=0;i<re.size();++i)
            printf("%d\n",re[i]);
    }
    return 0;
}
