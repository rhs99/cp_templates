#include <bits/stdc++.h>
using namespace std;
#define inf 1e8

int const ALPHA = 26;

struct Node
{
	int to[ALPHA];
	bool leaf;
	int link;
    int ext;
    int lvl;

	Node()
    {
		leaf = link = ext = lvl = 0;
		for(int i = 0;  i < ALPHA ; i++)
            to[i] = 0;
	}
};

vector<Node> t;

void add(string &s)
{
	int v = 0;

	for(auto ch : s)
    {
		if(!t[v].to[ch-'a'])
        {
			t[v].to[ch-'a'] = t.size();
			t.push_back(Node());
	    }

		v = t[v].to[ch-'a'];
	}

	t[v].leaf = 1;
}

void build_aho()
{
	queue < int > q;
	q.push(0);

	while(!q.empty())
    {
		int p = q.front();
		q.pop();

		for(int ch = 0; ch < ALPHA; ch++)
        {
			int v = t[p].to[ch];

			if(v)
            {
				t[v].link = (p == 0)? 0 : t[t[p].link].to[ch];

                if(t[t[v].link].leaf)
                {
                    t[v].ext = t[v].link;
                }
                else
                {
                    t[v].ext = t[t[v].link].ext;
                }
                t[v].lvl = t[p].lvl + 1;
				q.push(v);
			}
			else
            { 
				t[p].to[ch] = t[t[p].link].to[ch];
			}
		}
	}
}



int main(){

	ios::sync_with_stdio(false);
    cin.tie(0);

    // string s;
    // cin>>s;

    // int n;
    // cin>>n;

    // vector<pair<int,string>>q(n);

    // for(int i=0;i<n;i++)
    // {
    //     cin>>q[i].first>>q[i].second;
    //     add(q[i].second);
    // }

    // build_aho();

    int tc;
    cin>>tc;

    for(int cs=1;cs<=tc;cs++)
    {
        t.clear();
        t.push_back(Node());

        int n;
        cin>>n;
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            add(s);
        }
        build_aho();

        cin>>s;
        vector<int>dp(s.size()+1,inf);
        dp[0] = 0;
        int cur = 0;
        for(int i=1;i<=s.size();i++)
        {
            cur = t[cur].to[s[i-1]-'a'];
            int temp = cur;
            while(temp != 0)
            {
                if(t[temp].leaf)
                    dp[i] = min(dp[i],1 + dp[i-t[temp].lvl]);
                temp = t[temp].ext;
            }
        }

        if(dp[s.size()] == inf)
             cout<<"Case "<<cs<<": impossible"<<"\n";
        else
            cout<<"Case "<<cs<<": "<<dp[s.size()]<<"\n";
    }

	 
	return 0;
}


