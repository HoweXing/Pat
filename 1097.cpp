#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>
#include <set>
#include <cmath>
using namespace std;

struct Node
{
    int val;
    int next;
};

int valset[10001];
Node nodeset[100000];

int main()
{
    for(int i=0;i<=10000;++i)
        valset[i]=0;
    char line[50];
    int add,val,next;
    int n;
    gets(line);
    sscanf(line,"%d %d",&add,&val);
    int root=add;
    n=val;
    int fore,addstr;
    int deroot=-1,der;
    for(int i=0;i<n;++i)
    {
        gets(line);
        sscanf(line,"%d %d %d",&add,&val,&next);
        Node node;
        node.val=val;
        node.next=next;
        addstr=add;
        nodeset[addstr]=node;
    }
    addstr=root;
    fore=root;
    while(addstr!=-1)
    {
        if(valset[abs(nodeset[addstr].val)]==0)
        {
            valset[abs(nodeset[addstr].val)]=1;
            fore=addstr;
            addstr=nodeset[addstr].next;
        }
        else
        {
            nodeset[fore].next=nodeset[addstr].next;
            if(deroot==-1)
            {
                deroot=addstr;
                der=deroot;
                nodeset[der].next=-1;
            }
            else
            {
                nodeset[der].next=addstr;
                der=addstr;
                nodeset[der].next=-1;
            }
            addstr=nodeset[fore].next;
        }
    }
    while(root!=-1)
    {
        printf("%05d %d ",root,nodeset[root].val);
        if(nodeset[root].next==-1)
            printf("-1\n");
        else
            printf("%05d\n",nodeset[root].next);
        root=nodeset[root].next;
    }
    while(deroot!=-1)
    {
        printf("%05d %d ",deroot,nodeset[deroot].val);
        if(nodeset[deroot].next==-1)
            printf("-1\n");
        else
            printf("%05d\n",nodeset[deroot].next);
        deroot=nodeset[deroot].next;
    }
    return 0;
}
