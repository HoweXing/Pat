#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=(s.size()-1)/3;
    int side=n;
    int but=s.size()-2*side;
    for(int i=0;i<side;++i)
    {
        printf("%c",s[i]);
        for(int j=0;j<but-2;++j)
            printf(" ");
        printf("%c\n",s[s.size()-1-i]);
    }
    for(int i=side;i<s.size()-side;++i)
        printf("%c",s[i]);
    printf("\n");
    return 0;
}
