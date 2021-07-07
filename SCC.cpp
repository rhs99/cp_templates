#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define inf INT_MAX
#define mx 100007
#define mod 1000000007
int cost[mx];
int vis[mx];
vector<int>g[mx];
vector<int>rg[mx];
stack<int>stk;
int tr=0;
priority_queue< int,vector<int>,greater<int> >ans[mx];
void dfs1(int u)
{
    vis[u]=1;
    vector<int>::iterator it;
    for(it=g[u].begin(); it!=g[u].end(); it++)
    {
        if(!vis[*it])
            dfs1(*it);
    }
    stk.push(u);
}

void dfs2(int u)
{
    vis[u]=1;
    ans[tr].push(cost[u]);
    vector<int>::iterator it;
    for(it=rg[u].begin(); it!=rg[u].end(); it++)
    {
        if(!vis[*it])
            dfs2(*it);
    }
    stk.push(u);
}


int main()
{
    int n;
    cin>>n;
    int i;
    for(i=1; i<=n; i++)
        cin>>cost[i];
    int m,u,v;
    cin>>m;
    for(i=0; i<m; i++)
    {
        cin>>u>>v;
        g[u].pb(v);
        rg[v].pb(u);

    }

    for(i=1; i<=n; i++)
    {
        if(!vis[i])
            dfs1(i);
    }

    memset(vis,0,sizeof(vis));

    while(!stk.empty())
    {
        u=stk.top();
        stk.pop();
        if(!vis[u])
        {
            dfs2(u);
            tr++;
        }
    }
    ll s=0,way=1;
    for(i=0;i<tr;i++)
    {
        int c=0;
        int t;
        t=ans[i].top();
        int mn=t;
        s+=mn;
        while(!ans[i].empty())
        {
            t=ans[i].top();
            ans[i].pop();
            if(t==mn)
                c++;
        }
        way=((way%mod)*(c%mod))%mod;
    }
    cout<<s<<" "<<way<<endl;
    return 0;
}


