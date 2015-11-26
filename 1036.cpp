#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

struct Stu
{
    string name,id;
    int grade;
};

vector<Stu> boys,girls;
int n;

bool comp_in(const Stu &a, const Stu &b)
{
    return a.grade<b.grade;
}

bool comp_de(const Stu &a, const Stu &b)
{
    return a.grade>b.grade;
}

int main()
{
    scanf("%d",&n);
    getchar();
    char name[11],id[11],gender[2];
    int grade;
    for(int i=0;i<n;++i)
    {
        scanf("%s %s %s %d",name,gender,id,&grade);
        getchar();
        Stu stu;
        stu.name=name;
        stu.id=id;
        stu.grade=grade;
        if(strcmp(gender,"M")==0)
            boys.push_back(stu);
        else
            girls.push_back(stu);
    }
    sort(boys.begin(),boys.end(),comp_in);
    sort(girls.begin(),girls.end(),comp_de);
    if(girls.size()==0)
        printf("Absent\n");
    else
        printf("%s %s\n",girls[0].name.c_str(),girls[0].id.c_str());
    if(boys.size()==0)
        printf("Absent\n");
    else
        printf("%s %s\n",boys[0].name.c_str(),boys[0].id.c_str());
    if(girls.size()==0 || boys.size()==0)
        printf("NA\n");
    else
        printf("%d\n",girls[0].grade-boys[0].grade);
    return 0;
}
