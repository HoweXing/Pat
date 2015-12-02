#include <iostream>
#include <cmath>
#include <stack>
#include <stdio.h>
using namespace std;

bool isprime(int num)
{
    if(num==0||num==1)
        return false;
    for(int i=2;i<=sqrt(num);++i)
    {
        if(num%i==0)
            return false;
    }
    return true;
}

int main()
{
    int num,radix;
    while(cin>>num)
    {
        if(num<0)
            return 0;
        cin>>radix;
        if(!isprime(num))
            printf("No\n");
        else
        {
            stack<int> st;
            while(num>0)
            {
                st.push(num%radix);
                num/=radix;
            }
            int base=1,rnum=0;
            while(!st.empty())
            {
                rnum+=base*st.top();
                st.pop();
                base*=radix;
            }
            if(isprime(rnum))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
