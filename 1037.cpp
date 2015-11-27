#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ncpo,ncne,nppo,npne;

bool comp(const int &a, const int &b)
{
    return a>b;
}

int main()
{
    int nc,np,tmp;
    cin>>nc;
    for(int i=0;i<nc;++i)
    {
        cin>>tmp;
        if(tmp>=0)
            ncpo.push_back(tmp);
        else
            ncne.push_back(tmp);
    }
    cin>>np;
    for(int i=0;i<np;++i)
    {
        cin>>tmp;
        if(tmp>=0)
            nppo.push_back(tmp);
        else
            npne.push_back(tmp);
    }
    sort(ncpo.begin(),ncpo.end(),comp);
    sort(ncne.begin(),ncne.end());
    sort(nppo.begin(),nppo.end(),comp);
    sort(npne.begin(),npne.end());
    int total=0;
    for(int i=0;i<ncpo.size() && i<nppo.size();++i)
    {
        total+=ncpo[i]*nppo[i];
        //cout<<ncpo[i]<<" & "<<nppo[i]<<endl;
    }
    for(int i=0;i<ncne.size() && i<npne.size();++i)
    {
        total+=ncne[i]*npne[i];
        //cout<<ncne[i]<<" & "<<npne[i]<<endl;
    }
    cout<<total<<endl;
}
