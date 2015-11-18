#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int now=0,sum=0;
    for(int i=0;i<n;++i)
    {
        int sub=arr[i]-now;
        if(sub>0)
            sum+=6*sub;
        else
            sum+=-4*sub;
        sum+=5;
        now=arr[i];
    }
    cout<<sum<<endl;
    return 0;
}
