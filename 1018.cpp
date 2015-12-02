#include<cstdio>
#include<vector>
#define INF 0x7f7f7f7f
using namespace std;
int map[505][505];
int remain[505];
int cmax,n,sp,m,sum=0,cnt=0;
int a[505],visit[505];
vector<int> v[505];
int p[505];
void dijkstra()
{
	int i,j,u,min,k;
	int set[505],lowcost[505];
	for(i=0;i<=n;++i)
	{
		lowcost[i]=map[0][i];
		set[i]=0;
	}
	set[0]=1;
	for(i=1;i<=n;++i)
	{
		min=INF;
		u=-1;
		for(j=1;j<=n;++j)
			if(set[j]==0&&lowcost[j]<min)
			{
				min=lowcost[j];
				u=j;
			}
		if(u==sp)
			break;
		set[u]=1;
		for(j=1;j<=n;++j)
			if(set[j]==0&&lowcost[u]+map[u][j]<lowcost[j])
				lowcost[j]=lowcost[u]+map[u][j];
	}
	sum=lowcost[sp];
}
void DFS(int no,int cur,int k)
{
	int i;
	if(no==sp)
	{
		if(cur==sum)
		{
			for(i=0;i<k;++i)
				v[cnt].push_back(a[i]);
			++cnt;
		}
		return;
	}
	if(cur>=sum)
		return;
	for(i=1;i<=n;++i)
		if(visit[i]==0&&map[no][i]<INF)
		{
			visit[no]=1;
			cur+=map[no][i];
			a[k]=i;
			DFS(i,cur,k+1);
			cur-=map[no][i];
			visit[no]=0;
		}
}
int main()
{
	int i,j,x,y,t,u;
	bool f=false;
	scanf("%d%d%d%d",&cmax,&n,&sp,&m);
	for(i=1;i<=n;++i)
		scanf("%d",&remain[i]);
	for(i=0;i<=n;++i)
	{
		visit[i]=0;
		for(j=0;j<=n;++j)
			map[i][j]=INF;
	}
	for(i=0;i<m;++i)
	{
		scanf("%d%d%d",&x,&y,&t);
		map[x][y]=map[y][x]=t;
	}
	dijkstra();
	DFS(0,0,0);
	int q[505],k=0,send[505],back[505],in=INF,min;
	for(i=0;i<cnt;++i)
	{
		for(j=0;j<v[i].size();++j)
		{
			if(j==0)
				q[j]=remain[v[i][j]]-cmax/2;
			else
				q[j]=q[j-1]+remain[v[i][j]]-cmax/2;
		}
		min=INF;
		for(j=0;j<v[i].size();++j)
		{
			if(q[j]<min)
				min=q[j];
		}
		if(min<0)
		{
			send[i]=0-min;
			back[i]=q[v[i].size()-1]+send[i];
		}
		else
		{
			send[i]=0;
			back[i]=q[v[i].size()-1]+send[i];
		}
		if(send[i]<in)
			in=send[i];
	}
	min=INF;
	for(i=0;i<cnt;++i)
		if(send[i]==in&&back[i]<min)
		{
			min=back[i];
			u=i;
		}
	printf("%d ",send[u]);
	printf("0->");
	for(i=0;i<v[u].size();++i)
	{
		if(i!=0)
			printf("->");
		printf("%d",v[u][i]);
	}
	printf(" %d\n",back[u]);
	return 0;
}
