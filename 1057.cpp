#include <stdio.h>
#include <string.h>
#define N 100001

int n,stack[N],top=-1;
int c[N];

void add(int pos, int value)
{
    while(pos<N)
    {
        c[pos]+=value;
        pos+=pos&(-pos);
    }
}

int sum(int pos)
{
    int re=0;
    while(pos>0)
    {
        re+=c[pos];
        pos-=pos&(-pos);
    }
    return re;
}

int find(int lnum)
{
    int l=0,r=N-1,median,res;
    while(l<=r)
    {
        median=(l+r)/2;
        res=sum(median);
        if(res<lnum)
            l=median+1;
        else            //key step
            r=median-1;
    }
    return l;
}

int main()
{
    memset(c,0,sizeof(int)*N);
    scanf("%d",&n);
    getchar();
    char line[20];
    int pushnum,popnum;
    for(int i=0;i<n;++i)
    {
        gets(line);
        switch(line[1])
        {
            case 'u':{
                sscanf(line,"Push %d",&pushnum);
                stack[++top]=pushnum;
                add(pushnum,1);
                break;
            }
            case 'o':{
                if(top==-1)
                    printf("Invalid\n");
                else
                {
                    int popnum=stack[top--];
                    add(popnum,-1);
                    printf("%d\n",popnum);
                }
                break;
            }
            case 'e':{
                if(top==-1)
                    printf("Invalid\n");
                else
                {
                    int size=top+1,lnum,l=0;
                    if(size%2==0)
                        lnum=size/2;
                    else
                        lnum=(size+1)/2;
                    printf("%d\n",find(lnum));
                }
                break;
            }
        }
    }
    return 0;
}
