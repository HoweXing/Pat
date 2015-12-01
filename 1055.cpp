#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;

struct People
{
    char name[9];
    int age,worth;
};

bool comp(const People &a, const People &b)
{
    if(a.worth!=b.worth)
        return a.worth>b.worth;
    if(a.age!=b.age)
        return a.age<b.age;
    else
        return strcmp(a.name,b.name)<0;
}

vector<People> v;

int main()
{
    scanf("%d%d",&n,&k);
    getchar();
    for(int i=0;i<n;++i)
    {
        People p;
        scanf("%s%d%d",p.name,&p.age,&p.worth);
        getchar();
        v.push_back(p);
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<k;++i)
    {
        int m,l,r,tmp;
        scanf("%d%d%d",&m,&l,&r);
        tmp=m;
        printf("Case #%d:\n",i+1);
        for(int j=0;j<n&&m>0;++j)
        {
            if(v[j].age>=l&&v[j].age<=r)
            {
                printf("%s %d %d\n",v[j].name,v[j].age,v[j].worth);
                --m;
            }
        }
        if(m==tmp)
            printf("None\n");
    }
    return 0;
}
