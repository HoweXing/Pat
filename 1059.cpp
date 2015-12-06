#include <stdio.h>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int n;
vector<int> Prime;
vector<int>::iterator vit;
map<int,int> Map;
map<int,int>::iterator mit;

bool isprime(int num)
{
    if(num==0||num==1)
        return false;
    if(num==2)
        return true;
    for(int i=2;i<=sqrt(num);++i)
    {
        if(num%i==0)
            return false;
    }
    return true;
}

int main()
{
    scanf("%d",&n);
    for(int i=2;i<=2000;++i)
    {
        if(isprime(i))
            Prime.push_back(i);
    }
    int maxprime=Prime[Prime.size()-1];
    int num=n;
    while(n>1)
    {
        for(vit=Prime.begin();vit!=Prime.end();)
        {
            if(n%(*vit)!=0)
                vit=Prime.erase(vit);
            else
            {
                Map[*vit]++;
                n/=(*vit);
            }
        }
        if(vit==Prime.end())
        {
            if(isprime(n))
            {
                Map[n]++;
                n=1;
            }
            else
            {
                for(int i=maxprime+1;i<sqrt(n);++i)
                {
                    if(isprime(i))
                        Prime.push_back(i);
                }
            }
        }
    }
    if(num==1)
        printf("1=1\n");
    else
    {
        printf("%d=",num);
        for(mit=Map.begin();mit!=Map.end();++mit)
        {
            if(mit!=Map.begin())
                printf("*");
            printf("%d",mit->first);
            if(mit->second>1)
                printf("^%d",mit->second);
        }
    }
    return 0;
}
