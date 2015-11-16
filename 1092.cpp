#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;

int main()
{
    char shop[1001],eva[1001];
    map<char,int> m;
    gets(shop);
    gets(eva);
    for(int i=0;i<strlen(eva);++i)
        m[eva[i]]++;
    for(int i=0;i<strlen(shop);++i)
    {
        if(m[shop[i]]>0)
            --m[shop[i]];
    }
    int sum=0;
    for(map<char,int>::iterator it=m.begin();it!=m.end();++it)
        sum+=it->second;
    if(sum>0)
        cout<<"No "<<sum<<endl;
    else
        cout<<"Yes "<<strlen(shop)-strlen(eva)<<endl;
    return 0;
}
