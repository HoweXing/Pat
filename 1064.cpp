#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

struct Range
{
    int l,r;
};

int n;
vector<int> v,re;
queue<Range> q;

bool is2m(int num)
{
    for(int i=2;i<1000;i*=2)
    {
        if(num==i)
            return true;
    }
    return false;
}

int s2qrt(int num)
{
    int cnt=0;
    while(num>1)
    {
        ++cnt;
        num>>=1;
    }
    return cnt;
}

int maxminnum(int num)
{
    for(int i=2;i<2000;i*=2)
    {
        if(i>num)
            return i/2;
    }
    return 1;
}

void getroot(int l, int r)
{
    if(l>r)
        return;
    Range leftrange,rightrange;
    int size=r-l+1,mid;
    if(is2m(size+1))
    {
        mid=(l+r)/2;
        re.push_back(v[mid]);
    }
    else
    {
        int bsize=maxminnum(size)-1;
        int over=size-bsize;
        int lastlevel=pow(2,s2qrt(bsize+1));
        int rightchild=over-lastlevel/2;
        mid=r-(bsize-1)/2;
        if(rightchild>0)
            mid-=rightchild;
        re.push_back(v[mid]);
    }

    leftrange.l=l;
    leftrange.r=mid-1;
    rightrange.l=mid+1;
    rightrange.r=r;
    q.push(leftrange);
    q.push(rightrange);
}

int main()
{
    scanf("%d",&n);
    int tmp;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&tmp);
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    Range rootrange;
    rootrange.l=0;
    rootrange.r=n-1;
    q.push(rootrange);
    while(!q.empty())
    {
        Range cur=q.front();
        q.pop();
        getroot(cur.l,cur.r);
    }
    for(int i=0;i<re.size();++i)
    {
        if(i>0)
            printf(" ");
        printf("%d",re[i]);
    }
    printf("\n");
    return 0;
}
