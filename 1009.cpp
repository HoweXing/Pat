#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

map<int,double> n1,n2,re;
map<int,double>::iterator it1,it2;
map<int,double>::reverse_iterator it;

int main()
{
    int n,k;
    double num;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>k>>num;
        n1[k]=num;
    }
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>k>>num;
        n2[k]=num;
    }
    for(it1=n1.begin();it1!=n1.end();++it1)
    {
        for(it2=n2.begin();it2!=n2.end();++it2)
        {
            re[it1->first+it2->first]+=it1->second*it2->second;
        }
    }
    int cnt=0;
    for(it=re.rbegin();it!=re.rend();++it)
    {
        if(it->second!=0)
            ++cnt;
    }
    printf("%d",cnt);
    for(it=re.rbegin();it!=re.rend();++it)
    {
        if(it->second!=0)
            printf(" %d %.1f",it->first,it->second);
    }
    printf("\n");
    return 0;
}
