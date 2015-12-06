#include <stdio.h>
#include <set>
using namespace std;

int n,m,k,tmp;
set<int> Set[51];
set<int>::iterator sit1,sit2;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&tmp);
            Set[i].insert(tmp);
        }
    }
    scanf("%d",&k);
    int s1,s2;
    while(k--)
    {
        scanf("%d%d",&s1,&s2);
        sit1=Set[s1].begin();
        sit2=Set[s2].begin();
        int same=0,total=0;
        while(sit1!=Set[s1].end() && sit2!=Set[s2].end())
        {
            if(*sit1!=*sit2)
            {
                if(*sit1<*sit2)
                {
                    ++total;
                    ++sit1;
                }
                else
                {
                    ++total;
                    ++sit2;
                }
            }
            else
            {
                ++same;
                ++total;
                ++sit1;
                ++sit2;
            }
        }
        while(sit1!=Set[s1].end())
        {
            ++total;
            ++sit1;
        }
        while(sit2!=Set[s2].end())
        {
            ++total;
            ++sit2;
        }
        printf("%.1f%%\n",(double)same/total*100);
    }
    return 0;
}
