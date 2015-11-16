#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

set<int> s;
vector<int> v,re;
map<int,int> pos,spos,errorpos;

int main()
{
    int n;
    scanf("%d",&n);
    int tmp;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&tmp);
        pos[tmp]=i;
        s.insert(tmp);
    }
    int id=0;
    for(set<int>::iterator it=s.begin();it!=s.end();++it,++id)
        spos[*it]=id;
    for(map<int,int>::iterator sit=spos.begin(),it=pos.begin();sit!=spos.end();sit++,it++)
    {
        if(it->second!=sit->second)
            errorpos[it->first]=it->second;
    }
    for(map<int,int>::iterator sit=spos.begin(),it=pos.begin();sit!=spos.end();sit++,it++)
    {
        if(it->second!=sit->second)
            continue;
        bool flag=true;
        for(map<int,int>::iterator tit=errorpos.begin();tit!=errorpos.end()&&flag;++tit)
        {
            if(tit->first<it->first&&tit->second>it->second)
                flag=false;
            if(tit->first>it->first&&tit->second<it->second)
                flag=false;
        }
        if(flag)
            re.push_back(it->first);
    }
    printf("%d\n",re.size());
    for(int i=0;i<re.size();++i)
    {
        if(i!=0)
            printf(" ");
        printf("%d",re[i]);
    }
    printf("\n");
    return 0;
}
