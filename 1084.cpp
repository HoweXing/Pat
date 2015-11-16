#include <iostream>
#include <string.h>
#include <vector>
#include <set>
using namespace std;

int main()
{
    char s1[81],s2[81];
    cin>>s1>>s2;
    int h1=0,len1=strlen(s1);
    int h2=0,len2=strlen(s2);
    vector<char> non;
    set<char> ed;
    while(h1<len1&&h2<len1)
    {
        //cout<<h1<<" "<<h2<<" "<<non.size()<<endl;
        if(s1[h1]==s2[h2])
        {
            ++h1;
            ++h2;;
        }
        else
        {
            int c=s1[h1];
            if(s1[h1]>='a'&&s1[h1]<='z')
                c+='A'-'a';
            if(ed.find(c)==ed.end())
            {
                non.push_back(c);
                ed.insert(c);
            }
            ++h1;
        }
    }
    if(h1<len1)
    {
        int c=s1[h1];
        if(s1[h1]>='a'&&s1[h1]<='z')
            c+='a'-'A';
        if(ed.find(c)!=ed.end())
        {
            non.push_back(c);
            ed.insert(c);
        }
        ++h1;
    }
    for(int i=0;i<non.size();++i)
        cout<<non[i];
    cout<<endl;
}
