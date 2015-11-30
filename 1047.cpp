#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

struct Hash{
    int n[4];
};

int n,k,c;
map<int,vector<Hash> > Map;

bool comp(const Hash &a, const Hash &b)
{
    for(int i=0;i<4;++i)
    {
        if(a.n[i]!=b.n[i])
            return a.n[i]<b.n[i];
    }
    return true;
}

int main()
{
    scanf("%d%d",&n,&k);
    char name[4];
    int course;
    for(int i=0;i<n;++i)
    {
        getchar();
        scanf("%s%d",name,&c);
        for(int j=0;j<c;++j)
        {
            scanf("%d",&course);
            Hash h;
            for(int z=0;z<4;++z)
            {
                if(z!=3)
                    h.n[z]=name[z]-'A';
                else
                    h.n[z]=name[z]-'0';
            }
            Map[course].push_back(h);
        }
    }
    for(int i=1;i<=k;++i)
    {
        if(Map[i].size()==0)
            printf("%d 0\n",i);
        else
        {
            printf("%d %d\n",i,Map[i].size());
            sort(Map[i].begin(),Map[i].end(),comp);
            for(int j=0;j<Map[i].size();++j)
                printf("%c%c%c%c\n",Map[i][j].n[0]+'A',Map[i][j].n[1]+'A',Map[i][j].n[2]+'A',Map[i][j].n[3]+'0');
        }
    }
    return 0;
}
