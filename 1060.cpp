#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n,p1=0,p2=0,f1=0,f2=0,len1,len2;
char s1[101],s2[101],str1[101],str2[101];

int trim(char *s)
{
    int start=0,len=strlen(s),k=0;
    char re[101];
    int pos_point=0,pos_fnz=0;
    while(s[pos_point]!='.' && pos_point<len)
        ++pos_point;
    while((s[pos_fnz]<'1'||s[pos_fnz]>'9') && pos_fnz<len)
        ++pos_fnz;
    if(atof(s)==0)
        re[k++]='0';
    else
    {
        for(int i=pos_fnz;i<len&&k<n;++i)
        {
            if(s[i]=='.')
                continue;
            re[k++]=s[i];
        }
    }
    while(k<n)
        re[k++]='0';
    re[k]='\0';
    strcpy(s,re);
    if(pos_point==pos_fnz || pos_fnz==len)
        return 0;
    else if(pos_point>pos_fnz)
        return pos_point-pos_fnz;
    else
        return pos_point-pos_fnz+1;
}

int main()
{
    scanf("%d %s %s",&n,s1,s2);
    p1=trim(s1);
    p2=trim(s2);
    if(p1!=p2 || strcmp(s1,s2)!=0)
        printf("NO 0.%s*10^%d 0.%s*10^%d\n",s1,p1,s2,p2);
    else
        printf("YES 0.%s*10^%d\n",s1,p1);
    return 0;
}
