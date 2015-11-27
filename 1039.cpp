#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

map<int,vector<int> > Map;
set<int>::iterator it;

int Hash(char* s)
{
    return (s[0]-'A')*6760+(s[1]-'A')*260+(s[2]-'A')*10+s[3]-'0';
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    string name;
    char tmp[5];
    for(int i=0;i<k;++i)
    {
        int index,m;
        scanf("%d %d",&index,&m);
        for(int j=0;j<m;++j)
        {
            scanf("%s",tmp);
            Map[Hash(tmp)].push_back(index);
        }
    }
    for(int i=0;i<n;++i)
    {
        scanf("%s",tmp);
        int hnm=Hash(tmp);
        printf("%s %d",tmp,Map[hnm].size());
        sort(Map[hnm].begin(),Map[hnm].end());
        int j=0,e=Map[hnm].size();
        for(int j=0;j<e;++j)
            printf(" %d",Map[hnm][j]);
        printf("\n");
    }
    return 0;
}
