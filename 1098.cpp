#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n,tmp;
vector<int> src,now;
vector<int> sorted,unsorted;
map<int,int> Map;

bool isi()
{
    int k=-1;
    bool flag=true;
    for(int i=1;i<now.size();++i)
    {
        if(now[i]<now[i-1])
        {
            k=i;
            break;
        }
    }
    for(int i=k;i<now.size();++i)
    {
        if(now[i]!=src[i])
        {
            flag=false;
            break;
        }
    }
    if(flag)
        sort(now.begin(),now.begin()+k+1);
    return flag;
}

int part()
{
    map<int,int>::reverse_iterator rit=Map.rbegin();
    int k=-1;
    for(int i=now.size()-1;i>=0&&rit!=Map.rend();--i)
    {
        if(now[i]!=rit->first)
        {
            k=i;
            break;
        }
        Map[now[i]]--;
        if(Map[now[i]]==0)
            ++rit;
    }
    return k;
}

void adjust()
{
    for(int i=0;(i*2+1)<unsorted.size();++i)
    {
        if((i*2+2)<unsorted.size())
        {
            int k=(unsorted[i*2+1]>unsorted[i*2+2])?(i*2+1):(i*2+2);
            if(unsorted[k]>unsorted[i])
            {
                int tmp=unsorted[i];
                unsorted[i]=unsorted[k];
                unsorted[k]=tmp;
            }
        }
        else
        {
            int k=i*2+1;
            if(unsorted[k]>unsorted[i])
            {
                int tmp=unsorted[i];
                unsorted[i]=unsorted[k];
                unsorted[k]=tmp;
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        src.push_back(tmp);
        Map[tmp]++;
    }
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        now.push_back(tmp);
    }
    if(isi())
    {
        printf("Insertion Sort\n");
        for(int i=0;i<now.size();++i)
        {
            if(i!=0)
                printf(" ");
            printf("%d",now[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Heap Sort\n");
        int k=part();
        for(int i=0;i<=k;++i)
            unsorted.push_back(now[i]);
        for(int i=k+1;i<n;++i)
            sorted.push_back(now[i]);
        int next=unsorted[0];
        unsorted[0]=unsorted[unsorted.size()-1];
        unsorted.pop_back();
        adjust();
        vector<int> re;
        for(int i=0;i<unsorted.size();++i)
            re.push_back(unsorted[i]);
        re.push_back(next);
        for(int i=0;i<sorted.size();++i)
            re.push_back(sorted[i]);
        for(int i=0;i<re.size();++i)
        {
            if(i!=0)
                printf(" ");
            printf("%d",re[i]);
        }
        printf("\n");
    }
    return 0;
}
