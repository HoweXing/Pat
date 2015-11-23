#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stdio.h>
using namespace std;

int post[31],in[31];

struct Node{
    int val;
    Node *left,*right;
};

Node* buildtree(int pl, int pr, int il, int ir)
{
    if(pr<pl||ir<il)
        return NULL;
    Node *node = new Node;
    node->val=post[pr];
    if(pl==pr)
    {
        node->left=NULL;
        node->right=NULL;
    }
    else
    {
        int k;
        for(k=il;k<=ir;++k)
        {
            if(in[k]==node->val)
                break;
        }
        int lnum=k-il,rnum=ir-k;
        node->left=buildtree(pl,pl+lnum-1,il,k-1);
        node->right=buildtree(pl+lnum,pr-1,k+1,ir);
    }
    return node;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>post[i];
    for(int i=0;i<n;++i)
        cin>>in[i];
    Node *root = buildtree(0,n-1,0,n-1);
    vector<int> level;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        if(cur->left)
            q.push(cur->left);
        if(cur->right)
            q.push(cur->right);
        level.push_back(cur->val);
        delete cur;
    }
    for(int i=0;i<level.size();++i)
    {
        if(i>0)
            printf(" ");
        printf("%d",level[i]);
    }
    printf("\n");
    return 0;
}
