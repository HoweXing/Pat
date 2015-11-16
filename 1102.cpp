#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

int *leftnode = NULL;
int *rightnode = NULL;
vector<int> inorder;

void in(int root)
{
    if(root==-1)
        return;
    in(leftnode[root]);
    inorder.push_back(root);
    in(rightnode[root]);
}

int main()
{
    int n;
    cin>>n;
    if(n==0)
        return 0;
    int sum=n*(n-1)/2;
    leftnode = new int[n];
    rightnode = new int[n];
    getchar();
    char line[20];
    char lstr[10],rstr[10];
    int l,r;
    for(int i=0;i<n;++i)
    {
        l=r=-1;
        gets(line);
        sscanf(line,"%s %s",&lstr,&rstr);
        //printf("%s&%s\n",lstr,rstr);
        if(strcmp(lstr,"-")==0)
            l=-1;
        else
            l=atoi(lstr);
        if(strcmp(rstr,"-")==0)
            r=-1;
        else
            r=atoi(rstr);
        //printf("%d#%d\n",l,r);
        leftnode[i]=l;
        rightnode[i]=r;
        if(l!=-1)
            sum-=l;
        if(r!=-1)
            sum-=r;
    }
    int root=sum;
    //printf("root %d\n",root);
    queue<int> q;
    q.push(root);
    vector<int> levelorder;
    while(!q.empty())
    {
        int cur=q.front();
        //printf("cur %d\n",cur);
        levelorder.push_back(cur);
        q.pop();
        if(rightnode[cur]!=-1)
            q.push(rightnode[cur]);
        if(leftnode[cur]!=-1)
            q.push(leftnode[cur]);
        int tmp=leftnode[cur];
        leftnode[cur]=rightnode[cur];
        rightnode[cur]=tmp;
    }
    for(int i=0;i<levelorder.size();++i)
    {
        if(i!=0)
            printf(" ");
        printf("%d",levelorder[i]);
    }
    printf("\n");
    in(root);
    for(int i=0;i<inorder.size();++i)
    {
        if(i!=0)
            printf(" ");
        printf("%d",inorder[i]);
    }
    printf("\n");
    return 0;
}
