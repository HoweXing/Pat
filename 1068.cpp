#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int coins[10001],n,m;
int dp[10001][101],contain[10001][101];

bool comp(const int &a, const int &b)
{
    return a>b;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&coins[i]);
    sort(coins+1,coins+1+n,comp);

    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            contain[i][j]=0;
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(j<coins[i] || dp[i-1][j]>dp[i-1][j-coins[i]]+coins[i])
                dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=dp[i-1][j-coins[i]]+coins[i];
                contain[i][j]=1;
            }
        }
    }
    if(dp[n][m]!=m)
        printf("No Solution\n");
    else
    {
        vector<int> v;
        int walk=m;
        for(int i=n;i>0&&walk>0;--i)
        {
            if(contain[i][walk]==1)
            {
                v.push_back(coins[i]);
                walk-=coins[i];
            }
        }
        for(int i=0;i<v.size();++i)
        {
            if(i>0)
                printf(" ");
            printf("%d",v[i]);
        }
        printf("\n");
    }
    return 0;
}
