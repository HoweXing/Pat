#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

char s[4][65];
int len[4];
string day[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main()
{
    for(int i=0;i<4;++i)
    {
        gets(s[i]);
        len[i]=strlen(s[i]);
    }
    int len1=(len[0]<len[1])?len[0]:len[1];
    int len2=(len[2]<len[3])?len[2]:len[3];
    int walk=0;
    for(;walk<len1;++walk)
    {
        if(s[0][walk]==s[1][walk] && s[0][walk]>='A' &&s[0][walk]<='G')
            break;
    }
    printf("%s ",day[s[0][walk]-'A'].c_str());
    for(++walk;walk<len1;++walk)
    {
        if(s[0][walk]==s[1][walk] && ((s[0][walk]>='0'&&s[0][walk]<='9') || (s[0][walk]>='A'&&s[0][walk]<='N')) )
            break;
    }
    if(s[0][walk]>='0'&&s[0][walk]<='9')
        printf("%02d:",s[0][walk]-'0');
    else
        printf("%02d:",s[0][walk]-'A'+10);
    walk=0;
    for(;walk<len2;++walk)
    {
        if(s[2][walk]==s[3][walk] && ((s[2][walk]>='a'&&s[2][walk]<='z')||(s[2][walk]>='A'&&s[2][walk]<='Z')) )
            break;
    }
    printf("%02d\n",walk);
    return 0;
}
