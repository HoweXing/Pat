#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <string>
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

string rtoa(long long num_n, long long num_d)
{
    bool neg=((num_n<0||num_d<0) && !(num_n<0&&num_d<0));
    long long integer=abs(num_n/num_d);
    long long n=abs(num_n%num_d);
    long long d=abs(num_d);
    if(n!=0)
    {
        long long gcd = GCD(n,d);
        n/=gcd;
        d/=gcd;
    }

    string str;
    if(integer==0&&n==0)
        str="0";
    else
    {
        if(neg)
            str="(-";
        if(integer!=0&&n!=0)
        {
            char tmp[1000];
            sprintf(tmp,"%lld %lld/%lld",integer,n,d);
            str.append(tmp);
        }
        else if(integer==0)
        {
            char tmp[1000];
            sprintf(tmp,"%lld/%lld",n,d);
            str.append(tmp);
        }
        else
        {
            char tmp[1000];
            sprintf(tmp,"%lld",integer);
            str.append(tmp);
        }
        if(neg)
            str.append(")");
    }
    return str;
}

int main()
{
    long long num1_n,num1_d,num2_n,num2_d;
    char line[1000];
    gets(line);

    int loc[3]={-1,-1,-1};
    for(int i=0,k=0;i<strlen(line);++i)
    {
        if(line[i]=='/'||line[i]==' ')
            loc[k++]=i;
    }
    if(loc[0]!=-1&&loc[1]!=-1&&loc[2]!=-1)
        sscanf(line,"%lld/%lld %lld/%lld",&num1_n, &num1_d, &num2_n, &num2_d);
    else if(loc[1]==-1&&loc[2]==-1)
    {
        sscanf(line,"%lld %lld",&num1_n, &num2_n);
        num1_d=num2_d=1;
    }
    else if(loc[2]==-1)
    {
        if(line[loc[0]]=='/')
        {
            sscanf(line,"%lld/%lld %lld",&num1_n, &num1_d, &num2_n);
            num2_d=1;
        }
        else
        {
            sscanf(line,"%lld %lld/%lld",&num1_n, &num2_n, &num2_d);
            num1_d=1;
        }
    }

    string str1,str2;
    str1=rtoa(num1_n,num1_d);
    str2=rtoa(num2_n,num2_d);

    int lcm = LCM(num1_d,num2_d);
    /*add*/
    cout<<str1<<" + "<<str2<<" = "<<rtoa(num1_n*(lcm/num1_d)+num2_n*(lcm/num2_d),lcm)<<endl;
    /*sub*/
    cout<<str1<<" - "<<str2<<" = "<<rtoa(num1_n*(lcm/num1_d)-num2_n*(lcm/num2_d),lcm)<<endl;
    /*mul*/
    cout<<str1<<" * "<<str2<<" = "<<rtoa(num1_n*num2_n,num1_d*num2_d)<<endl;
    /*div*/
    if(num2_n==0)
        cout<<str1<<" / "<<str2<<" = Inf"<<endl;
    else
        cout<<str1<<" / "<<str2<<" = "<<rtoa(num1_n*num2_d,num1_d*num2_n)<<endl;
}
