#include <stdio.h>

int n,m,l;
int fav[201],arr[10001],dp[201][10001]={0};

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
        scanf("%d",&fav[i]);
    scanf("%d",&l);
    for(int i=1;i<=l;++i)
        scanf("%d",&arr[i]);
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=l;++j)
        {
            int max=dp[i-1][j-1];
            if(max<dp[i-1][j])
                max=dp[i-1][j];
            if(max<dp[i][j-1])
                max=dp[i][j-1];
            if(fav[i]==arr[j])
                dp[i][j]=max+1;
            else
            {
                dp[i][j]=max;
            }
        }
    }
    printf("%d\n",dp[m][l]);
}
