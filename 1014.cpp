#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Cus{
    int id;
    int s,e;
    int cost;
    int win;
    bool operator < (const Cus &a) const
    {
        return e>a.e;
    }
};

int n,m,k,q;
queue<int> cost;
map<int,int> cap,cusdone;
map<int,int>::iterator it;
int tmp,pos;
priority_queue<Cus> Queue;
vector<int> done,query;
int id=0;

int findwin()
{
    int maxnum=-1,winid=99;
    for(it=cap.begin();it!=cap.end();++it)
    {
        if(it->second>maxnum)
        {
            maxnum=it->second;
            winid=it->first;
        }
    }
    return winid;
}

int main()
{
    cin>>n>>m>>k>>q;
    for(int i=0;i<k;++i)
    {
        scanf("%d",&tmp);
        cost.push(tmp);
    }
    for(int i=0;i<q;++i)
    {
        scanf("%d",&tmp);
        query.push_back(tmp-1);
    }
    for(int i=0;i<n;++i)
    {
        cap[i]=m;
        done.push_back(0);
    }
    pos=m*n;
    while(pos>0&&!cost.empty())
    {
        Cus c;
        c.id=id++;
        c.cost=cost.front();
        cost.pop();
        c.win=findwin();
        c.s=done[c.win];
        c.e=c.s+c.cost;
        done[c.win]=c.e;
        cap[c.win]--;
        pos--;
        Queue.push(c);
        //cout<<"in "<<c.id<<" "<<c.e<<" "<<c.win<<" "<<cap[c.win]<<endl;
    }
    while(!Queue.empty())
    {
        Cus cur=Queue.top();
        Queue.pop();
        cap[cur.win]++;
        pos++;
        int now=cur.e;
        while(!Queue.empty())
        {
            Cus next=Queue.top();
            if(next.e!=now)
                break;
            Queue.pop();
            cap[next.win]++;
            pos++;
            if(next.s>=540)
                continue;
            cusdone[next.id]=next.e;
        }
        if(cur.s>=540)
            continue;
        cusdone[cur.id]=cur.e;
        while(pos>0&&!cost.empty())
        {
            Cus c;
            c.id=id++;
            c.cost=cost.front();
            cost.pop();
            c.win=findwin();
            c.s=done[c.win];
            c.e=c.s+c.cost;
            done[c.win]=c.e;
            cap[c.win]--;
            pos--;
            Queue.push(c);
            //cout<<"in "<<c.id<<" "<<c.e<<" "<<c.win<<" "<<cap[c.win]<<endl;
        }
    }
    for(int i=0;i<q;++i)
    {
        int total=cusdone[query[i]];
        if(total>0)
            printf("%02d:%02d\n",8+total/60,total%60);
        else
            printf("Sorry\n");
    }
    return 0;
}
