#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define MX 1000001

pll operator+ (pll a, ll x)
{
    return {a.F + x, a.S + x} ;
}
pll operator- (pll a, ll x)
{
    return {a.F - x, a.S - x} ;
}
pll operator* (pll a, ll x)
{
    return {a.F * x, a.S * x} ;
}
pll operator+(pll x, pll y)
{
    return {x.F + y.F,x.S + y.S} ;
}
pll operator-(pll x,pll y)
{
    return {x.F - y.F, x.S - y.S} ;
}
pll operator*(pll x,pll y)
{
    return {x.F * y.F, x.S * y.S} ;
}
pll operator%(pll x,pll y)
{
    return {x.F % y.F, x.S % y.S} ;
}

ll bigMod(ll x,ll n,ll mod)
{
    if(n == 0)
        return 1LL;

    ll t = bigMod(x,n/2,mod);
    t = (t%mod * t%mod)%mod;
    if(n%2==1)
    {
        t = (t%mod * x%mod)%mod;
    }
    return t;
}


pll base = {37,41};
pll mod = {1000000007,1000000009};
pll pwr[MX];



void calcPwr()
{
    pwr[0] = {1,1};

    for(int i=1; i<MX; i++)
    {
        pwr[i] = (pwr[i-1]*base)%mod;
    }
}


pll calcPrefHash(const string &s)
{
    pll h = {0,0};

    for(int i=0; i<s.size(); i++)
    {
        h = (h + (pwr[i] * (s[i]-'a'+1))%mod)%mod;
    }
    return h;
}

pll calcSuffHash(const string &s)
{
    pll h = {0,0};

    for(int i=s.size()-1; i>=0; i--)
    {
        h = (h + (pwr[s.size()-i-1] * (s[i]-'a'+1))%mod)%mod;
    }
    return h;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}





