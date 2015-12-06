#include <stdio.h>

int arr[100001],n;

int find(int start)
{
    for(int i=start;i<n;++i)
    {
        if(arr[i]!=i)
            return i;
    }
    return -1;
}

int main()
{
    scanf("%d",&n);
    bool flag=false;
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    int pos=find(1),cnt=0,tmp;
    while(pos!=-1)
    {
        if(arr[0]==0)
        {
            arr[0]=arr[pos];
            arr[pos]=0;
            ++cnt;
        }
        while(arr[0]!=0)
        {
            tmp=arr[0];
            arr[0]=arr[tmp];
            arr[tmp]=tmp;
            ++cnt;
        }
        pos=find(pos);
    }
    printf("%d\n",cnt);
    return 0;
}
