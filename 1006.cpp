#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char line[100];
int n;

struct Person{
    char id[16];
    int in_h,in_m,in_s;
    int out_h,out_m,out_s;
    int in,out;
};
vector<Person> v;

bool comp1(const Person &a, const Person &b)
{
    return a.in<b.in;
}

bool comp2(const Person &a, const Person &b)
{
    return a.out>b.out;
}

int main()
{
    cin>>n;
    getchar();
    for(int i=0;i<n;++i)
    {
        Person p;
        gets(line);
        sscanf(line,"%s %d:%d:%d %d:%d:%d",p.id,&p.in_h,&p.in_m,&p.in_s,&p.out_h,&p.out_m,&p.out_s);
        p.in=p.in_h*3600+p.in_m*60+p.in_s;
        p.out=p.out_h*3600+p.out_m*60+p.out_s;
        v.push_back(p);
    }
    sort(v.begin(),v.end(),comp1);
    printf("%s ",v[0].id);
    sort(v.begin(),v.end(),comp2);
    printf("%s\n",v[0].id);
    return 0;
}
