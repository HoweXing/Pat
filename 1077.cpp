#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    scanf("%d\n",&num);
    char **str = new char*[num];
    char **iestr = new char*[num];
    int minlen=999;
    for(int i=0;i<num;++i)
    {
        str[i]=new char[260];
        iestr[i]=new char[260];
        gets(str[i]);
        //scanf("%s\n",str[i]);
        //printf("input %s\n",str[i]);
        int k=0;
        for(int j=strlen(str[i])-1;j>=0;--j,++k)
        {
            iestr[i][k]=str[i][j];
        }
        iestr[i][k]='\0';
        if(k<minlen)
            minlen=k;
    }
    char same[260];
    int i;
    for(i=0;i<minlen;++i)
    {
        bool flag=true;
        for(int j=0;j<num-1;++j)
        {
            if(iestr[j][i]!=iestr[j+1][i])
                flag=false;
        }
        if(flag)
            same[i]=iestr[0][i];
        else
            break;
    }
    same[i]='\0';
    char re[260];
    if(i==0)
    {
        sprintf(re,"nai");
        //printf("%s\n",same);
    }
    else
    {
        //printf("%s\n",same);
        i=0;
        for(int j=strlen(same)-1;j>=0;--j,++i)
            re[i]=same[j];
        re[i]='\0';
    }
    printf("%s\n",re);
}
