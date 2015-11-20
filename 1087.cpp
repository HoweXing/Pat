#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#define INF 0x7f7f7f7f
using namespace std;

int n,k;
string start,tmpstr;
string citys[201];
map<string,int> cityid;
int Map[201][201];
int target,mindist;
int happiness[201];
int visited[201],a[201];
vector<int> v[201];
int cnt=0;

int dijkstra()
{
    int i,j,u,min;
    int set[201],lowcost[201];
    for(int i=0;i<n;++i)
    {
        lowcost[i]=Map[0][i];
        set[i]=0;
    }
    set[0]=1;
    for(i=1;i<n;++i)
    {
        min=INF;
        u=-1;
        for(j=1;j<n;++j)
        {
            if(set[j]==0&&lowcost[j]<min)
            {
                min=lowcost[j];
                u=j;
            }
        }
        if(u==target)
            break;
        set[u]=1;
        for(j=1;j<n;++j)
        {
            if(set[j]==0&&lowcost[u]+Map[u][j]<lowcost[j])
                lowcost[j]=lowcost[u]+Map[u][j];
        }
    }
    return lowcost[target];
}

void DFS(int now,int cur,int citynum)
{
    int i;
    if(now==target)
    {
        if(cur==mindist)
        {
            for(i=0;i<citynum;++i)
                v[cnt].push_back(a[i]);
            ++cnt;
        }
        return;
    }
    if(cur>=mindist)
        return;
    for(i=1;i<n;++i)
    {
        if(visited[i]==0&&Map[now][i]<INF)
        {
            visited[now]=i;
            cur+=Map[now][i];
            a[citynum]=i;
            DFS(i,cur,citynum+1);
            cur-=Map[now][i];
            visited[now]=0;
        }
    }
}

bool comp(const vector<int> &a, const vector<int> &b)
{
    int sum1=0,sum2=0;
    for(int i=0;i<a.size();++i)
        sum1+=happiness[a[i]];
    for(int i=0;i<b.size();++i)
        sum2+=happiness[b[i]];
    if(sum1!=sum2)
        return sum1>sum2;
    else
        return (sum1/a.size())>(sum2/b.size());
}

int main()
{
    cin>>n>>k>>start;
    citys[0]=start;
    cityid[start]=0;
    for(int i=0;i<n;++i)
    {
        visited[i]=0;
        for(int j=0;j<n;++j)
        {
            Map[i][j]=INF;
        }
    }
    for(int i=1;i<n;++i)
    {
        cin>>citys[i]>>happiness[i];
        cityid[citys[i]]=i;
        if(citys[i]=="ROM")
            target=i;
    }
    for(int i=0;i<k;++i)
    {
        string c1,c2;
        int cost;
        cin>>c1>>c2>>cost;
        Map[cityid[c1]][cityid[c2]]=cost;
        Map[cityid[c2]][cityid[c1]]=cost;
    }
    mindist=dijkstra();
    DFS(0,0,0);
    sort(v,v+cnt,comp);
    int happinesssum=0;
    for(int i=0;i<v[0].size();++i)
        happinesssum+=happiness[v[0][i]];
    cout<<cnt<<" "<<mindist<<" "<<happinesssum<<" "<<happinesssum/v[0].size()<<endl;
    cout<<citys[0];
    for(int i=0;i<v[0].size();++i)
        cout<<"->"<<citys[v[0][i]];
    cout<<endl;
    return 0;
}
