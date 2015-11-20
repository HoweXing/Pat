#include <iostream>
#include <vector>
using namespace std;

int n,radix;
vector<int> v;

int main()
{
    cin>>n>>radix;
    if(n==0)
    {
        cout<<"Yes"<<endl<<"0"<<endl;
        return 0;
    }
    while(n>0)
    {
        v.push_back(n%radix);
        n/=radix;
    }
    int i=0,j=v.size()-1;
    bool palin=true;
    while(i<=j)
    {
        if(v[i]!=v[j])
        {
            palin=false;
            break;
        }
        ++i;
        --j;
    }
    if(palin)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    for(int i=v.size()-1;i>=0;--i)
    {
        if(i!=v.size()-1)
            cout<<" ";
        cout<<v[i];
    }
    cout<<endl;
    return 0;
}
