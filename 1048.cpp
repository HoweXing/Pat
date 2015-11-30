#include <stdio.h>
#include <algorithm>
using namespace std;

int n,m;
int coins[100001];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",&coins[i]);
    sort(coins,coins+n);
    int v1=0,v2=n-1;
    while(v1<v2)
    {
        int sum=coins[v1]+coins[v2];
        if(sum==m)
            break;
        else if(sum<m)
            ++v1;
        else
            --v2;
    }
    if(v1==v2)
        printf("No Solution\n");
    else
        printf("%d %d\n",coins[v1],coins[v2]);
}
