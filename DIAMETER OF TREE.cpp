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
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int rst(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool chk(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

int n;
vector<int>g[10007];
bool vis[10007];
int mx=-1,node=-1;
void dfs(int s,int l)
{
    if(l>mx)
    {
        mx=l;
        node=s;
    }
    if(!vis[s])
    {
        vis[s]=1;
        vector<int>::iterator it;
        for(it=g[s].begin(); it!=g[s].end(); it++)
        {
            if(!vis[*it])
            {
                dfs(*it,l+1);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    memset(vis,0,sizeof(vis));
    cin>>n;
    int i,u,v;
    for(i=0; i<n-1; i++)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0);
    memset(vis,0,sizeof(vis));
    mx=-1;
    dfs(node,0);
    cout<<mx;
    return 0;
}








