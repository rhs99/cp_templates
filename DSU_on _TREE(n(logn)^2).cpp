 #include<bits/stdc++.h>
using namespace std;
#define MX 101

int sz[MX];
int clr[MX];
vector<int>g[MX];
map<int,int> *cnt[MX];

void subtree_size(int u,int p)
{
    sz[u] = 1;
    for(int v : g[u])
    {
        if(v != p)
        {
            subtree_size(v,u);
            sz[u] += sz[v];
        }
    }
}

void dfs(int u,int p)
{
    int mx = -1,big_child = -1;
    
    for(int v : g[u])
    {
        if(v != p)
        {
            dfs(v,u);
            
            if(sz[v] > mx)
            {
                mx = sz[v];
                big_child = v;
            }
        }
    }
    
    if(big_child != -1)
    {
        cnt[u] = cnt[big_child];
    }
    else
    {
        cnt[u] = new map<int,int>();
    }
    
    (*cnt[u])[clr[u]]++;
    
    for(int v : g[u])
    {
        if(v != p && v != big_child)
        {
            for(auto &it : *cnt[v])
            {
                (*cnt[u])[it.first] += it.second;
            }
        }
    }
    
    //now (*cnt[u])[c] is the number of vertices in subtree of vertex u that has color c
}

int main()
{
    return 0;
}
