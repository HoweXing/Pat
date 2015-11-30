#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

string src,lstr,rstr;

int main()
{
    cin>>src;
    int total=0,base=1;
    int len=src.size();
    for(int i=0;i<len;++i)
    {
        lstr=src.substr(0,i);
        rstr=src.substr(i+1,len);
        int lnum=atoi(lstr.c_str());
        int rnum=atoi(rstr.c_str());
        int base=pow(10,len-1-i);
        total+=base*lnum;
        if(src[i]=='1')
            total+=rnum+1;
        else if(src[i]>'1')
            total+=base;
    }
    printf("%d\n",total);
    return 0;
}
