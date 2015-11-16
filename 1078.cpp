#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <math.h>
using namespace std;

bool isprime(int n)
{
    if(n==1||n==0)
        return false;
    if(n==2||n==3)
        return true;
    for(int i=2;i<=(int)sqrt(n);++i)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
   int num,size,tmp;
   vector<int> posv;
   scanf("%d %d",&size,&num);
   for(;!isprime(size);++size);
   int *hash = new int[size];
   for(int i=0;i<size;++i)
    hash[i]=-1;
   for(int i=0;i<num;++i)
   {
       if(i>0)
        printf(" ");
       scanf("%d",&tmp);
       int pos=tmp%size;
       if(hash[pos]==-1)
       {
           hash[pos]=tmp;
          printf("%d",pos);
       }
       else
       {
           bool inserted=false;
           for(int j=1;j<=size;++j)
           {
               int offset=j*j;
               int pos1=(pos+offset)%size;
               if(hash[pos1]==-1)
               {
                   hash[pos1]=tmp;
                   printf("%d",pos1);
                   inserted=true;
                   break;
               }
           }
           if(!inserted)
                printf("-");
       }
       if(i==num-1)
        printf("\n");
   }
}
