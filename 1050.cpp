#include <stdio.h>
#include <string.h>

char s1[10001],s2[10001];
int flag[128]={0};

int main()
{
    gets(s1);
    gets(s2);
    int len1=strlen(s1),len2=strlen(s2);
    for(int i=0;i<len2;++i)
        flag[s2[i]]=1;
    for(int i=0;i<len1;++i)
    {
        if(flag[s1[i]]==0)
            printf("%c",s1[i]);
    }
    printf("\n");
    return 0;
}
