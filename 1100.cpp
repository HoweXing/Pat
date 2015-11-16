#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>
#include <string.h>
using namespace std;

string low[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string high[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
map<string,int> mlow,mhigh;

void mtoe(char *line)
{
    char lowchar[5],highchar[5];
    int blank=-1;
    for(int i=0;i<strlen(line);++i)
    {
        if(line[i]==' ')
        {
            blank=i;
            break;
        }
    }
    if(blank!=-1)
    {
        sscanf(line,"%s %s",highchar,lowchar);
        string low_str=lowchar;
        string high_str=highchar;
        //cout<<low_str<<" "<<high_str<<endl;
        int num=mhigh[high_str]*13+mlow[low_str];
        printf("%d\n",num);
    }
    else
    {
        string sigle=line;
        int h=mhigh[sigle];
        int l=mlow[sigle];
        if(h==0&&l==0)
            printf("0\n");
        else if(h>0)
            cout<<h*13<<endl;
        else
            cout<<l<<endl;
    }
}

void etom(char *line)
{
    int num=atoi(line);
    int high_num=num/13;
    int low_num=num%13;
    if(high_num>0&&low_num>0)
        cout<<high[high_num]<<" "<<low[low_num]<<endl;
    if(high_num==0&&low_num==0)
        cout<<"tret"<<endl;
    if(high_num>0&&low_num==0)
        cout<<high[high_num]<<endl;
    if(high_num==0&&low_num>0)
        cout<<low[low_num]<<endl;
}

int main()
{
    for(int i=1;i<=12;++i)
        mhigh[high[i]]=i;
    for(int i=0;i<=12;++i)
        mlow[low[i]]=i;
    int n;
    char line[10];
    cin>>n;
    getchar();
    for(int i=0;i<n;++i)
    {
        gets(line);
        if(line[0]>='0'&&line[0]<='9')
            etom(line);
        else
            mtoe(line);
    }
    return 0;
}
