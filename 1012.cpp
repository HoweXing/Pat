#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Stu{
    int score[4],rank[4];
    int bestrank,index;
    string id;
};

string course[4]={"A","C","M","E"};
vector<Stu> v;
map<string,Stu> Map;

bool comp_c(const Stu &a, const Stu &b)
{
    return a.score[1]>b.score[1];
}

bool comp_m(const Stu &a, const Stu &b)
{
    return a.score[2]>b.score[2];
}

bool comp_e(const Stu &a, const Stu &b)
{
    return a.score[3]>b.score[3];
}

bool comp_a(const Stu &a, const Stu &b)
{
    return a.score[0]>b.score[0];
}

void adj(int index)
{
    for(int i=0;i<v.size();++i)
    {
        if(i>0)
        {
            if(v[i].score[index]==v[i-1].score[index])
            {
                v[i].rank[index]=v[i-1].rank[index];
            }
            else
                v[i].rank[index]=i+1;
        }
        else
            v[i].rank[index]=i+1;
    }
}

void bestrank()
{
    for(int i=0;i<v.size();++i)
    {
        int brank=9999;
        for(int j=0;j<4;++j)
        {
            if(v[i].rank[j]<brank)
            {
                brank=v[i].rank[j];
                v[i].index=j;
            }
        }
        v[i].bestrank=brank;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        Stu s;
        cin>>s.id>>s.score[1]>>s.score[2]>>s.score[3];
        s.score[0]=(s.score[1]+s.score[2]+s.score[3])/3;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),comp_e);
    adj(3);
    sort(v.begin(),v.end(),comp_m);
    adj(2);
    sort(v.begin(),v.end(),comp_c);
    adj(1);
    sort(v.begin(),v.end(),comp_a);
    adj(0);
    bestrank();
    for(int i=0;i<v.size();++i)
    {
        Map[v[i].id]=v[i];
    }
    for(int i=0;i<m;++i)
    {
        string id;
        cin>>id;
        if(Map[id].bestrank>0)
            cout<<Map[id].bestrank<<" "<<course[Map[id].index]<<endl;
        else
            cout<<"N/A"<<endl;
    }
    return 0;
}
