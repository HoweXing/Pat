#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val,high;
    Node *left,*right;
    Node(int value): val(value),left(NULL),right(NULL),high(0){}
};

int max(int a, int b)
{
    return a>b?a:b;
}

int gethigh(Node *node)
{
    if(node==NULL)
        return -1;
    else
        return node->high;
}

void checkhigh(Node *node)
{
    node->high=max(gethigh(node->left),gethigh(node->right))+1;
}

bool isbalance(Node *node)
{
    int left_high,right_high;
    left_high=gethigh(node->left);
    right_high=gethigh(node->right);
    if(abs(left_high-right_high)<=1)
        return true;
    return false;
}

Node* rotateLL(Node *node)
{
    Node *child=node->left;
    node->left=child->right;
    child->right=node;
    checkhigh(node);
    checkhigh(child);
    return child;
}

Node* rotateRR(Node *node)
{
    Node *child=node->right;
    node->right=child->left;
    child->left=node;
    checkhigh(node);
    checkhigh(child);
    return child;
}

Node* rotateLR(Node *node)
{
    node->left=rotateRR(node->left);
    return rotateLL(node);
}

Node* rotateRL(Node *node)
{
    node->right=rotateLL(node->right);
    return rotateRR(node);
}

Node* insert(Node *root, int value)
{
    if(root==NULL)
        root=new Node(value);
    else
    {
        if(value<root->val)
        {
            root->left=insert(root->left,value);
            if(!isbalance(root))
            {
                if(value<root->left->val)
                    root=rotateLL(root);
                else
                    root=rotateLR(root);
            }
        }
        else
        {
            root->right=insert(root->right,value);
            if(!isbalance(root))
            {
                if(value<root->right->val)
                    root=rotateRL(root);
                else
                    root=rotateRR(root);
            }
        }
    }
    checkhigh(root);
    return root;
}

int main()
{
    int n,num;
    scanf("%d",&n);
    Node *root=NULL;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&num);
        root=insert(root,num);
    }
    printf("%d\n",root->val);
    return 0;
}
