#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

struct CompNode
{
    string str;
    int cnt;
};

bool comp(const CompNode &a, const CompNode &b)
{
    if(a.cnt!=b.cnt)
        return a.cnt>b.cnt;
    return a.str<b.str;
}

map<string,int> Map;
map<string,int>::iterator mit;
string src;
char buf[1048577];
vector<CompNode> v;

void tolower(string &str)
{
    for(int i=0;i<str.size();++i)
    {
        if(str[i]>='A'&&str[i]<='Z')
            str[i]+=32;
    }
}

bool ischr(char c)
{
    if(c>='A'&&c<='Z')
        return true;
    if(c>='a'&&c<='z')
        return true;
    if(c>='0'&&c<='9')
        return true;
    return false;
}

int main()
{
    gets(buf);
    src=buf;
    int begin=0,end=0;
    string can;
    for(int i=0;i<src.size();++i)
    {
        if(!ischr(src[i]))
        {
            end=i;
            if(end-begin>=1)
            {
                can=src.substr(begin,end-begin);
                tolower(can);
                Map[can]++;
            }
            begin=end+1;
        }
    }
    if(src.size()==1)
    {
        tolower(src);
        Map[src]++;
    }
    for(mit=Map.begin();mit!=Map.end();++mit)
    {
        CompNode cn;
        cn.str=mit->first;
        cn.cnt=mit->second;
        v.push_back(cn);
    }
    sort(v.begin(),v.end(),comp);
    printf("%s %d\n",v[0].str.c_str(),v[0].cnt);
    return 0;
}
