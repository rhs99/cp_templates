#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define MAX 1000008
bool v[MAX];
int len, sp[MAX];

void Sieve()
{
    for (int i = 2; i < MAX; i += 2)
            sp[i] = 2;

    for (ll i = 3; i < MAX; i += 2)
    {
        if (!v[i])
        {
            sp[i] = i;
            for (ll j = i; (j*i) < MAX; j += 2)
            {
                if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
            }
        }
    }
}

int main()
{
    Sieve();
    int t;
    cin>>t;
    int i;
    for(i=1; i<=t; i++)
    {
        ll n;
        cin>>n;
        ll d=sp[n];
        if(d==n)
        {
            double f=1.0;
            printf("Case %d: %lf\n",i,f);
        }
        else
        {
            map<ll,int>my;
            ll c=0;
            while(n!=1)
            {
                ll p=sp[n];
                my[p]++;
                n=n/p;
                c++;
            }
            ll f=0;
            map<ll,int>::iterator it;
            for(it=my.begin(); it!=my.end(); it++)
            {
                ll x,y;
                x=it->x;
                y=it->y;
                f+=((x*y*1.0)/(c*1.0));
            }

            printf("Case %d: %lf\n",i,f);
        }
    }

    return 0;
}
