#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

struct Cus{
    int h,m,s;
    int arrive,p,wait;
    bool operator < (const Cus &other) const
    {
        return arrive>other.arrive;
    }
};

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    getchar();
    char line[20];
    priority_queue<Cus> q;
    for(int i=0;i<n;++i)
    {
        gets(line);
        Cus c;
        sscanf(line,"%d:%d:%d %d",&c.h,&c.m,&c.s,&c.p);
        c.arrive=c.h*3600+c.m*60+c.s;
        q.push(c);
    }
    priority_queue<int> servered;
    int total=0,cnt=0;
    while(!q.empty())
    {
        Cus cur=q.top();
        q.pop();
        if(cur.arrive>17*3600)
            break;
        ++cnt;
        if(servered.size()==k)
        {
            int firstok=-servered.top();
            servered.pop();
            cur.wait=(firstok>cur.arrive)?(firstok-cur.arrive):0;
        }
        else
        {
            if(cur.arrive<8*3600)
                cur.wait=8*3600-cur.arrive;
            else
                cur.wait=0;
        }
        servered.push(-(cur.arrive+cur.wait+cur.p*60));
        total+=cur.wait;
    }
    printf("%.1f\n",(double)total/60/cnt);
    return 0;
}
