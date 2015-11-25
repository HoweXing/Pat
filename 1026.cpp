#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;

struct Player{
    int arrive,start,end,wait,last;
    int tablenum;
    bool vip;
};

struct comp_arrive
{
    bool operator () (const Player &a, const Player &b)
    {
        return a.arrive>b.arrive;
    }
};

struct comp_play
{
    bool operator () (const Player &a, const Player &b)
    {
        return a.end>b.end;
    }
};

struct comp_start
{
    bool operator () (const Player &a, const Player &b)
    {
        return a.start>b.start;
    }
};

priority_queue<Player,vector<Player>,comp_arrive> arrive,wait,vipwait;
priority_queue<Player,vector<Player>,comp_play> play;
priority_queue<Player,vector<Player>,comp_start> done;
//vector<Player> done;
set<int> vipdone;
map<int,int> ntable,viptable,tables;
map<int,int>::iterator mit;

int n,k,m;
int ava,vipava;
int nowtime;

int main()
{
    cin>>n;
    string time;
    int vip;
    for(int i=0;i<n;++i)
    {
        Player p;
        cin>>time>>p.last>>vip;
        if(p.last>120)
            p.last=120;
        p.last*=60;
        p.vip=(vip==1)?true:false;
        p.arrive=((time[0]-'0')*10+time[1]-'0')*3600+((time[3]-'0')*10+time[4]-'0')*60+(time[6]-'0')*10+time[7]-'0';
        arrive.push(p);
    }
    cin>>k>>m;
    ava=k-m;
    vipava=m;
    for(int i=0;i<m;++i)
    {
        int tmp;
        cin>>tmp;
        viptable[tmp]=1;
    }
    for(int i=1;i<=k;++i)
    {
        if(viptable.find(i)==viptable.end())
            ntable[i]=1;
        tables[i]=1;
    }
    for(int nowtime=8*3600;nowtime<21*3600;++nowtime)
    {
        //cout<<nowtime<<endl;
        Player cur;
        while(!play.empty())
        {
            //cout<<" playing"<<endl;
            cur=play.top();
            if(cur.end>nowtime)
                break;
            play.pop();
            done.push(cur);
            if(viptable.find(cur.tablenum)!=viptable.end())
            {
                viptable[cur.tablenum]=1;
                tables[cur.tablenum]=1;
                vipava++;
            }
            else
            {
                ntable[cur.tablenum]=1;
                tables[cur.tablenum]=1;
                ava++;
            }
        }
        while(!arrive.empty())
        {
            //cout<<" arriving"<<endl;
            cur=arrive.top();
            if(cur.arrive>nowtime)
                break;
            arrive.pop();
            if(cur.vip)
            {
                wait.push(cur);
                vipwait.push(cur);
            }
            else
                wait.push(cur);
        }
        while(!vipwait.empty())
        {
            //cout<<" vip waiting"<<endl;
            cur=vipwait.top();
            if(cur.arrive>nowtime)
                break;
            if(vipava==0)
                break;
            if(vipdone.find(cur.arrive)!=vipdone.end())
            {
                vipwait.pop();
                continue;
            }
            vipwait.pop();
            vipdone.insert(cur.arrive);
            int t=-1;
            for(mit=viptable.begin();mit!=viptable.end();++mit)
            {
                if(mit->second==1)
                {
                    t=mit->first;
                    mit->second=0;
                    tables[mit->first]=0;
                    --vipava;
                    break;
                }
            }
            //cout<<vipava<<" "<<ava<<" get table "<<t<<endl;
            //cout<<"This is "<<nowtime/3600<<":"<<nowtime%3600/60<<":"<<nowtime%60<<" the player arrived at "<<cur.arrive/3600<<":"<<cur.arrive%3600/60<<":"<<cur.arrive%60<<" wait "<<nowtime-cur.arrive<<endl;
            cur.tablenum=t;
            cur.start=nowtime;
            cur.wait=cur.start-cur.arrive;
            cur.end=cur.start+cur.last;
            play.push(cur);
        }
        while(!wait.empty())
        {
            //cout<<" waiting "<<wait.size()<<endl;
            cur=wait.top();
            if(cur.arrive>nowtime)
                break;
            if(cur.vip && vipdone.find(cur.arrive)!=vipdone.end())
            {
                wait.pop();
                continue;
            }
            if(ava==0&&vipava==0)
                break;
            wait.pop();
            if(cur.vip)
                vipdone.insert(cur.arrive);
            int t;
            for(mit=tables.begin();mit!=tables.end();++mit)
            {
                if(mit->second==1)
                {
                    t=mit->first;
                    mit->second=0;
                    if(viptable.find(mit->first)!=viptable.end())
                    {
                        viptable[mit->first]=0;
                        --vipava;
                    }
                    else
                    {
                        ntable[mit->first]=0;
                        --ava;
                    }
                    break;
                }
            }
            //cout<<vipava<<" "<<ava<<" get table "<<t<<endl;
            //cout<<"This is "<<nowtime/3600<<":"<<nowtime%3600/60<<":"<<nowtime%60<<" the player arrived at "<<cur.arrive/3600<<":"<<cur.arrive%3600/60<<":"<<cur.arrive%60<<" wait "<<nowtime-cur.arrive<<endl;
            cur.tablenum=t;
            cur.start=nowtime;
            cur.wait=cur.start-cur.arrive;
            cur.end=cur.start+cur.last;
            play.push(cur);
        }
    }
    while(!play.empty())
    {
        Player cur=play.top();
        play.pop();
        done.push(cur);
    }
    map<int,int> cnt;
    while(!done.empty())
    {
        Player cur=done.top();
        done.pop();
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",cur.arrive/3600,cur.arrive%3600/60,cur.arrive%60,cur.start/3600,cur.start%3600/60,cur.start%60,(cur.wait+30)/60);
        cnt[cur.tablenum]++;
    }
    for(int i=1;i<=k;++i)
    {
        if(cnt[i]==0)
            cnt[i]==0;
    }
    for(mit=cnt.begin();mit!=cnt.end();++mit)
    {
        if(mit!=cnt.begin())
            printf(" ");
        printf("%d",mit->second);
    }
    printf("\n");
}
