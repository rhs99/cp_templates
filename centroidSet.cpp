#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
 
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
 
#define ri(n) scanf("%d",&n)
#define rl(n) scanf("%lld",&n)
 
#define MX 100010
#define inf 1e18
#define MOD 1000000007
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
//find_by_order(k) --> returns iterator to the kth largest element counting from 0
//order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int setBit(int n,int p)
{
    return n|(1<<p);
}
bool checkBit(int n,int p)
{
    return (bool)(n&(1<<p));
}
 
int fx[]= {0,0,-1,1};
int fy[]= {-1,1,0,0};
 
ll bigMod(ll x,ll n)
{
    if(n==0)
        return 1;
    ll t = bigMod(x,n/2);
    t = ((t%MOD)*(t%MOD))%MOD;
    if(n%2)
    {
        t = ((x%MOD)*(t%MOD))%MOD;
    }
    return t;
}
//***********************************************************************//
const int LOGN = 20;
set<int>g[MX];
int lvl[MX],table[MX][LOGN];

/*-----------------------------------------lca----------------------------*/
void dfs(int u,int p)
{
    lvl[u] = p!=-1 ? lvl[p] + 1 : 0;
    table[u][0] = p;
    for(auto v:g[u])
    {
        if(v != p)
            dfs(v,u); 
    }
}

void make_sparse_table(int n)
{
    memset(table,-1,sizeof(table));
    dfs(1,-1);
    for(int j=1;j<LOGN;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(table[i][j-1] != -1)
                table[i][j] = table[table[i][j-1]][j-1];
        }
    }
}

int lca(int u,int v)
{
    if(lvl[u] < lvl[v])
        swap(u,v);
    for(int i=LOGN-1;i>=0;i--)
    {
        if(lvl[u]-(1<<i) >= lvl[v])
        {
            u = table[u][i];
        }
    }
    if(u == v)
        return v;
    
    for(int i=LOGN-1;i>=0;i--)
    {
        if(table[u][i] != -1 && table[u][i] != table[v][i])
        {
            u = table[u][i];
            v = table[v][i];
        }
    }
    return table[v][0];
}


/*------------centroid decomposition-------------*/
int dad[MX],sub[MX];

int sub_dfs(int u,int p)
{
    sub[u] = 1;
    for(auto v:g[u])
    {
        if(v != p)
            sub[u] += sub_dfs(v,u);
    }
    return sub[u];
}

int get_centroid(int u,int p,int sz)
{
    for(auto v:g[u])
    {
        if(v != p && sub[v] > sz/2)
        {
            return get_centroid(v,u,sz);
        }
    }
    return u;
}

void build(int u,int p)
{
    int sub_sz = sub_dfs(u,p);
    int centroid = get_centroid(u,p,sub_sz);
    dad[centroid] = p == -1 ? centroid : p;

    for(auto v:g[centroid])
    {
        g[v].erase(centroid);
        build(v, centroid);
    }
    g[centroid].clear();
}

/*-----------handle queries-------------*/
int vis[MX];
set<pll>ans[MX];

ll dist(int u,int v)
{
    return lvl[u] + lvl[v] - 2*lvl[lca(u,v)];
}

void update(int u)
{
    int ancestor = u;
    while(true)
    {
        ll d = dist(u,ancestor);

        if(vis[u])
            ans[ancestor].insert({d,u});
        else
            ans[ancestor].erase({d,u});
        
        // cout<<"node "<<ancestor<<" "<<ans[ancestor].size()<<endl;

        if(ancestor == dad[ancestor])
            return;
        ancestor = dad[ancestor];
    }
}

ll query(int u)
{
    int ancestor = u;
    ll ret = inf;
    while(true)
    {
        // cout<<"node "<<ancestor<<endl;
        // for(auto it:ans[ancestor])
        // {
        //     cout<<"dis "<<it.first<<" "<<it.second<<endl;
        // }

        if(ans[ancestor].size())
        {
            ret = min(ret,dist(u,ancestor) + (*ans[ancestor].begin()).first);
        }
        
        if(ancestor == dad[ancestor])
            return ret==inf?-1:ret;
        ancestor = dad[ancestor];
    }
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m,u,v,t;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }

    make_sparse_table(n);
    build(1,-1);

    cin>>m;

    while(m--)
    {
        cin>>t>>u;
        if(t == 0)
        {
            vis[u] ^= 1;
            update(u);
        }
        else
            cout<<query(u)<<"\n";
    }

    return 0;
}
 