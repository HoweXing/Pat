#include <stdio.h>
#include <map>
using namespace std;

int m,n;
map<int,int> Map;
map<int,int>::iterator mit;

int main()
{
    scanf("%d%d",&m,&n);
    int len=m*n,color;
    for(int i=0;i<len;++i)
    {
        scanf("%d",&color);
        Map[color]++;
    }
    for(mit=Map.begin();mit!=Map.end();++mit)
    {
        if(mit->second>len/2)
        {
            printf("%d\n",mit->first);
            break;
        }
    }
    return 0;
}
