#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

string cnc[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

string dw(int k)
{
    switch(k%4)
    {
      case 3:return "Qian";
      case 2:return "Bai";
      case 1:return "Shi";
      case 0:
          if(k/4==2)
              return "Yi";
          else if(k/4==1)
              return "Wan";
    }
    return "";
}

int main()
{
    char str[12],istr[12];
    int top=0;
    scanf("%s",str);
    for(int i=strlen(str)-1;i>=0;--i)
    {
        istr[top++]=str[i];
    }
    istr[top]='\0';
    vector<string> v;
    for(top=strlen(str)-1;top>=0;--top)
    {
        char c[5]={'\0'};
        c[0]=istr[top];
        //cout<<c<<endl;
        if(c[0]=='-')
            v.push_back("Fu");
        else
        {
            int dig = atoi(c);
            //cout<<dig<<endl;
            int k;
            if(dig!=0)
            {
                v.push_back(cnc[dig]);
                v.push_back(dw(top));
            }
            else
            {
                int notz=top;
                while(istr[notz]=='0'&&notz>=0)
                    --notz;
                if(v.size()==0&&notz==-1)
                {
                    v.push_back(cnc[dig]);
                    break;
                }
                else if(v.size()==0)
                {
                    top=notz+1;
                    continue;
                }
                bool f=true;
                int k;
                for(k=top;k>=0;--k)
                {
                    if(istr[k]!='0')
                    {
                        break;
                    }
                    //cout<<"k "<<k<<endl;
                    if(k%4==0&&f)
                    {
                        if(dw(k)!="")
                            v.push_back(dw(k));
                        f=false;
                    }
                }
                if(k>=0)
                    v.push_back(cnc[dig]);
                //cout<<"k "<<k<<endl;
                top=k+1;
            }
        }
    }
    //cout<<"*";
    for(int i=0;i<v.size();++i)
    {
        if(i>0&&v[i]!="")
            cout<<" ";
        cout<<v[i];
    }
    //cout<<"*";
    cout<<endl;
    return 0;
}
