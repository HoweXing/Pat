#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

struct Book{
    string title,author,publisher,year;
    vector<string> keywords;
};

map<int,Book> bookindex;
map<string,set<int> > titleindex,kwdindex,auindex,pubindex,yearindex;
set<int>::iterator sit;
int n,m;
char line[1000];

int main()
{
    cin>>n;
    getchar();
    for(int i=0;i<n;++i)
    {
       int id;
       Book b;
       gets(line);
       id=atoi(line);
       gets(line);
       b.title=line;
       titleindex[b.title].insert(id);
       gets(line);
       b.author=line;
       auindex[b.author].insert(id);
       gets(line);
       string kwds=line,tmp;
       int s=0;
       do{
            int e=kwds.find(" ",s);
            if(e==string::npos)
            {
                tmp=kwds.substr(s,kwds.size());
                kwdindex[tmp].insert(id);
                b.keywords.push_back(tmp);
                break;
            }
            else
            {
                tmp=kwds.substr(s,e-s);
                kwdindex[tmp].insert(id);
                b.keywords.push_back(tmp);
            }
            s=e+1;
       }while(1);
       gets(line);
       b.publisher=line;
       pubindex[b.publisher].insert(id);
       gets(line);
       b.year=line;
       yearindex[b.year].insert(id);

       bookindex[id]=b;
    }
    cin>>m;
    getchar();
    for(int i=0;i<m;++i)
    {
        gets(line);
        printf("%s\n",line);
        char query[100];
        string qstr;
        qstr=line;
        qstr=qstr.substr(3,qstr.size());
        switch(line[0])
        {
            case '1':{
                if(titleindex[qstr].size()>0)
                for(sit=titleindex[qstr].begin();sit!=titleindex[qstr].end();++sit)
                    printf("%07d\n",*sit);
                else
                    printf("Not Found\n");
                break;
            }
            case '2':{
                if(auindex[qstr].size()>0)
                for(sit=auindex[qstr].begin();sit!=auindex[qstr].end();++sit)
                    printf("%07d\n",*sit);
                else
                    printf("Not Found\n");
                break;
            }
            case '3':{
                if(kwdindex[qstr].size()>0)
                for(sit=kwdindex[qstr].begin();sit!=kwdindex[qstr].end();++sit)
                    printf("%07d\n",*sit);
                else
                    printf("Not Found\n");
                break;
            }
            case '4':{
                if(pubindex[qstr].size()>0)
                for(sit=pubindex[qstr].begin();sit!=pubindex[qstr].end();++sit)
                    printf("%07d\n",*sit);
                else
                    printf("Not Found\n");
                break;
            }
            case '5':{
                if(yearindex[qstr].size()>0)
                for(sit=yearindex[qstr].begin();sit!=yearindex[qstr].end();++sit)
                    printf("%07d\n",*sit);
                else
                    printf("Not Found\n");
                break;
            }
        }
    }
    return 0;
}
