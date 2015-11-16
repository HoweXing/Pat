#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int Left[101],Right[101];
int LeftNum[101];

int travel(int root, int parln)
{
    if(root==-1)
        return 0;
    int cnt=0;
    cnt+=travel(Left[root],parln);
    LeftNum[root]=cnt+parln;
    cnt+=travel(Right[root],LeftNum[root]+1);
    return cnt+1;
}

int main()
{
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>Left[i]>>Right[i];
    }
    for(int i=0;i<n;++i)
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    travel(0,0);
    sort(v.begin(),v.end());
    queue<int> q;
    q.push(0);
    vector<int> re;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        re.push_back(v[LeftNum[cur]]);
        if(Left[cur]!=-1)
            q.push(Left[cur]);
        if(Right[cur]!=-1)
            q.push(Right[cur]);
    }
    for(int i=0;i<re.size();++i)
    {
        if(i!=0)
            printf(" ");
        printf("%d",re[i]);
    }
    printf("\n");
    return 0;
}
