#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Stu{
    string id,name;
    int score;
};

int n,c;

bool comp_id(const Stu &a, const Stu &b)
{
    return a.id<b.id;
}

bool comp_name(const Stu &a, const Stu &b)
{
    if(a.name!=b.name)
        return a.name<b.name;
    return a.id<b.id;
}

bool comp_score(const Stu &a, const Stu &b)
{
    if(a.score!=b.score)
        return a.score<b.score;
    return a.id<b.id;
}

int main()
{
    scanf("%d %d",&n,&c);
    vector<Stu> v;
    for(int i=0;i<n;++i)
    {
        Stu s;
        char id[10],name[10];
        getchar();
        scanf("%s %s %d",id,name,&s.score);
        s.id=id;
        s.name=name;
        //cout<<s.id<<" "<<s.name<<" "<<s.score<<endl;
        v.push_back(s);
    }
    switch(c)
    {
        case 1:sort(v.begin(),v.end(),comp_id);break;
        case 2:sort(v.begin(),v.end(),comp_name);break;
        case 3:sort(v.begin(),v.end(),comp_score);break;
    }
    for(int i=0;i<n;++i)
    {
        printf("%s %s %d\n",v[i].id.c_str(),v[i].name.c_str(),v[i].score);
    }
    return 0;
}
