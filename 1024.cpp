#include <iostream>
#include <string>
using namespace std;

string Step(string num)
{
    string rev;
    for(int i=num.size()-1;i>=0;--i)
        rev.push_back(num[i]);
    int k=0,c=0,tmp=0;
    while(1)
    {
        tmp=num[k]-'0'+rev[k]-'0'+c;
        rev[k]='0'+tmp%10;
        c=tmp/10;
        if(k==num.size()-1)
        {
            if(c>0)
                rev.push_back(c+'0');
            break;
        }
        ++k;
    }
    string re;
    for(int i=rev.size()-1;i>=0;--i)
        re.push_back(rev[i]);
    return re;
}

bool Palin(string num)
{
    int i=0,j=num.size()-1;
    bool flag=true;
    while(i<=j)
    {
        if(num[i]!=num[j])
        {
            flag=false;
            break;
        }
        ++i;
        --j;
    }
    return flag;
}

int main()
{
    string num;
    int round;
    cin>>num>>round;
    int step=0;
    for(;step<round;++step)
    {
        if(Palin(num))
            break;
        num=Step(num);
    }
    cout<<num<<endl<<step<<endl;
    return 0;
}
