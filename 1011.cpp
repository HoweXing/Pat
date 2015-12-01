#include <stdio.h>
#include <iostream>
#define NUM 3
using namespace std;

double games[NUM][NUM];

int Best(double *g)
{
    double max=0;
    int id=-1;
    for(int i=0;i<NUM;++i)
    {
        if(g[i]>max)
        {
            max=g[i];
            id=i;
        }
    }
    return id;
}

char crt[NUM]={'W','T','L'};

int main()
{
    double sum=1;
    for(int i=0;i<NUM;++i)
    {
        for(int j=0;j<NUM;++j)
            scanf("%lf",&games[i][j]);
        int id=Best(games[i]);
        printf("%c ",crt[id]);
        sum*=games[i][id];
    }
    sum=sum*0.65;
    sum-=1;
    sum*=2;
    printf("%.2f\n",sum);
    return 0;
}
