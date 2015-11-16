#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

char line[100];
char n1[11],n2[11];
int tag,radix;

long long otoi(char *s, long long r)
{
    long long base=1,num=0;
    //cout<<strlen(s)<<endl;
    //int total=0;
    for(int i=strlen(s)-1;i>=0;--i)
    {
        if(s[i]>='0'&&s[i]<='9')
            num+=((s[i]-'0')*base);
        else
            num+=((s[i]-'a'+10)*base);
        base*=r;
        //total+=num;
    }
    //cout<<r<<" "<<num<<" "<<total<<endl;
    return num;
}

int findMax(char *s)
{
    int max=-1;
    for(int i=0;i<strlen(s);++i)
    {
        if(s[i]>max)
            max=s[i];
    }
    if(max>='0'&&max<='9')
        return max-'0'+1;
    else
        return max-'a'+10+1;
}

int main()
{
    cin>>n1>>n2>>tag>>radix;
    //cout<<n1<<" "<<n2<<" "<<tag<<" "<<radix<<endl;
    long long ln1,ln2,cmp;
    char var[11];
    long long start,re=-1,e;
    if(strcmp(n1,"1")==0&&strcmp(n2,"1")==0)
    {
        cout<<2<<endl;
        return 0;
    }
    if(strcmp(n1,n2)==0)
    {
        cout<<radix<<endl;
        return 0;
    }

    if(tag==1)
    {
        ln1=otoi(n1,radix);
        cmp=ln1;
        start=findMax(n2);
        e=(ln1+1)>36?(ln1+1):36;
        strcpy(var,n2);
    }
    else
    {
        ln2=otoi(n2,radix);
        cmp=ln2;
        start=findMax(n1);
        e=(ln2+1)>36?(ln2+1):36;
        strcpy(var,n1);
    }
    /*long long l=start;
    long long r=e;
    long long mid=(l+r)/2;
    while(l<r)
    {
        //cout<<mid<<endl;
        long long tmp=otoi(var,mid);
        if(tmp==cmp)
        {
            re=mid;
            break;
        }
        if(tmp<cmp)
        {
            l=mid;
            mid=(l+r)/2;
        }
        else
        {
            r=mid;
            mid=(l+r)/2;
        }
    }*/
    if(strlen(var)==1)
    {
        if(otoi(var,start)==cmp)
            re=start;
    }
    else
    {
        long long l=start;
        long long r=e;
        long long mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            long long tmp=otoi(var,mid);
            if(tmp==cmp)
            {
                re=mid;
                break;
            }
            if(tmp>=0&&tmp<cmp)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        /*for(int i=start;i<=e;++i)
        {
            long long tmp=otoi(var,i);
            if(cmp<tmp)
                break;
            if(cmp==tmp)
            {
                re=i;
                break;
            }
        }*/
    }
    if(re==-1)
        cout<<"Impossible"<<endl;
    else
        cout<<re<<endl;
    return 0;
}
