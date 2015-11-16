#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Player{
    int arrive,s,e;
    int last;
    int tablenum;
    bool vip;
};

struct comp_arrive{
    bool operator()(const Player &a, const Player &b)
    {
        return a.arrive>b.arrive;
    }
};

struct comp_play{
    bool operator()(const Player &a, const Player &b)
    {
        return a.e>b.e;
    }
};

char line[100];
int n,k,m,tmp;
priority_queue<Player,vector<Player>,comp_arrive> arrive,wait,vipwait;
priority_queue<Player,vector<Player>,comp_play> play;
map<int,int> table,viptable,done;
map<int,int>::iterator it;
int ava,vipava;

int findtable(bool vip)
{

}

void check(int now)
{

}

int main()
{
    cin>>n;
    getchar();
    for(int i=0;i<n;++i)
    {
        Player p;
        int hour,minute,second;
        int v;
        gets(line);
        sscanf(line,"%d:%d:%d %d %d",&hour,&minute,&second,&p.last,&v);
        p.vip=(v==1)?true:false;
        p.arrive=(hour-8)*3600+minute*60+second;
        arrive.push(p);
    }
    cin>>k>>m;
    ava=k-m;
    vipava=m;
    for(int i=0;i<m;++i)
    {
        cin>>tmp;
        viptable[tmp1]=1;
    }
    for(int i=1;i<=k;++i)
    {
        if(viptable[i]==0)
            table[i]=1;
    }
    while(!arrive.empty())
    {
        Player cur=arrive.top();
        arrive.pop();
        check(cur.arrive);
        if(cur.vip)
        {
            if(ava==0&&vipava==0)
            {
                wait.push(cur);
                vipwait.push(cur);
            }
            else
            {
                int t=findtable(true);
                if(t>=0)
                    table[t]=0;
                else
                    viptable[-t]=0;
                cur.s=cur.arrive;
                cur.e=cur.s+cur.last;
                cur.tablenum=t>0?t:(-t);
            }
        }
        else
        {
            if()
        }
    }
    return 0;
}
