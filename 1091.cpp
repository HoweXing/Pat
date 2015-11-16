#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

char data[1286][128][60];
char visited[1296][128][60];
int m,n,l,t;

struct Point
{
    int x,y,z;
};

bool check(Point p)
{
    if(p.x>=0&&p.x<m&&
       p.y>=0&&p.y<n&&
       p.z>=0&&p.z<l&&
       visited[p.x][p.y][p.z]=='0'&&
       data[p.x][p.y][p.z]=='1')
    {
        visited[p.x][p.y][p.z]='1';
        return true;
    }

    return false;
}

int main()
{
    cin>>m>>n>>l>>t;
    int tmp;
    for(int i=0;i<l;++i)
    {
        for(int j=0;j<m;++j)
        {
            for(int k=0;k<n;++k)
            {
                cin>>tmp;
                if(tmp==1)
                    data[j][k][i]='1';
                else
                    data[j][k][i]='0';
                visited[j][k][i]='0';
            }
        }
    }
    int vol=0;
    for(int i=0;i<l;++i)
    {
        for(int j=0;j<m;++j)
        {
            for(int k=0;k<n;++k)
            {
                if(visited[j][k][i]=='1'||data[j][k][i]=='0')
                    continue;
                queue<Point> q;
                Point cur;
                cur.x=j;
                cur.y=k;
                cur.z=i;
                q.push(cur);
                int cnt=0;
                while(!q.empty())
                {
                    cur=q.front();
                    //cout<<cur.x<<" "<<cur.y<<" "<<cur.z<<endl;
                    q.pop();
                    ++cnt;
                    visited[cur.x][cur.y][cur.z]='1';

                    Point next=cur;
                    next.x++;
                    if(check(next))
                        q.push(next);
                    next=cur;
                    next.x--;
                    if(check(next))
                        q.push(next);
                    next=cur;
                    next.y++;
                    if(check(next))
                        q.push(next);
                    next=cur;
                    next.y--;
                    if(check(next))
                        q.push(next);
                    next=cur;
                    next.z++;
                    if(check(next))
                        q.push(next);
                    next=cur;
                    next.z--;
                    if(check(next))
                        q.push(next);
                }
                if(cnt>=t)
                    vol+=cnt;
            }
        }
    }
    cout<<vol<<endl;
    return 0;
}
