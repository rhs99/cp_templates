#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define inf LONG_LONG_MAX
#define mx 100007
#define ll long long
vector<pii>g[mx];
vector<ll>dist(mx,inf);
vector<bool>vis(mx,false);
vector<int>par(mx,-1);

void dijkstra(void)
{
    dist[1]=0;
    par[1]=-1;
    priority_queue< pii,vector<pii>,greater<pii> >pq;
    pq.push(mp(0,1));
    while(!pq.empty())
    {
        pii u=pq.top();
        pq.pop();
        if(!vis[u.y])
        {
            vis[u.y]=true;
            vector<pii>::iterator it;
            for(it=g[u.y].begin(); it!=g[u.y].end(); it++)
            {
                pii v=*it;
                if(!vis[v.x])
                {
                    if((dist[u.y]+v.y)<dist[v.x])
                    {
                        dist[v.x]=dist[u.y]+v.y;
                        pq.push(mp(dist[v.x],v.x));
                        par[v.x]=u.y;
                    }
                }
            }
        }

    }
}

void prnt(int x)
{
    if(par[x]==-1)
    {
        cout<<x<<" ";
        return ;
    }
    prnt(par[x]);
    cout<<x<<" ";
}

int main()
{
    int n,m;
    cin>>n>>m;
    int i,a,b,w;
    for(i=0; i<m; i++)
    {
        cin>>a>>b>>w;
        g[a].pb(mp(b,w));
        g[b].pb(mp(a,w));

    }

    dijkstra();
    if(!vis[n])
        cout<<-1;
    else
        prnt(n);

    return 0;
}

