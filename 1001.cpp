#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    a+=b;
    b=a;
    a=abs(a);
    char stack[12],re[20];
    int top=-1,rtop=-1;
    do
    {
        stack[++top]='0'+a%10;
        a/=10;
    }while(a>0);
    int cnt=0;
    for(int i=0;i<=top;++i)
    {
        re[++rtop]=stack[i];
        ++cnt;
        if(cnt%3==0&&i!=top)
            re[++rtop]=',';
    }
    if(b<0)
        printf("-");
    for(int i=rtop;i>=0;--i)
        printf("%c",re[i]);
    printf("\n");
    return 0;
}
