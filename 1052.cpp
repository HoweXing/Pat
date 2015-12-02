#include <stdio.h>
#include <map>
using namespace std;

struct Node{
    int add,next,key;
};

int n,start,key;
map<int,Node> Map;
map<int,Node>::iterator mit;
map<int,Node>::reverse_iterator rmit;
Node tmp[100001];

int main()
{
    scanf("%d%d",&n,&start);
    for(int i=0;i<n;++i)
    {
        Node a;
        scanf("%d%d%d",&a.add,&a.key,&a.next);
        tmp[a.add]=a;
    }
    int walk=start;
    while(walk!=-1)
    {
        Map[tmp[walk].key]=tmp[walk];
        walk=tmp[walk].next;
    }
    int next=-1;
    for(rmit=Map.rbegin();rmit!=Map.rend();++rmit)
    {
        rmit->second.next=next;
        next=rmit->second.add;
    }
    if(Map.size()>0)
    {
        mit=Map.begin();
        printf("%d %05d\n",Map.size(),mit->second.add);
    }
    else
        printf("%d -1\n",Map.size());
    for(mit=Map.begin();mit!=Map.end();++mit)
    {
        if(mit->second.next!=-1)
            printf("%05d %d %05d\n",mit->second.add,mit->first,mit->second.next);
        else
            printf("%05d %d %d\n",mit->second.add,mit->first,mit->second.next);
    }
    return 0;
}
