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
struct Query{
    int id,l,r;
    Query(){}
    Query(int a,int b,int c)
    {
        id = a;
        l = b;
        r = c;
    }
    bool operator<(const Query & rhs)
    {
        return r<rhs.r;
    }
};
//***********************************************************************//
int n;
ll a[MX];
ll tr[MX*4],lazyAdd[MX*4],lazyCnt[MX*4];
 
void build(int v,int b,int e)
{
    if(b == e)
    {
        tr[v] = a[b];
        return;
    }
 
    int mid = (b+e)/2;
    int left = v*2, right = left + 1;
 
    build(left, b, mid);
    build(right, mid+1, e);
 
    tr[v] = tr[left] + tr[right];
}
 
 
void push(int v,int b,int e)
{
    if(lazyAdd[v] || lazyCnt[v])
    {
        int left = v*2,right = left+1,mid = (b + e)/2;
        ll len = e-b+1;

        tr[v] += (lazyAdd[v]*len) + lazyCnt[v]*((len*(len+1))/2);

        if(b != e)
        {
            lazyAdd[left] += lazyAdd[v];
            lazyCnt[left] += lazyCnt[v];

            lazyAdd[right] += (lazyAdd[v] + (mid + 1 - b)*lazyCnt[v]);
            lazyCnt[right] += lazyCnt[v];
        }

        lazyAdd[v] = lazyCnt[v] = 0; 
    }    
}
 
void update(int v,int b,int e,int l,int r)
{
    push(v,b,e);

    if(e<l || b>r)
        return;

    if(b>=l && e<=r)
    {
        lazyAdd[v] += (b-l);
        lazyCnt[v] += 1;
        
        push(v,b,e);
        return;
    }
 
    int mid = (b+e)/2;
    int left = v*2, right = left + 1;
 
    update(left,b,mid,l,r);
    update(right,mid+1,e,l,r);
  
    tr[v] = tr[left] + tr[right];
}
 
ll query(int v,int b,int e,int l,int r)
{
    push(v,b,e);

    if(e<l || b>r)
        return 0;

    if(b>=l && e<=r)
    {
        return tr[v];
    }
 
    int mid = (b+e)/2;
    int left = v*2, right = left + 1;
 
    return query(left,b,mid,l,r) + query(right,mid+1,e,l,r);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin>>n>>q;
 
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
 
    build(1,1,n);
 
    while(q--)
    {
        int t;
        cin>>t;
        if(t == 1)
        {
            int l,r;
            cin>>l>>r;
            update(1,1,n,l,r);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<"\n";
        }
    }
   
    
    return 0;
}
 