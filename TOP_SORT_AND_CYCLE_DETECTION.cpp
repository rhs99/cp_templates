#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pci pair<char,int>
#define pb push_back
#define mp make_pair
#define x first
#define y second

map<char,vector<char> >graph;
map<char,int>vis;
map<char,int>rec;

stack<char>stk;
map<char,int>vis1;


void tops(char v)
{
    vis1[v] = 1;
    vector<char>::iterator i;
    for (i = graph[v].begin(); i != graph[v].end(); i++)
        if (vis1[*i]==0)
            tops(*i);
    stk.push(v);
}


void topsort()
{
    for (char t = 'a'; t <= 'z'; t++)
      if (vis1[t] == 0)
        tops(t);


    while (stk.empty() == false)
    {
        cout << stk.top();
        stk.pop();
    }
}






bool cycle(char v)
{
    if(vis[v]==0)
    {
        vis[v]=1;
        rec[v]=1;
        vector<char>::iterator it;
        for(it=graph[v].begin(); it!=graph[v].end(); it++)
        {
            if((vis[*it]==0)&&(cycle(*it)))
            {
                return true;
            }
            else if(rec[*it]==1)
                return true;

        }
    }
    rec[v]=0;
    return false;
}

bool iscycle()
{
    for(char t='a'; t<='z'; t++)
    {
        if(vis[t]==0)
        {
            if(cycle(t))
                return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int i,j;
    for(char t='a'; t<='z'; t++)
    {
        vis[t]=0;
        rec[t]=0;
        vis1[t]=0;

    }
    vector<string>v(n);
    for(i=0; i<n; i++)
    {
        cin>>v[i];
    }

    for(i=0; i<n-1; i++)
    {
        int l1=v[i].size(),l2=v[i+1].size();
        int mn=min(l1,l2);
        for(j=0; j<mn; j++)
        {
            if(v[i][j]!=v[i+1][j])
            {
               // cout<<v[i][j]<<" "<<v[i+1][j]<<endl;
                graph[v[i][j]].pb(v[i+1][j]);
                break;
            }
        }

        if(j==mn)
        {
            if(l1>l2)
            {
                cout<<"Impossible";
                return 0;
            }
        }


    }

    if(iscycle())
    {
        cout<<"Impossible";
    }
    else
    {

        topsort();

    }
}



/*int e;
    cin>>e;
    int i;
    for(char t='a'; t<='z'; t++)
    {
        vis[t]=0;
        rec[t]=0;

    }



    for(i=0; i<e; i++)
    {
        char a,b;
        cin>>a>>b;
        graph[a].pb(b);
    }
    if(iscycle())
        cout<<"yes";
    else
        cout<<"no";
*/

