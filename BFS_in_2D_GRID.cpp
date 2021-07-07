#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
int grid[10][10];
int lvl[10][10];
int vis[10][10];
int main()
{
    int i=1;
    map< char,int >my;
    char c;
    for(c='a'; c<='h'; c++)
    {
        my[c]=i++;
    }
    char s[4];
    while(cin>>s)
    {
        char d[4];
        cin>>d;
        int sx=s[1]-'0',dx=d[1]-'0',sy=my[s[0]],dy=my[d[0]];
        memset(grid,0,sizeof(grid));
        memset(vis,0,sizeof(vis));
        memset(lvl,0,sizeof(lvl));
        int fx[]= {-1,-1,1,1,-2,-2,2,2};
        int fy[]= {-2,2,-2,2,1,-1,1,-1};
        queue<pii>q;
        q.push(mp(sx,sy));
        lvl[sx][sy]=0;
        vis[sx][sy]=1;
        while(!q.empty())
        {
            pii top=q.front();
            q.pop();
            int k;
            int tx=top.first;
            int ty=top.second;
            int ax,ay;
            for(k=0; k<8; k++)
            {
                ax=tx+fx[k];
                ay=ty+fy[k];
                if(ax>0&&ax<9&&ay>0&&ay<9&&vis[ax][ay]==0)
                {
                    vis[ax][ay]=1;
                    lvl[ax][ay]=lvl[tx][ty]+1;
                    q.push(mp(ax,ray));

                }
            }


        }
        printf("To get from %s to %s takes %d knight moves.\n",s,d,lvl[dx][dy]);

    }
    return 0;

}
