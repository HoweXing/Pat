#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

vector<int> v1,v2,v;
int n1,n2,tmp;
int lsk,rsk;

int main()
{
    scanf("%d",&n1);
    for(int i=0;i<n1;++i)
    {
        scanf("%d",&tmp);
        v1.push_back(tmp);
    }
    scanf("%d",&n2);
    for(int i=0;i<n2;++i)
    {
        scanf("%d",&tmp);
        v2.push_back(tmp);
    }
    int total=n1+n2;
    int l1=0,l2=0;
    while(l1<n1 && l2<n2)
    {
        if(v1[l1]<v2[l2])
            v.push_back(v1[l1++]);
        else
            v.push_back(v2[l2++]);
    }
    while(l1<n1)
        v.push_back(v1[l1++]);
    while(l2<n2)
        v.push_back(v2[l2++]);
    printf("%d\n",v[(total-1)/2]);
    return 0;
}
