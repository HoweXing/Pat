#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
using namespace std;

vector<int> pre,in;
set<int> used,re;
int p=0;
vector<int> result;

void post(int pre_s, int pre_e, int in_s, int in_e)
{
    //cout<<pre_s<<" "<<pre_e<<" "<<in_s<<" "<<in_e<<endl;
    //getchar();
    if(in_s==in_e)
        result.push_back(in[in_s]);
    else
    {
        int val = pre[pre_s];
        int in_mid = in_s;
        while(in[in_mid]!=val)
            ++in_mid;
        if(in_mid>in_s)
            post(pre_s+1, pre_s+in_mid-in_s, in_s, in_mid-1);
        if(in_mid<in_e)
            post(pre_s+in_mid-in_s+1, pre_e, in_mid+1, in_e);
        result.push_back(in[in_mid]);
    }
}

int main()
{
    int n,id;
    char line[20];
    stack<int> s;
    cin>>n;
    if(n==0)
        return 0;
    getchar();
    for(;in.size()<n;)
    {
        gets(line);
        if(line[1]=='u')
        {
            sscanf(line,"Push %d",&id);
            pre.push_back(id);
            s.push(id);
        }
        else
        {
            in.push_back(s.top());
            s.pop();
        }
    }
    post(0, pre.size()-1, 0, in.size()-1);
    for(int i=0;i<result.size();++i)
    {
        if(i!=0)
            cout<<" ";
        cout<<result[i];
    }
    cout<<endl;
    //getchar();
}
