#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    long long At=0,a=0,t=0;
    long long cnt=0;
    for(int i=str.size()-1;i>=0;--i)
    {
        if(str[i]=='T')
            ++t;
        if(str[i]=='A')
            ++a;
        if(str[i]=='A')
        {
            At+=t;
        }
        if(str[i]=='P')
        {
            cnt+=At;
        }
    }
    cout<<cnt%1000000007<<endl;
    return 0;
}
