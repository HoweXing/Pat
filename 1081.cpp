#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

long long GCD(long long a,long long b)
{
    if(a<b)
    {
        long long c=b;
        b=a;
        a=c;
    }
    long long mod=a%b;
    while(mod!=0)
    {
        a=b;
        b=mod;
        mod=a%b;
    }
    return b;
}

long long LCM(long long a, long long b)
{
    return a*b/GCD(a,b);
}

int main()
{
    long long n;
    long long fz=0,fm=1;
    cin>>n;
    char str[50];
    for(long long i=0;i<n;++i)
    {
        long long a,b;
        scanf("%s",str);
        sscanf(str,"%lld/%lld",&a,&b);
        long long lcm = LCM(fm,b);
        fz*=lcm/fm;
        a*=lcm/b;
        fm=lcm;
        fz+=a;
    }
    if(fz==0)
        cout<<0<<endl;
    else
    {
        if(fz%fm==0)
            cout<<fz/fm<<endl;
        else if(abs(fz)<fm)
        {
            long long gcd = GCD(abs(fz),fm);
            fz/=gcd;
            fm/=gcd;
            cout<<fz<<"/"<<fm<<endl;
        }
        else
        {
            cout<<fz/fm<<" ";
            fz%=fm;
            long long gcd = GCD(fz,fm);
            fz/=gcd;
            fm/=gcd;
            cout<<fz<<"/"<<fm<<endl;
        }
    }
}
