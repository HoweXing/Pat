#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[100001];
int n,cnt=0;
double srcp,r,prices[100001],minp=99999999999;

int main()
{
    scanf("%d %lf %lf",&n,&srcp,&r);
    for(int i=0;i<n;++i)
    {
        int num,tmp;
        scanf("%d",&num);
        for(int j=0;j<num;++j)
        {
            scanf("%d",&tmp);
            v[i].push_back(tmp);
        }
    }
    queue<int> q;
    q.push(0);
    prices[0]=srcp;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        if(v[cur].size()==0)
        {
            if(prices[cur]<minp)
            {
                minp=prices[cur];
                cnt=1;
            }
            else if(prices[cur]==minp)
                ++cnt;
        }
        else if(prices[cur]<minp)
        {
            for(int i=0;i<v[cur].size();++i)
            {
                prices[v[cur][i]]=prices[cur]*(1+r/100);
                if(prices[v[cur][i]]<=minp)
                    q.push(v[cur][i]);
            }
        }
    }
    printf("%.4f %d\n",minp,cnt);
    return 0;
}
