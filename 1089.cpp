#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> src,now;
    int tmp;
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        src.push_back(tmp);
    }
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        now.push_back(tmp);
    }

    bool isi=true;
    int loc=-1;
    for(int i=1;i<n;++i)
    {
        if(now[i]<now[i-1])
        {
            loc=i;
            break;
        }
    }
    //cout<<"loc "<<loc<<endl;
    if(loc!=-1)
    {
        for(int i=loc;i<n;++i)
        {
            if(now[i]!=src[i])
            {
                isi=false;
                break;
            }
        }
    }
    if(isi)
    {
        cout<<"Insertion Sort"<<endl;
        if(loc!=-1)
            sort(now.begin(),now.begin()+loc+1);
        for(int i=0;i<n;++i)
        {
            if(i!=0)
                cout<<" ";
            cout<<now[i];
        }
        cout<<endl;
        return 0;
    }

    cout<<"Merge Sort"<<endl;
    int step;
    bool b=true;
    for(int i=2;i<=n&&b;i*=2)
    {
        for(int j=0;j<n&&b;j+=i)
        {
            bool f=true;
            for(int k=j+1;k<n&&k<i+j&&b;++k)
            {
                //cout<<i<<" "<<j<<" "<<k<<endl;
                if(now[k]<now[k-1])
                {
                    step=i;
                    f=false;
                    break;
                }
            }
            //cout<<f<<endl;
            if(!f)
                b=false;
        }
    }
    //cout<<"step "<<step<<endl;
    //step*=2;
    int s=0,e=step>n?n:step;
    while(e<=n)
    {
        //cout<<s<<" "<<e<<endl;
        sort(now.begin()+s,now.begin()+e);
        if(e==n)
            break;
        s=e;
        e=(e+step)>n?n:(e+step);
    }
    for(int i=0;i<n;++i)
    {
        if(i!=0)
            cout<<" ";
        cout<<now[i];
    }
    cout<<endl;
    return 0;
}
