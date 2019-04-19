#include<bits/stdc++.h>
using namespace std;
#define MX 101

int sz[MX];
int clr[MX];
vector<int>g[MX];
vector<int> *vec[MX];
int cnt[MX];

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


void dfs(int u, int p, bool keep)
{
    int mx = -1, big_child = -1;

    for(auto &v : g[u])
    {
        if(v != p && sz[v] > mx)
        {
            mx = sz[v], big_child = v;
        }
    }
    for(auto &v : g[u])
    {
        if(v != p && v != big_child)
        {
            dfs(v, u, 0);
        }
    }
    if(big_child != -1)
    {
        dfs(big_child, u, 1), vec[u] = vec[big_child];
    }
    else
    {
        vec[u] = new vector<int> ();
    }

    vec[u]->push_back(u);

    cnt[ clr[u] ]++;

    for(auto &v : g[u])
    {
        if(v != p && v != big_child)
        {
            for(auto &it : *vec[v])
            {
                cnt[ clr[it] ]++;
                vec[u] -> push_back(it);
            }
        }
    }

    //now cnt array contains the answer for node u
    //now cnt[c] simply represents the number of nodes with color c in subtree of u



    if(keep == 0)
    {
        for(auto &v : *vec[u])
        {
            cnt[ clr[v] ]--;
        }
    }
}



int main()
{
    return 0;
}
