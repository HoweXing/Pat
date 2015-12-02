#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Record{
    string name;
    int month,day,hour,minute;
    int cnt;
    int flag;
};

struct Bill{
    int sday,shour,smin;
    int eday,ehour,emin;
    int last;
    double cost;
};

int price[24];
char line[200];
map<string,vector<Record> > Src,Map;
map<string,vector<Record> >::iterator it;
map<string,vector<Bill> > BMap;
map<string,vector<Bill> >::iterator bit;
int month;

bool comp(const Record &a, const Record &b)
{
    return a.cnt<b.cnt;
}

Record stor(char *s)
{
    Record r;
    char name[25],date_time[20],onoff[20];
    sscanf(s,"%s %s %s",name,date_time,onoff);
    r.name=name;
    if(onoff[1]=='n')
        r.flag=0;
    else
        r.flag=1;
    sscanf(date_time,"%d:%d:%d:%d",&r.month,&r.day,&r.hour,&r.minute);
    r.cnt=(r.day-1)*24*60+(r.hour)*60+r.minute;
    return r;
}

int main()
{
    for(int i=0;i<24;++i)
        scanf("%d",&price[i]);
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;++i)
    {
        gets(line);
        Record r=stor(line);
        Src[r.name].push_back(r);
    }
    for(it=Src.begin();it!=Src.end();++it)
    {
        sort(it->second.begin(),it->second.end(),comp);
        int pre=1;
        for(int i=0;i<it->second.size();++i)
        {
            Record r=it->second[i];
            if(r.flag==0)
            {
                if(pre==0)
                    continue;
                if(i==it->second.size()-1)
                    continue;
                if(it->second[i+1].flag==r.flag)
                    continue;
                Map[r.name].push_back(r);
                pre=0;
            }
            else
            {
                if(pre==1)
                    continue;
                Map[r.name].push_back(r);
                pre=1;
            }
        }
    }
    for(it=Map.begin();it!=Map.end();++it)
    {
        for(int i=0;i<it->second.size()-1;i+=2)
        {
            Record on=it->second[i];
            Record off=it->second[i+1];
            month=on.month;
            Bill b;
            b.sday=on.day;b.shour=on.hour;b.smin=on.minute;
            b.eday=off.day;b.ehour=off.hour;b.emin=off.minute;
            b.last=off.cnt-on.cnt;
            double co=0;
            if(on.day==off.day&&on.hour==off.hour)
                co+=(off.minute-on.minute)*price[on.hour];
            else
            {
                for(int x=on.day;x<=off.day;++x)
                {
                    for(int y=(x==on.day?on.hour:0);y<=(x==off.day?off.hour:23);++y)
                    {
                        if(x==on.day&&y==on.hour)
                            co+=(60-on.minute)*price[on.hour];
                        else if(x==off.day&&y==off.hour)
                            co+=off.minute*price[off.hour];
                        else
                            co+=60*price[y];
                    }
                }
            }
            co/=100;
            b.cost=co;
            BMap[on.name].push_back(b);
        }
    }
    for(bit=BMap.begin();bit!=BMap.end();++bit)
    {
        if(bit->second.size()>0)
            printf("%s %02d\n",bit->first.c_str(),month);
        double total=0;
        for(int i=0;i<bit->second.size();++i)
        {
            Bill b=bit->second[i];
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",b.sday,b.shour,b.smin,b.eday,b.ehour,b.emin,b.last,b.cost);
            total+=b.cost;
        }
        if(bit->second.size()>0)
            printf("Total amount: $%.2f\n",total);
    }
    return 0;
}
