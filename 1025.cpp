#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

struct Rank{
    string id;
    double score;
    int frank,lrank,loc;
};

bool comp(const Rank &a, const Rank &b)
{
    if(a.score!=b.score)
        return a.score>b.score;
    return a.id<b.id;
}

int n,k;
vector<Rank> v[101],result,tmp;
int p[101];

vector<Rank> FindFront()
{
    vector<Rank> re;
    int maxscore=0;
    for(int i=1;i<=n;++i)
    {
        if(p[i]>=v[i].size())
            continue;
        if(v[i][p[i]].score>maxscore)
        {
            maxscore=v[i][p[i]].score;
            re.clear();
            re.push_back(v[i][p[i]]);
            p[i]++;
        }
        else if(v[i][p[i]].score==maxscore)
        {
            re.push_back(v[i][p[i]]);
            p[i]++;
        }
        if(p[i]<v[i].size() && v[i][p[i]].score==maxscore)
            --i;
    }
    sort(re.begin(),re.end(),comp);
    return re;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>k;
        for(int j=0;j<k;++j)
        {
            Rank r;
            cin>>r.id>>r.score;
            r.loc=i;
            v[i].push_back(r);
        }
        sort(v[i].begin(),v[i].end(),comp);
        for(int j=0;j<v[i].size();++j)
        {
            if(j>0 && v[i][j].score==v[i][j-1].score)
                v[i][j].lrank=v[i][j-1].lrank;
            else
                v[i][j].lrank=j+1;
        }
    }
    for(int i=1;i<=n;++i)
        p[i]=0;
    /*while(1)
    {
        tmp=FindFront();
        if(tmp.size()==0)
            break;
        for(int i=0;i<tmp.size();++i)
            result.push_back(tmp[i]);
        tmp.clear();
    }*/
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<v[i].size();++j)
            result.push_back(v[i][j]);
    }
    sort(result.begin(),result.end(),comp);
    printf("%d\n",result.size());
    for(int i=0;i<result.size();++i)
    {
        if(i>0 && result[i].score==result[i-1].score)
            result[i].frank=result[i-1].frank;
        else
            result[i].frank=i+1;
        printf("%s %d %d %d\n",result[i].id.c_str(),result[i].frank,result[i].loc,result[i].lrank);
    }
    return 0;
}
