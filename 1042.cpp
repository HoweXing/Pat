#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char src[55][4],dst[55][4];
char chr[5]={'S','H','C','D','J'};
int pos[55];

void shuffling()
{
    for(int i=1;i<55;++i)
        strcpy(dst[pos[i]],src[i]);
    for(int i=1;i<55;++i)
        strcpy(src[i],dst[i]);
}

int main()
{
    int n;
    for(int i=0;i<5;++i)
    {
        for(int j=1;j<=13;++j)
        {
            if(i==4&&j>2)
                break;
            sprintf(src[i*13+j],"%c%d",chr[i],j);
        }
    }
    scanf("%d",&n);
    for(int i=1;i<55;++i)
        scanf("%d",&pos[i]);
    for(int i=0;i<n;++i)
        shuffling();
    for(int i=1;i<55;++i)
    {
        if(i>1)
            printf(" ");
        printf("%s",dst[i]);
    }
    printf("\n");
    return 0;
}
