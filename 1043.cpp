#include <iostream>
#include <vector>
using namespace std;

vector<int> pre,post;

bool flag=true;

struct Node
{
    int val=-1;
    Node *left=NULL;
    Node *right=NULL;
};

Node* built(int s, int e)
{
    //cout<<"b "<<s<<" "<<e<<endl;
    if(!flag)
        return NULL;
    if(s<0||s>e||e>=pre.size())
        return NULL;
    if(s==e)
    {
        Node* node = new Node();
        node->val=pre[s];
        return node;
    }
    if(s==e-1&&pre[s]>pre[e])
    {
        Node* node = new Node();
        node->val=pre[s];
        node->left=built(e,e);
        return node;
    }
    if(s==e-1&&pre[s]<=pre[e])
    {
        Node* node = new Node();
        node->val=pre[s];
        node->right=built(e,e);
        return node;
    }
    else
    {
        int root=pre[s];
        int p=s+1;
        while(pre[p]<root&&p<=e)
            ++p;
        //cout<<"p "<<p<<endl;
        for(int i=p;i<=e;++i)
        {
            if(pre[i]<root)
            {
                //cout<<"because "<<pre[i]<<" < "<<root<<endl;
                flag=false;
                return NULL;
            }
        }
        Node* node = new Node();
        node->val=pre[s];
        node->left=built(s+1,p-1);
        node->right=built(p,e);
        return node;
    }

}

Node* rbuilt(int s, int e)
{
    //cout<<"rb "<<s<<" "<<e<<endl;
    if(!flag)
        return NULL;
    if(s<0||s>e||e>=pre.size())
        return NULL;
    if(s==e)
    {
        Node* node = new Node();
        node->val=pre[s];
        return node;
    }
    if(s==e-1&&pre[s]<=pre[e])
    {
        Node* node = new Node();
        node->val=pre[s];
        node->left=rbuilt(e,e);
        return node;
    }
    if(s==e-1&&pre[s]>pre[e])
    {
        Node* node = new Node();
        node->val=pre[s];
        node->right=rbuilt(e,e);
        return node;
    }
    else
    {
        int root=pre[s];
        int p=s+1;
        while(pre[p]>=root&&p<=e)
            ++p;
        for(int i=p;i<=e;++i)
        {
            if(pre[i]>=root)
            {
                //cout<<"because "<<pre[i]<<" >= "<<root<<endl;
                flag=false;
                return NULL;
            }
        }
        Node* node = new Node();
        node->val=pre[s];
        node->left=rbuilt(s+1,p-1);
        node->right=rbuilt(p,e);
        return node;
    }

}

void postorder(Node *root)
{
    if(root==NULL)
        return;
    if(root->left!=NULL)
        postorder(root->left);
    if(root->right!=NULL)
        postorder(root->right);
    post.push_back(root->val);
}

int main()
{
    int n;
    cin>>n;
    int tmp;
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        pre.push_back(tmp);
    }
    Node* root = new Node();
    flag=true;
    root=built(0,n-1);
    if(flag)
    {
        cout<<"YES"<<endl;
        postorder(root);
        for(int i=0;i<post.size();++i)
        {
            if(i!=0)
                cout<<" ";
            cout<<post[i];
        }
        cout<<endl;
        return 0;
    }
    else
    {
        flag=true;
        root=rbuilt(0,n-1);
        if(flag)
        {
            cout<<"YES"<<endl;
            postorder(root);
            for(int i=0;i<post.size();++i)
            {
                if(i!=0)
                    cout<<" ";
                cout<<post[i];
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
