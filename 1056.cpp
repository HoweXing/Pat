#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int weight[1001],rank[1001];
int n,group,groupnum;
vector<int> src,dst,cmp;

bool comp(const int &a, const int &b)
{
    return weight[a]>weight[b];
}

int main()
{
    scanf("%d%d",&n,&group);
    for(int i=0;i<n;++i)
        scanf("%d",&weight[i]);
    for(int i=0;i<n;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        src.push_back(tmp);
    }
    while(src.size()>1)
    {
        groupnum=src.size()/group;
        if(src.size()>group*groupnum)
            ++groupnum;
        //printf("%d %d\n",src.size(),groupnum);
        int k=0;
        for(int i=0;i<groupnum;++i)
        {
            cmp.clear();
            for(int j=0;j<group&&k<src.size();++j)
                cmp.push_back(src[k++]);
            sort(cmp.begin(),cmp.end(),comp);
            for(int j=1;j<cmp.size();++j)
                rank[cmp[j]]=groupnum+1;
            //printf("push %d\n",cmp[0]);
            dst.push_back(cmp[0]);
        }
        src.clear();
        for(int i=0;i<dst.size();++i)
            src.push_back(dst[i]);
        dst.clear();
        //system("pause");
    }
    rank[src[0]]=1;
    for(int i=0;i<n;++i)
    {
        if(i>0)
            printf(" ");
        printf("%d",rank[i]);
    }
    return 0;
}
