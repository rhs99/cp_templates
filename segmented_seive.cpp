#include<bits/stdc++.h>
using namespace std;
#define MX 50001
#define pb push_back
vector<int>prime;
vector<bool>mark(MX,false);

void seive()
{
    int i,j,limit=sqrt(MX*1.0);
    mark[1]=true;
    prime.pb(2);
    for(i=4; i<MX; i+=2)
        mark[i]=true;
    for(i=3; i<MX; i+=2)
    {
        if(!mark[i])
        {
            prime.pb(i);
            if(i<=limit)
            {
                for(j=(i*i); j<MX; j+=(i*2))
                {
                    mark[j]=true;
                }
            }
        }
    }
}

bool vis[100010];

int main()
{

    seive();

    int t,p;
    long long i,j,l,r;

    scanf("%d",&t);
    for(int tc = 1; tc<=t; tc++)
    {
        scanf("%lld%lld",&l,&r);



        for(i=0; i<prime.size(); i++)
        {
            if(prime[i]*prime[i]<=r)
            {
                p = (l-1)/prime[i];
                p += 1;

                if(p%2==0)
                    p++;
                if(p==1)
                    p+=2;

                for(j = prime[i]*p; j<=r; j+=(prime[i]*2))
                {


                    vis[j-l] = 1;
                }


            }

        }
        p=0;
        for(j=0; j<(r-l+1); j++)
        {
            if(j+l==1)
                continue;

            if(j+l == 2)
            {
                p++;
                continue;
            }
            if((j+l)%2 && !vis[j])
            {
                p++;
            }
        }

        printf("Case %d: %d\n",tc,p);

        memset(vis,0,sizeof(vis));

    }

    return 0;

}

