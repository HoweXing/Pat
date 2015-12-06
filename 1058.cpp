#include <stdio.h>

int num[6];

int main()
{
    for(int i=0;i<6;++i)
    {
        scanf("%d",&num[i]);
        getchar();
    }
    for(int i=0;i<3;++i)
        num[i]+=num[i+3];
    for(int i=2;i>0;--i)
    {
        if(i==2 && num[i]>=29)
        {
            num[i-1]+=num[i]/29;
            num[i]=num[i]%29;
        }
        else if(i==1 && num[i]>=17)
        {
            num[i-1]+=num[i]/17;
            num[i]=num[i]%17;
        }
    }
    for(int i=0;i<3;++i)
    {
        if(i>0)
            printf(".");
        printf("%d",num[i]);
    }
    printf("\n");
    return 0;
}
