#include<bits/stdc++.h>
using namespace std;
#define pb push_back
bool isBackEdge(vector<int>graph[],bool vis[],bool recstk[],int v)
{
    if(!vis[v])
    {
        vis[v]=true;
        recstk[v]=true;
        vector<int>::iterator it;
        for(it=graph[v].begin(); it!=graph[v].end(); it++)
        {
            if(!vis[*it]&&isBackEdge(graph,vis,recstk,*it))
                return true;
            else if(recstk[*it])
                return true;
        }
    }

    recstk[v]=false;
    return false;
}

bool isCycle(vector<int>graph[],int v)
{
    int i;
    bool vis[v];
    bool recstk[v];
    for(i=0; i<v; i++)
    {
        vis[i]=false;
        recstk[i]=false;
    }
    for(i=0; i<v; i++)
    {
        if(isBackEdge(graph,vis,recstk,i))
            return true;
    }
    return false;

}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>graph[v];
    int i,a,b;;
    for(i=0; i<e; i++)
    {
        cin>>a>>b;
        graph[a].pb(b);
    }
    if(isCycle(graph,v))
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
