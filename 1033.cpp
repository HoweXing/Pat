#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Gas{
    double p,d;
};

bool comp(const Gas &a, const Gas &b)
{
    return a.d<b.d;
}

double cap,dis,dav;
int n;
vector<Gas> v;

int nextSmall(int cur)
{
    int re=-1;
    double min=v[cur].p;
    for(int i=cur+1;i<v.size()&&(v[i].d-v[cur].d)<cap*dav;++i)
    {
        if(v[i].p<min)
        {
            re=i;
            min=v[i].p;
            break;
        }
    }
    return re;
}

int main()
{
    cin>>cap>>dis>>dav>>n;
    Gas tmp;
    for(int i=0;i<n;++i)
    {
        cin>>tmp.p>>tmp.d;
        if(tmp.d<dis)
            v.push_back(tmp);
    }
    sort(v.begin(),v.end(),comp);
    //for(int i=0;i<v.size();++i)
    //    cout<<v[i].p<<" "<<v[i].d<<endl;
    bool stop=false;
    double run=0,cost=0;
    double remaingas=0;
    for(int i=0;i<v.size()&&run<dis;++i)
    {
        if(i==0&&v[i].d>0)
        {
            stop=true;
            break;
        }
        run=v[i].d;
        if(i!=0)
            remaingas-=(v[i].d-v[i-1].d)/dav;
        //printf("before %.2f\n",remaingas);
        double dis_ns = nextSmall(i);
        //cout<<" dis_ns "<<dis_ns<<endl;
        if(dis_ns==-1)
        {
            if(cap*dav>=(dis-v[i].d))
            {
                double add=(dis-v[i].d)/dav-remaingas;
                cost+=add*v[i].p;
                //printf(" *** %.2f\n",add*v[i].p);
                remaingas+=add;
            }
            else
            {
                double add=cap-remaingas;
                cost+=add*v[i].p;
                //printf(" *** %.2f\n",add*v[i].p);
                remaingas=cap;
            }
        }
        else
        {
            if((v[dis_ns].d-v[i].d)>remaingas*dav)
            {
                double add=(v[dis_ns].d-v[i].d)/dav-remaingas;
                cost+=add*v[i].p;
                //printf(" *** %.2f\n",add*v[i].p);
                remaingas+=add;
            }
        }
        //printf("after %.2f\n",remaingas);
        if(i!=0)
        {
            if(i!=v.size()-1&&(remaingas*dav-(v[i+1].d-v[i].d))<-0.00000000001)
            {
                //cout<<"can not arrive next station"<<endl;
                //cout<<remaingas*dav<<" < "<<(v[i+1].d-v[i].d)<<endl;
                stop=true;
                run+=remaingas*dav;
                break;
            }
            if(i==v.size()-1&&(remaingas*dav-(dis-v[i].d))<-0.00000000001)
            {
                //cout<<"can not arrive destination"<<endl;
                //cout<<remaingas*dav<<" < "<<(dis-v[i].d)<<endl;
                stop=true;
                run+=remaingas*dav;
                break;
            }
        }
    }
    if(stop)
        printf("The maximum travel distance = %.2f\n",run);
    else
        printf("%.2f\n",cost);
    return 0;
}
