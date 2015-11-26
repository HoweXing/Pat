#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define INF 0x7f7f7f7f
using namespace std;

int Map[1011][1011],visited[1011];
int lowcost[1011];
int n,m,k,ds;
int num_sta=0;
map<string,int> str_id;
string id_str[1011];

struct Station
{
    string name;
    double dist_house_total=0,dist_house_ave=0,dist_house_min=INF;
};
vector<Station> vs;

bool comp(const Station &a, const Station &b)
{
    if(a.dist_house_min!=b.dist_house_min)
        return a.dist_house_min>b.dist_house_min;
    if(a.dist_house_ave!=b.dist_house_ave)
        return a.dist_house_ave<b.dist_house_ave;
    return a.name<b.name;
}

bool isdig(string s)
{
    for(int i=0;i<s.size();++i)
    {
        if(s[i]<'0'||s[i]>'9')
            return false;
    }
    return true;
}

void dijkstra(int root)
{
    for(int i=1;i<=n+m;++i)
    {
        visited[i]=0;
        lowcost[i]=Map[root][i];
    }
    lowcost[root]=0;
    visited[root]=1;
    for(int i=2;i<=n+m;++i)
    {
        int mindist=INF;
        int u=-1;
        for(int i=1;i<=m+n;++i)
        {
            if(visited[i]==0 && lowcost[i]<mindist)
            {
                mindist=lowcost[i];
                u=i;
            }
        }
        visited[u]=1;
        for(int i=1;i<=m+n;++i)
        {
            if(visited[i]==0 && lowcost[u]+Map[u][i]<lowcost[i])
                lowcost[i]=lowcost[u]+Map[u][i];
        }
    }
}

int main()
{
    scanf("%d %d %d %d",&n,&m,&k,&ds);
    getchar();
    //cout<<n<<"&"<<m<<"&"<<k<<"&"<<ds<<endl;
    char c1[10],c2[10];
    int dis;
    for(int i=1;i<=n+m;++i)
    {
        for(int j=1;j<=n+m;++j)
            Map[i][j]=INF;
    }
    for(int i=0;i<k;++i)
    {
        scanf("%s %s %d",c1,c2,&dis);
        getchar();
        //cout<<c1<<"&"<<c2<<"&"<<dis<<endl;
        string cs1=c1,cs2=c2;
        int n1,n2;
        if(isdig(cs1))
            n1=atoi(c1);
        else
        {
            if(str_id[cs1]==0)
            {
                str_id[cs1]=++num_sta+n;
                id_str[num_sta]=cs1;
            }
            n1=str_id[cs1];
        }
        if(isdig(cs2))
            n2=atoi(c2);
        else
        {
            if(str_id[cs2]==0)
            {
                str_id[cs2]=++num_sta+n;
                id_str[num_sta]=cs2;
            }
            n2=str_id[cs2];
        }
        Map[n1][n2]=dis;
        Map[n2][n1]=dis;
    }
    for(int i=n+1;i<=n+m;++i)
    {
        dijkstra(i);
        Station sta;
        int cnt=0;
        for(int i=1;i<=n;++i)
        {
            if(lowcost[i]>ds)
                break;
            cnt++;
            if(lowcost[i]<sta.dist_house_min)
                sta.dist_house_min=lowcost[i];
            sta.dist_house_total+=lowcost[i];
        }
        if(cnt<n)
            continue;
        sta.dist_house_ave=sta.dist_house_total/n;
        sta.name=id_str[i-n];
        vs.push_back(sta);
    }
    sort(vs.begin(),vs.end(),comp);
    if(vs.size()==0)
        printf("No Solution\n");
    else
        printf("%s\n%.1f %.1f\n",vs[0].name.c_str(),vs[0].dist_house_min,vs[0].dist_house_ave);
    return 0;
}
