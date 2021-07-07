#include<bits/stdc++.h>
using namespace std;
#define MX 101
int g[MX][MX],rg[MX][MX],p[MX];
bool vis[MX];
int n,src,tar;
bool bfs()
{
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(src);
    vis[src] = 1;
    p[src] = -1;
    int u,v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i=1; i<=n; i++)
        {
            if(i!=u&&!vis[i]&&rg[u][i]>0)
            {
                v = i;
                q.push(v);
                vis[v] = 1;
                p[v] = u;
            }
        }
    }
    return vis[tar];
}
int maxflow()
{
    int flow = 0;
    int u,v,mn;
    while(bfs())
    {
        mn = INT_MAX;
        v = tar;
        while(p[v] !=- 1)
        {
            u = p[v];
            mn = min(mn,rg[u][v]);
            v = p[v];
        }
        v = tar;
        while(p[v] !=- 1)
        {
            u = p[v];
            rg[u][v] -= mn;
            rg[v][u] = g[u][v]-rg[u][v];
            v = p[v];
        }
        flow += mn;
    }
    return flow;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    int c,i,u,v,w;
    for(int tc=1; tc<=tc; tc++)
    {
        scanf("%d",&n);
        scanf("%d%d%d",&src,&tar,&c);
        for(i=0; i<c; i++)
            scanf("%d%d%d",&u,&v,&w);;
        {
            g[u][v] += w;
            g[v][u] = g[u][v];
        }
        for(u=1; u<=n; u++)
        {
            for(v=1; v<=n; v++)
            {
                rg[u][v] = g[u][v];
            }
        }
        printf("Case %d: %d\n",tc,maxflow());
        memset(g,0,sizeof(g));
    }
    return 0;
}
