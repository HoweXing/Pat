#include <stdio.h>
#include <algorithm>
using namespace std;

int N,arr[10001],can[10001],k=0,len=0;
int matrix[10001][10001];
int m,n;

bool comp(const int a, const int b)
{
    return a>b;
}

int findNext(int curx, int cury, int d)
{
    switch(d)
    {
        case 1:{
            if(cury+1<n && matrix[curx][cury+1]==0)
                return 1;
            return 2;
            break;
        }
        case 2:{
            if(curx+1<m && matrix[curx+1][cury]==0)
                return 2;
            return 3;
            break;
        }
        case 3:{
            if(cury-1>=0 && matrix[curx][cury-1]==0)
                return 3;
            return 4;
            break;
        }
        case 4:{
            if(curx-1>=0 && matrix[curx-1][cury]==0)
                return 4;
            return 1;
        }
    }
}

int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;++i)
        scanf("%d",&arr[i]);
    sort(arr,arr+N,comp);
    for(int i=1;i<=N;++i)
    {
        if(N%i==0)
        {
            can[len++]=i;
            if(i*i<=N)
                k=len;
        }
    }
    m=can[k-1];
    n=can[k-1];
    int mi=k-1,ni=k-1;
    if(m*n!=N)
    {
        int tmp=m*n;
        while(tmp!=N)
        {
            if(tmp<N)
            {
                if(m>n)
                    n=can[++ni];
                else
                    m=can[++mi];
            }
            else
            {
                if(m>n)
                    m=can[--mi];

            }
            tmp=m*n;
        }
    }
    int x=0,y=0,d=1;
    for(int i=0;i<N;++i)
    {
        matrix[x][y]=arr[i];
        d=findNext(x,y,d);
        switch(d)
        {
            case 1:{
                ++y;
                break;
            }
            case 2:{
                ++x;
                break;
            }
            case 3:{
                --y;
                break;
            }
            case 4:{
                --x;
                break;
            }
        }
    }
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(j>0)
                printf(" ");
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
