#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

string src;
char buf[30000];
int point,e,more_l=0,more_r=0,rightmove=0;
string left,right;

void trim(string &s)
{
    int begin=0;
    for(;begin<s.size();++begin)
    {
        if(s[begin]!='0')
            break;
    }
    s=s.substr(begin,s.size());
}

int main()
{
    gets(buf);
    src=buf;
    if(src[0]=='-')
        printf("%c",src[0]);
    e=src.find("E");
    left=src.substr(1,e-1);
    right=src.substr(e+1,src.size());
    rightmove=atoi(right.c_str());
    point=left.find(".");
    if(rightmove>0)
    {
        while(rightmove>0 && point<left.size()-1)
        {
            char tmp=left[point];
            left[point]=left[point+1];
            left[point+1]=tmp;
            --rightmove;
            ++point;
        }
        if(rightmove==0)
        {
            if(point==left.size()-1)
                printf("%s\n",left.substr(0,left.size()-1).c_str());
            else
            {
                trim(left);
                printf("%s\n",left.c_str());
            }
        }
        else
            printf("%s%s\n",left.substr(0,left.size()-1).c_str(),string(rightmove,'0').c_str());
   }
    else
    {
        while(rightmove<0 && point>0)
        {
            char tmp=left[point];
            left[point]=left[point-1];
            left[point-1]=tmp;
            ++rightmove;
            --point;
        }
        if(rightmove==0)
            printf("0.%s\n",left.substr(1,left.size()).c_str());
        else
            printf("0.%s%s\n",string(0-rightmove,'0').c_str(),left.substr(1,left.size()).c_str());
    }
    return 0;
}
