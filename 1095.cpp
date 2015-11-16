#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n,k;
struct Car
{
    char num[8];
    vector<int> insec,outsec;
    int total=0;
};

bool comp(const Car &a, const Car &b)
{
    return a.insec<b.insec;
}

int tton(char *time)
{
    return ((time[0]-'0')*10+time[1]-'0')*3600+((time[3]-'0')*10+time[4]-'0')*60+((time[6]-'0')*10+time[7]-'0');
    //int h,m,s;
    //sscanf(time,"%d:%d:%d",&h,&m,&s);
    //return 3600*h+60*m+s;
}

char* ntot(int n)
{
    int h,m,s;
    h=n/3600;
    n%=3600;
    m=n/60;
    n%=60;
    s=n;
    char *str = new char[12];
    sprintf(str,"%02d:%02d:%02d",h,m,s);
    return str;
}

vector<Car> v;
map<string,Car> m;
map<string,int> exist;
vector<int> query;
int start[10001];

int main()
{
    cin>>n>>k;
    char line[50],num[8],time[9];
    getchar();
    for(int i=0;i<n;++i)
    {
        gets(line);
        sscanf(line,"%s %s",num,time);
        string num_str=num;
        if(exist[num_str]<=0)
        {
            Car c;
            strcpy(c.num,num);
            m[num_str]=c;
            exist[num_str]++;
        }
        int ntime=tton(time);
        if(ntime<0||ntime>86399)
            continue;
        if(line[17]=='i')
            m[num_str].insec.push_back(ntime);
        else
            m[num_str].outsec.push_back(ntime);
    }
    for(int i=0;i<k;++i)
    {
        gets(line);
        int t = tton(line);
        query.push_back(t);
    }
    //cout<<"size "<<m.size()<<endl;
    for(map<string,Car>::iterator it=m.begin();it!=m.end();++it)
    {
        //if(it->second.insec.size()>=it->second.outsec.size())
        //{
            Car c=it->second;
            if(c.insec.size()==0||c.outsec.size()==0)
                continue;
            sort(c.insec.begin(),c.insec.end());
            sort(c.outsec.begin(),c.outsec.end());
            //cout<<c.num<<" in "<<c.insec.size()<<" out "<<c.outsec.size()<<endl;
            vector<int>::iterator inp=c.insec.begin(),outp=c.outsec.begin();
            Car rc;
            while(inp!=c.insec.end()&&outp!=c.outsec.end())
            {
                while(outp!=c.outsec.end()&&(*inp)>(*outp))
                    ++outp;
                if(outp==c.outsec.end())
                    break;
                while(inp!=c.insec.end()&&(*inp)<(*outp))
                    ++inp;
                if(inp==c.insec.end())
                    --inp;
                if(inp!=c.insec.begin()&&(*inp)>(*outp))
                    --inp;
                rc.total+=(*outp)-(*inp);
                rc.insec.push_back(*inp);
                rc.outsec.push_back(*outp);
                ++inp;
                ++outp;
            }
            if(rc.insec.size()>0)
            {
                strcpy(rc.num,c.num);
                v.push_back(rc);
                //cout<<rc.total<<endl;
            }
        //}
    }

    for(int i=0;i<v.size();++i)
        start[i]=0;
    for(int i=0;i<query.size();++i)
    {
        int t = query[i];
        if(t<0||t>86399)
        {
            printf("%d\n");
            continue;
        }
        int cnt=0;
        for(int j=0;j<v.size();++j)
        {
            for(int l=start[j];l<v[j].insec.size();++l)
            {
                if(v[j].outsec[l]<=t)
                    ++start[j];
                else if(v[j].insec[l]<=t)
                {
                    ++cnt;
                    break;
                }
            }
        }
        printf("%d\n",cnt);
    }
    int maxtime=0;
    set<string> maxid;
    for(int i=0;i<v.size();)
    {
        if(v[i].total>=maxtime)
        {
            maxtime=v[i].total;
            ++i;
        }
        else
            v.erase(v.begin()+i);
    }
    for(int i=0;i<v.size();++i)
    {
        if(v[i].total==maxtime)
        {
            string str = v[i].num;
            maxid.insert(str);
        }
    }
    //sort(maxid.begin(),maxid.end());
    for(set<string>::iterator it=maxid.begin();it!=maxid.end();++it)
        printf("%s ",(*it).c_str());
    printf("%s\n",ntot(maxtime));
    return 0;
}
