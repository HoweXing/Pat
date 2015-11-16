#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
using namespace std;

map<int,vector<int> > Map;
vector<vector<int> > v;
vector<int> tmp;
vector<int> cv;
int n,k,p;

int sum=0;
void Go(int cur)
{
    /*cout<<sum<<" "<<tmp.size()<<" "<<cur<<" : ";
    for(int i=0;i<tmp.size();++i)
        cout<<tmp[i]<<" ";
    cout<<endl;*/
    //system("pause");
    if(sum>n||tmp.size()>k)
        return;

    if(sum==n&&tmp.size()==k)
        v.push_back(tmp);

    if(tmp.size()>=k)
        return;

    if(cur==cv.size()-2)
    {
        int remain=k-tmp.size();
        vector<int> pushnum;
        for(int i=0;i<=remain;++i)
        {
            if(cv[cur]*i+cv[cur+1]*(remain-i)+sum==n)
                pushnum.push_back(i);
        }
        if(pushnum.size()==0)
            return;
        int num1=(int)pow((double)cv[cur],(double)1.0/p);
        int num2=(int)pow((double)cv[cur+1],(double)1.0/p);
        for(int i=0;i<pushnum.size();++i)
        {
            for(int j=0;j<pushnum[i];++j)
                tmp.push_back(num1);
            for(int j=0;j<remain-pushnum[i];++j)
                tmp.push_back(num2);
            v.push_back(tmp);
            for(int j=0;j<remain;++j)
                tmp.pop_back();
        }
    }
    else if(cur==cv.size()-1)
    {
        int remain=k-tmp.size();
        if(sum+remain*cv[cur]!=n)
            return;
        for(int i=0;i<remain;++i)
            tmp.push_back(cv[cur]);
        v.push_back(tmp);
        for(int i=0;i<remain;++i)
            tmp.pop_back();
    }
    else
    {
        for(int i=cur;i<cv.size();++i)
        {
            if(sum+cv[i]>n)
                continue;
            double num=pow((double)cv[i],(double)1.0/p);
            int tnum=(int)num;
            tmp.push_back(tnum);
            sum+=cv[i];
            Go(i);
            sum-=cv[i];
            tmp.pop_back();
        }
    }
}

bool comp(const vector<int> a, const vector<int> b)
{
    int sum1=0,sum2=0;
    for(int i=0;i<a.size();++i)
    {
        sum1+=a[i];
        sum2+=b[i];
    }
    if(sum1!=sum2)
        return sum1>sum2;
    int k=-1;
    for(int i=0;i<a.size();++i)
    {
        if(a[i]==b[i])
        {
            k=i;
            break;
        }
    }
    if(k==-1)
        return true;
    for(int i=k+1;i<a.size();++i)
    {
        if(a[i]>b[i])
            return true;
        else
            return false;
    }
    return true;
}

int main()
{
    for(int i=20;i>=1;--i)
        Map[2].push_back(pow(i,2));
    for(int i=7;i>=1;--i)
        Map[3].push_back(pow(i,3));
    for(int i=4;i>=1;--i)
        Map[4].push_back(pow(i,4));
    for(int i=3;i>=1;--i)
        Map[5].push_back(pow(i,5));
    for(int i=2;i>=1;--i)
        Map[6].push_back(pow(i,6));
    Map[7].push_back(128);
    Map[7].push_back(1);
    cin>>n>>k>>p;
    int start=0;
    while(Map[p][start]>n&&start<Map[p].size())
        ++start;
    for(int i=start;i<Map[p].size();++i)
        cv.push_back(Map[p][i]);
    Go(0);
    if(v.size()==0)
        printf("Impossible\n");
    else
    {
        sort(v.begin(),v.end(),comp);
        printf("%d = ",n);
        for(int j=0;j<v[0].size();++j)
        {
            if(j!=0)
                printf(" + ");
            printf("%d^%d",v[0][j],p);
        }
        printf("\n");
    }
    return 0;
}
