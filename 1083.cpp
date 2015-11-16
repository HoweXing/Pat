#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu
{
    char name[11];
    char id[11];
    float grade;
};

bool comp(const Stu &a, const Stu &b)
{
    return a.grade>b.grade;
}

vector<Stu> vs;

int main()
{
    int n;
    int g1,g2;
    cin>>n;
    if(n==0)
    {
        cout<<"NONE"<<endl;
        return 0;
    }
    for(int i=0;i<n;++i)
    {
        Stu tmp;
        cin>>tmp.name>>tmp.id>>tmp.grade;
        vs.push_back(tmp);
    }
    cin>>g1>>g2;
    if(g1>g2)
    {
        int c=g2;
        g2=g1;
        g1=c;
    }
    sort(vs.begin(),vs.end(),comp);
    int start;
    for(start=0;start<vs.size()&&vs[start].grade>g2;++start)
        ;
    if(start==vs.size())
        cout<<"NONE"<<endl;
    else if(vs[start].grade<g1)
        cout<<"NONE"<<endl;
    else
    {
        for(;start<vs.size()&&vs[start].grade>=g1;++start)
            cout<<vs[start].name<<" "<<vs[start].id<<endl;
    }
    return 0;
}
