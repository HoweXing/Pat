#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

string crt[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main()
{
    string line;
    cin>>line;
    int sum=0;
    for(int i=0;i<line.size();++i)
        sum+=line[i]-'0';
    string s[102];
    int top=-1;
    if(sum==0)
        s[++top]="zero";
    while(sum>0)
    {
        s[++top]=crt[sum%10];
        sum/=10;
    }
    for(int i=top;i>=0;--i)
    {
        if(i!=top)
            printf(" ");
        printf("%s",s[i].c_str());
    }
    printf("\n");
    return 0;
}
