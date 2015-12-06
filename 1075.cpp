#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int n,k,m;
int fullscore[6],user[10001][6],submit[10001][6];
vector<int> Rank;

bool comp(const int &a, const int &b)
{
    if(user[a][0]!=user[b][0])
        return user[a][0]>user[b][0];
    else
    {
        int perfect1=0,perfect2=0;
        for(int i=1;i<=k;++i)
        {
            if(user[a][i]==fullscore[i])
                ++perfect1;
            if(user[b][i]==fullscore[i])
                ++perfect2;
        }
        if(perfect1!=perfect2)
            return perfect1>perfect2;
        else
            return a<b;
    }
}

bool hascompiler(int ui)
{
    for(int i=1;i<=k;++i)
    {
        if(user[ui][i]!=-1)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=k;++j)
            user[i][j]=-1;
    }
    for(int i=1;i<=k;++i)
        scanf("%d",&fullscore[i]);
    int ui,pi,score;
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%d",&ui,&pi,&score);
        submit[ui][0]++;
        submit[ui][pi]++;
        if(score>-1)
        {
            int oldscore=user[ui][pi];
            if(oldscore<score)
            {
                user[ui][pi]=score;
                if(oldscore!=-1)
                    user[ui][0]+=score-oldscore;
                else
                    user[ui][0]+=score;
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(submit[i][0]>0 && hascompiler(i))
            Rank.push_back(i);
    }
    sort(Rank.begin(),Rank.end(),comp);
    int r=1,lastrank=0;
    for(int i=0;i<Rank.size();++i)
    {
        if(i==0 || user[Rank[i]][0]==user[Rank[i-1]][0])
        {
            printf("%d ",r);
            ++lastrank;
        }
        else
        {
            r+=lastrank;
            printf("%d ",r);
            lastrank=1;
        }
        int ui=Rank[i];
        printf("%05d %d",ui,user[ui][0]);
        for(int j=1;j<=k;++j)
        {
            if(user[ui][j]>=0)
                printf(" %d",user[ui][j]);
            else if(submit[ui][j]>0)
                printf(" 0");
            else
                printf(" -");
        }
        printf("\n");
    }
    return 0;
}
