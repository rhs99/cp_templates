#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define inf INT_MAX

typedef struct
{
    int u,v,w;
} edge;

int main()
{
    int t,x,y,w,i,j;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<edge>e(m+1);
        int dist[n+1];
        for(i=0; i<n; i++)
            dist[i]=inf;
        for(i=0; i<m; i++)
        {
            cin>>e[i].u>>e[i].v>>e[i].w;
        }
        dist[0]=0;
        for(i=0; i<n-1; i++)
        {
            for(j=0; j<m; j++)
            {

                if(dist[e[j].u]+e[j].w<dist[e[j].v])
                    dist[e[j].v]=dist[e[j].u]+e[j].w;
            }
        }
        bool flag=false;
        for(j=0; j<m; j++)
        {

            if(dist[e[j].u]+e[j].w<dist[e[j].v])
            {
                dist[e[j].v]=dist[e[j].u]+e[j].w;
                flag=true;
            }

        }

        if(!flag)
            cout<<"not possible"<<endl;
        else
            cout<<"possible"<<endl;



    }
    return 0;
}

