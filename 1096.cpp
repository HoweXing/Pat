#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

long long range[2];

void fun(long long num)
{
    //long long num;
    //cin>>num;
    long long maxlen=1;
    long long smallest=num;
    range[0]=0;
    range[1]=0;
    for(long long s=2;s*s<=num;++s)
    {
        if(num%s!=0)
            continue;
        if(smallest>s)
            smallest=s;
        //cout<<s<<" ";
        long long tmp=num;
        for(long long e=s;e<=num;++e)
        {
            if(tmp%e!=0)
                break;
            if(e-s+1>maxlen)
            {
                range[0]=s;
                range[1]=e;
                maxlen=e-s+1;
            }
            tmp/=e;
        }
        //cout<<endl;
    }
    //cout<<maxlen<<" "<<range[0]<<" "<<range[1]<<endl;
    if(range[0]!=0&&range[1]!=0)
    {
        printf("%d\n",range[1]-range[0]+1);
        for(int i=range[0];i<=range[1];++i)
        {
            if(i!=range[0])
                printf("*");
            printf("%d",i);
        }
        printf("\n");
    }
    else
        printf("1\n%d\n",smallest);
    //return 0;
}

int main()
{
    long long n;
    cin>>n;
    fun(n);
}
