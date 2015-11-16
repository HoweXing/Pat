#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <stdlib.h>
using namespace std;

class Node
{
public:
    double price;
    double sales;
    vector<int> sub;
};

Node array[100001];

int main()
{
    int num;
    double p,r;
    cin>>num>>p>>r;
    //Node *array = new Node[num];
    array[0].price=p;
    for(int i=0;i<num;++i)
    {
        int n;
        cin>>n;
        if(n>0)
        {
            int id;
            for(int j=0;j<n;++j)
            {
                cin>>id;
                array[i].sub.push_back(id);
            }
        }
        else
        {
            cin>>(array[i].sales);
        }
    }
    queue<int> q_id;
    q_id.push(0);
    double total=0;
    while(!q_id.empty())
    {
        int id = q_id.front();
        //cout<<"pop "<<id<<endl;
        //cout<<"size "<<array[id].sub.size()<<endl;
        //system("pause");
        q_id.pop();
        if(array[id].sub.size()>0)
        {
            for(int i=0;i<array[id].sub.size();++i)
            {
                array[array[id].sub[i]].price = (1+r/100) * array[id].price;
                q_id.push(array[id].sub[i]);
                //cout<<"push "<<array[id].sub[i]<<endl;
            }
        }
        else
        {
            total += array[id].price * array[id].sales;
            //cout<<"price "<<array[id].price<<" , sales "<<array[id].sales<<endl;
        }
    }
    printf("%.1f\n",total);
}
