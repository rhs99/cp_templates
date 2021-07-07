#include<bits/stdc++.h>
using namespace std;
map<string,int>sum;
map<string,string>p;
map<string,int>vis;
string Find(string x)
{
    if(p[x]==x)
        return x;
    else
        return p[x]=Find(p[x]);
}
int Union(string a,string b)
{
    string x,y;
    x=Find(a);
    y=Find(b);
    if(x!=y)
    {
        p[x]=y;
        sum[y]+=sum[x];
    }
    return  sum[y];

}
int main()
{
    int t;
    string a,b;
    cin>>t;
    while(t--)
    {
        int f;
        cin>>f;
        while(f--)
        {
            cin>>a>>b;
            if(vis[a]==0)
            {
                vis[a]=1;
                sum[a]=1;
                p[a]=a;
            }
            if(vis[b]==0)
            {
                vis[b]=1;
                sum[b]=1;
                p[b]=b;
            }
            cout<< Union(a,b)<<endl;
        }
        p.clear();
        vis.clear();
        sum.clear();

    }
    return 0;
}
