#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct App{
    int id,ge,gi,sum;
    vector<int> prefer;
};

bool comp(const App &a, const App &b)
{
    if(a.sum!=b.sum)
        return a.sum>b.sum;
    else
        return a.ge>b.ge;
}

App Array[40001];

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int *school = new int[m];
    int *lastsum = new int[m];
    int *lastge = new int[m];
    vector<int> *v = new vector<int>[m];
    for(int i=0;i<m;++i)
        cin>>school[i];
    for(int i=0;i<n;++i)
    {
        Array[i].id=i;
        cin>>Array[i].ge>>Array[i].gi;
        Array[i].sum = Array[i].ge + Array[i].gi;
        for(int j=0;j<k;++j)
        {
            int tint;
            cin>>tint;
            Array[i].prefer.push_back(tint);
        }
    }
    sort(Array,Array+n,comp);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<k;++j)
        {
            int sid = Array[i].prefer[j];
            if(school[sid]>0)
            {
                --school[sid];
                lastsum[sid]=Array[i].sum;
                lastge[sid]=Array[i].ge;
                v[sid].push_back(Array[i].id);
                break;
            }
            else if(Array[i].sum==lastsum[sid] && Array[i].ge == lastge[sid])
            {
                v[sid].push_back(Array[i].id);
                break;
            }
        }
    }
    for(int i=0;i<m;++i)
    {
        sort(v[i].begin(),v[i].end());
        for(int j=0;j<v[i].size();++j)
        {
            if(j>0)
                printf(" ");
            printf("%d",v[i][j]);
        }
        printf("\n");
    }
    return 0;
}
