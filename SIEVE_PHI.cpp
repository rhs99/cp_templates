#include<bits/stdc++.h>
using namespace std;
#define mx 5000000
#define ll unsigned long long
ll phi[mx+1];
void sievephi()
{
    int i,j;
    for(i=2; i<=mx; i++)
    {
        phi[i]=i;
    }
    for(i=2; i<=mx; i++)
    {
        if(phi[i]==i)
        {
            for(j=i; j<=mx; j+=i)
            {
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }

    phi[1]=0;
    for(i=2; i<=mx; i++)
    {
        phi[i]*=phi[i];
    }
    for(i=2; i<=mx; i++)
    {
        phi[i]+=phi[i-1];
    }

}
int main()
{
    sievephi();
    int t,a,b;
    scanf("%d",&t);
    for(ll tc=1; tc<=t; tc++)
    {
        scanf("%d%d",&a,&b);
        printf("Case %d: %llu\n",tc,phi[b]-phi[a-1]);
    }
    return 0;

}
