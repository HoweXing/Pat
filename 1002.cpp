#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int k;
    map<int,double> Map;
    scanf("%d",&k);
    for(int i=0;i<k;++i)
    {
        int n;
        double num;
        scanf("%d%lf",&n,&num);
        Map[n]+=num;
    }
    scanf("%d",&k);
    for(int i=0;i<k;++i)
    {
        int n;
        double num;
        scanf("%d%lf",&n,&num);
        Map[n]+=num;
    }
    int cnt=0;
    for(map<int,double>::reverse_iterator it=Map.rbegin();it!=Map.rend();++it)
    {
        if(it->second!=0)
            ++cnt;
    }
    printf("%d",cnt);
    for(map<int,double>::reverse_iterator it=Map.rbegin();it!=Map.rend();++it)
    {
        if(it->second!=0)
            printf(" %d %.1f",it->first,it->second);
    }
    printf("\n");
    return 0;
}
