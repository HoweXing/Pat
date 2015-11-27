#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

vector<string> col;

bool comp(const string &a, const string &b)
{
    int len=(a.size()>b.size())?b.size():a.size();
    for(int i=0;i<len;++i)
    {
        if(a[i]!=b[i])
            return a[i]<b[i];
    }
    if(a.size()>b.size())
    {
        for(int i=0;i<a.size()-b.size();++i)
        {
            if(a[b.size()+i]!=b[i])
                return a[b.size()+i]<b[i];
        }
    }
    else if(a.size()<b.size())
    {
        for(int i=0;i<b.size()-a.size();++i)
        {
            if(a[i]!=b[a.size()+i])
                return a[i]<b[a.size()+i];
        }
    }
    else
        return true;
}

int main()
{
    int n;
    cin>>n;
    //cout<<n<<endl;
    string tmp;
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        //cout<<tmp<<endl;
        col.push_back(tmp);
    }
    sort(col.begin(),col.end(),comp);
    bool nonzero=false;
    for(int i=0;i<n;++i)
    {
        if(!nonzero)
        {
            int j=0;
            for(;j<col[i].size();++j)
            {
                if(col[i][j]!='0')
                    break;
            }
            if(j<col[i].size())
            {
                nonzero=true;
                for(;j<col[i].size();++j)
                    printf("%c",col[i][j]);
            }
        }
        else
            printf("%s",col[i].c_str());
    }
    if(!nonzero)
        printf("0");
    printf("\n");
    return 0;
}
