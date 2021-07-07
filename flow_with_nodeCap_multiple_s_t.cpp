#include<bits/stdc++.h>
using namespace std;
#define INF 10000000
#define MX 210
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
            rg[v][u] += mn;
            v = p[v];
        }
        flow += mn;
    }
    return flow;
}
int main()
{
    int t;
    scanf("%d",&t);
    int N,c,i,u,v,w,e,ns,nt;
    for(int tc=1; tc<=t; tc++)
    {
        scanf("%d",&N);
        src = N+N+1;
        tar = src+1;
        for(i=1;i<=N;i++)
        {
            scanf("%d",&w);
            g[i][i+N] = w;
        }
        scanf("%d",&e);
        for(i=0;i<e;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            g[u+N][v] = w;
        }
        scanf("%d%d",&ns,&nt);
        for(i=0;i<ns;i++)
        {
            scanf("%d",&u);
            g[src][u] = INF;

        }
        for(i=0;i<nt;i++)
        {
            scanf("%d",&u);
            g[u+N][tar] = INF;

        }
        for(u=0;u<MX;u++)
        {
            for(v=0;v<MX;v++)
            {
                rg[u][v] = g[u][v];
            }
        }
        n = 2*N+2;
        printf("Case %d: %d\n",tc,maxflow());
        memset(g,0,sizeof(g));

    }
    return 0;
}
