#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define in insert
#define x first
#define y second
#define inf INT_MAX
#define mx 10001
vector<pii>g[mx];
bool inMST[mx];
vector<int>key(mx,inf);
int main()
{

    ios::sync_with_stdio(false);
    memset(inMST,0,sizeof(inMST));
    int n,m;
    int i;
    int u,v,w;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>u>>v>>w;
        g[u].pb(mp(v,w));
        g[v].pb(mp(u,w));
    }
    ll src=1,ans=0;
    key[src]=0;
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    pq.push(mp(0,src));
    while(!pq.empty())
    {
        pii top=pq.top();
        pq.pop();
        if(!inMST[top.y])
        {
            inMST[top.y]=1;
            ans+=top.x;
        }
        vector<pii>::iterator it;
        for(it=g[top.y].begin(); it!=g[top.y].end(); it++)
        {
            pii adj=*it;
            if((!inMST[adj.x])&&(key[adj.x]>adj.y))
            {
                key[adj.x]=adj.y;
                pq.push(mp(adj.y,adj.x));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}


