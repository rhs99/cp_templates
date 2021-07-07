#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int MX = 100001;
int T[MX],P[MX][18],L[MX];
bool vis[MX];

int N;

vector<int>g[MX];

void dfs(int u,int par,int lvl)
{
    vis[u] = true;
    T[u] = par;
    L[u] = lvl;

    int v;

    for(int i=0; i<g[u].size(); i++)
    {
        v=g[u][i];

        if(!vis[v])
        {
            dfs(v,u,lvl+1);
        }
    }
}

void makeParseTable()
{
    memset(P,-1,sizeof(P));

    dfs(1,-1,0);

    for(int i=1; i<=N; i++)
    {
        P[i][0] = T[i];
    }

    for(int j=1; (1<<j)<N; j++)
    {
        for(int i=1; i<=N; i++)
        {
            if(P[i][j-1] != -1)
            {
                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
}

int lcaQuery(int p,int q)
{
    if(L[p]<L[q])
    {
        int t = q;
        q=p;
        p=t;
    }

    int log = 0;

    while(1)
    {
        int next = log+1;
        if((1<<next)>L[p])
        {
            break;
        }
        log++;
    }

    for(int i=log; i>=0; i--)
    {
        if(L[p]-(1<<i)>=L[q])
        {
            p=P[p][i];
        }
    }


    if(p == q)
    {
        return p;
    }

    for(int i=log; i>=0; i--)
    {
        if(P[p][i] != -1 && P[p][i] != P[q][i])
        {
            p=P[p][i];
            q=P[q][i];
        }
    }

    return T[p];


}


int main()
{
    makeParseTable();


    return 0;
}
