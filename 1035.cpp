#include <stdio.h>
#include <string.h>

char name[1001][11],pwd[1001][11];
bool modified[1001];

bool needModify(char *str)
{
    bool flag=false;
    for(int i=0;i<strlen(str);++i)
    {
        switch(str[i])
        {
            case '1':str[i]='@';flag=true;break;
            case '0':str[i]='%';flag=true;break;
            case 'l':str[i]='L';flag=true;break;
            case 'O':str[i]='o';flag=true;break;
        }
    }
    return flag;
}

int n,cnt=0;

int main()
{
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;++i)
    {
        scanf("%s %s",name[i],pwd[i]);
        bool f=needModify(pwd[i]);
        modified[i]=f;
        if(f)
            ++cnt;
    }
    if(cnt==0)
    {
        if(n==1)
            printf("There is 1 account and no account is modified\n");
        else
            printf("There are %d accounts and no account is modified\n",n);
    }
    else
    {
        printf("%d\n",cnt);
        for(int i=0;i<n;++i)
        {
            if(modified[i])
            {
                printf("%s %s\n",name[i],pwd[i]);
            }
        }
    }
    return 0;
}
