#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int i=0,j=0,sum=0,maxsum=-999999999;
    int s,e;
    while(j<n)
    {
        if(sum>0)
            sum+=arr[j];
        else
        {
            sum=arr[j];
            i=j;
        }
        if(sum>maxsum)
        {
            maxsum=sum;
            s=i;
            e=j;
        }
        ++j;
    }
    if(maxsum>=0)
        cout<<maxsum<<" "<<arr[s]<<" "<<arr[e]<<endl;
    else
        cout<<0<<" "<<arr[0]<<" "<<arr[n-1]<<endl;
    delete arr;
    return 0;
}
