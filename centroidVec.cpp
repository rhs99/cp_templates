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
 
#define MX 200010
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
int n,k;
bool processed[MX];
int cnt[MX],sub[MX];
vector<int>g[MX];
ll ans;
int mx_lvl;
 
/*------------centroid decomposition-------------*/
 
int sub_dfs(int u,int p)
{
    sub[u] = 1;
    for(int v:g[u])
    {
        if(v != p && !processed[v])
            sub[u] += sub_dfs(v,u);
    }
    return sub[u];
}
 
int get_centroid(int u,int p,int sz)
{
    for(int v:g[u])
    {
        if(v != p && !processed[v] && sub[v] > sz)
        {
            return get_centroid(v,u,sz);
        }
    }
    return u;
}
 
void dfs(int u,int p,int lvl,bool flag)
{
    if(lvl > k)
        return;
    
    mx_lvl = max(mx_lvl,lvl);
 
    if(flag)
        cnt[lvl]++;
    else
        ans += cnt[k-lvl];
    
    for(int v:g[u])
    {
        if(v!=p && !processed[v])
        {
            dfs(v,u,lvl+1,flag);
        }
    }
}
 
void centroid_decompose(int u)
{
    int sub_sz = sub_dfs(u,-1);
    int centroid = get_centroid(u,-1,sub_sz/2);
    processed[centroid] = 1;
 
    cnt[0] = 1;
    mx_lvl = 0;
 
    for(int v:g[centroid])
    {
        if(!processed[v])
        {
            dfs(v,centroid,1,0);
            dfs(v,centroid,1,1);
        }
    }
 
    fill(cnt+1,cnt+mx_lvl+1,0);
 
    for(int v:g[centroid])
    {
        if(!processed[v])
        {
            centroid_decompose(v);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int u,v;
    cin>>n>>k;
 
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
 
    centroid_decompose(1);
 
    cout<<ans<<"\n";
     
 
    return 0;
}