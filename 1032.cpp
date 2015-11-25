#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node{
    char val;
    int next;
};

struct StackNode{
    char val;
    int add;
};

Node arr[100001];
int start1,start2,n,tmp;
stack<StackNode> stack1,stack2;

int main()
{
    scanf("%d %d %d",&start1,&start2,&n);
    getchar();
    for(int i=0;i<n;++i)
    {
        scanf("%d",&tmp);
        getchar();
        scanf("%c %d",&arr[tmp].val, &arr[tmp].next);
        getchar();
    }
    while(start1!=-1)
    {
        StackNode sn;
        sn.val=arr[start1].val;
        sn.add=start1;
        stack1.push(sn);
        start1=arr[start1].next;
    }
    while(start2!=-1)
    {
        StackNode sn;
        sn.val=arr[start2].val;
        sn.add=start2;
        stack2.push(sn);
        start2=arr[start2].next;
    }
    int sharing=-1;
    while(!stack1.empty() && !stack2.empty())
    {
        if(stack1.top().add == stack2.top().add)
            sharing=stack1.top().add;
        else
            break;
        stack1.pop();
        stack2.pop();
    }
    if(sharing!=-1)
        printf("%05d\n",sharing);
    else
        printf("-1\n");
    return 0;
}
