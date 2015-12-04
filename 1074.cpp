#include <stdio.h>
#include <vector>
using namespace std;

int key[100000],Next[100000];
int n,k,start;
bool first=true;
vector<int> v;

void reverse()
{
    if(!first)
        printf("%05d\n",v[v.size()-1]);
    for(int i=v.size()-1;i>=0;--i)
    {
        if(i!=0)
            printf("%05d %d %05d\n",v[i],key[v[i]],v[i-1]);
        else
            printf("%05d %d ",v[i],key[v[i]]);
    }
    first=false;
}

int main()
{
    scanf("%d%d%d",&start,&n,&k);
    int add,keyvalue,nextadd;
    for(int i=0;i<n;++i)
    {
        scanf("%d%d%d",&add,&keyvalue,&nextadd);
        key[add]=keyvalue;
        Next[add]=nextadd;
    }
    int walk=start;
    while(walk!=-1)
    {
        v.push_back(walk);
        if(v.size()==k)
        {
            reverse();
            v.clear();
        }
        walk=Next[walk];
    }
    if(v.size()>0)
    {
        if(!first)
            printf("%05d\n",v[0]);
        for(int i=0;i<v.size();++i)
        {
            if(i<v.size()-1)
                printf("%05d %d %05d\n",v[i],key[v[i]],v[i+1]);
            else
                printf("%05d %d -1\n",v[i],key[v[i]]);
        }
    }
    else
        printf("-1\n");
    return 0;
}
