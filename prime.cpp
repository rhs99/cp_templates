#include<bits/stdc++.h>
using namespace std;
#define mx 1000007
#define pb push_back
vector<int>prime;
vector<int>factor[10000];
vector<bool>mark(mx,false);

void seive()
{
    int i,j,limit=sqrt(mx*1.0);
    mark[1]=true;
    prime.pb(2);
    for(i=4; i<mx; i+=2)
        mark[i]=true;
    for(i=3; i<mx; i+=2)
    {
        if(!mark[i])
        {
            prime.pb(i);
            if(i<=limit)
            {
                for(j=(i*i); j<mx; j+=(i*2))
                {
                    mark[j]=true;
                }
            }
        }
    }
}

int main()
{

    seive();
    long long k=1;
    cout<<(k<<31);
    int i,j;
    for(i=0; i<prime.size(); i++)
    {
        for(j=prime[i]; j<mx; j=(j+prime[i]))
        {
            factor[j].pb(prime[i]);
        }
    }

    int t,p,l,d,c=0;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d%d",&p,&l);
        d=p-l;
        printf("Case %d: ",i);
        for(j=0; j<factor[d].size(); j++)
        {
            if(factor[d][j]>l)
            {
                printf("%d ",factor[d][j]);
                c++;
            }
        }
        if(c==0)
        {
            printf("impossible\n");
        }
        else
            printf("\n");
        c=0;

    }

    return 0;

}

