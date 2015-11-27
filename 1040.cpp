#include <stdio.h>
#include <string.h>

char str[1001];

int main()
{
    gets(str);
    int len=strlen(str);
    int maxcnt=0;
    for(int i=0;i<len;++i)
    {
        int cnt1=0;
        for(int j=1;i-j>=0&&i+j<len;++j)
        {
            if(str[i-j]!=str[i+j])
                break;
            ++cnt1;
        }
        cnt1=2*cnt1+1;
        int cnt2=0;
        if(i+1<len && str[i]==str[i+1])
        {
            for(int j=1;i-j>=0&&i+j+1<len;++j)
            {
                if(str[i-j]!=str[i+j+1])
                    break;
                ++cnt2;
            }
            cnt2=2*cnt2+2;
        }
        int cnt=(cnt1>cnt2)?cnt1:cnt2;
        if(maxcnt<cnt)
            maxcnt=cnt;
    }
    printf("%d\n",maxcnt);
}
