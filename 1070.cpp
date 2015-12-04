#include <stdio.h>
#include <algorithm>
using namespace std;

struct Mooncake
{
    double count,price,price_single;
};

int n,d;
Mooncake mc[1001];

bool comp(const Mooncake &a, const Mooncake &b)
{
    return a.price_single>b.price_single;
}

int main()
{
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;++i)
        scanf("%lf",&mc[i].count);
    for(int i=0;i<n;++i)
    {
        scanf("%lf",&mc[i].price);
        mc[i].price_single=mc[i].price/mc[i].count;
    }
    sort(mc,mc+n,comp);
    double total=0;
    int k=0;
    while(d>0&&k<n)
    {
        if(d>=mc[k].count)
        {
            d-=mc[k].count;
            total+=mc[k].price;
        }
        else
        {
            total+=mc[k].price*(d/mc[k].count);
            d=0;
        }
        ++k;
    }
    printf("%.2f\n",total);
    return 0;
}
