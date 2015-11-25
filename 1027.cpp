#include <iostream>
#include <stdio.h>
using namespace std;

char itoma(int num)
{
    if(num<10)
        return '0'+num;
    else
        return 'A'+num-10;
}

int main()
{
    int r,g,b;
    cin>>r>>g>>b;
    printf("#%c%c%c%c%c%c\n",itoma(r/13),itoma(r%13),itoma(g/13),itoma(g%13),itoma(b/13),itoma(b%13));
    return 0;
}
