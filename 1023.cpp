#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

string Multi2(string num)
{
    char line[25];
    memset(line,'0',sizeof(char)*25);
    int k=0,i;
    for(i=num.size()-1;i>=0;--i)
        line[k++]=num[i];
    int c=0;
    for(i=0;;++i)
    {
        int tmp=line[i]-'0';
        tmp*=2;
        tmp+=c;
        line[i]='0'+tmp%10;
        c=tmp/10;
        if(i>=(k-1)&&c==0)
            break;
    }
    char multi2[25];
    k=0;
    for(int j=i;j>=0;--j)
        multi2[k++]=line[j];
    multi2[k]='\0';
    string re=multi2;
    return re;
}

int main()
{
    string num;
    cin>>num;
    int digit[10];
    memset(digit,0,sizeof(int)*10);
    string multi2=Multi2(num);
    for(int i=0;i<num.size();++i)
        digit[num[i]-'0']++;
    for(int i=0;i<multi2.size();++i)
        digit[multi2[i]-'0']--;
    bool flag=true;
    for(int i=0;i<10;++i)
    {
        if(digit[i]!=0)
        {
            flag=false;
            break;
        }
    }
    if(flag)
        printf("Yes\n");
    else
        printf("No\n");
    printf("%s\n",multi2.c_str());
    return 0;
}
