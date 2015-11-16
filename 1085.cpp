#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n,p;
    cin>>n>>p;
    vector<long long> num;
    long long maxnum=0;
    for(long long i=0;i<n;++i)
    {
        long long tmp;
        cin>>tmp;
        num.push_back(tmp);
    }
    sort(num.begin(),num.end());
    long long s=0,e=0;
    for(;s<=e&&s<n&&e<n;)
    {
        //cout<<s<<" "<<e<<" ";
        long long minn=num[s],maxn=num[e];
        //cout<<minn<<" "<<maxn<<endl;
        if(maxn<=minn*p)
        {
            if(e-s+1>maxnum)
                maxnum=e-s+1;
            ++e;
        }
        else
        {
            ++s;
        }
    }
    cout<<maxnum<<endl;
    return 0;
}
