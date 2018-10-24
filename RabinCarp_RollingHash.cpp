#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll calcHash(const string &s,int m,int b,int MOD)
{
    ll power = 1LL;
    ll hashVal = 0;

    for(int i=m-1; i>=0; i--)
    {
        hashVal = hashVal + (power * ((int)s[i]));
        hashVal = hashVal%MOD;
        power = (power*b)%MOD;
    }
    return hashVal;
}

int match(const string &text,const string &pattern,int n,int m)//returns the index of text from where pattern is found
{

	int b1 = 347,mod1 = 1000000007;
	int b2 = 367,mod2 = 1000000009;

    ll patternHash1 = calcHash(pattern,m,b1,mod1);
	ll patternHash2 = calcHash(pattern,m,b2,mod2);

	ll rollingHash1 = calcHash(text,m,b1,mod1);
	ll rollingHash2 = calcHash(text,m,b2,mod2);

	if(rollingHash1 == patternHash1 && rollingHash2 == patternHash2)
		return 0;

	ll power1 = 1LL,power2 = 1ll;

	for(int i=1;i<m;i++)
	{
		power1 = (power1*b1)%mod1;
		power2 = (power2*b2)%mod2;
	}

	for(int i=m;i<n;i++)
	{
		rollingHash1 = rollingHash1 - (power1 * (int)text[i-m])%mod1;
		rollingHash1 = (rollingHash1 + mod1)%mod1;
		rollingHash1 = (rollingHash1 * b1)%mod1;
		rollingHash1 = (rollingHash1 + (int)text[i])%mod1;

		rollingHash2 = rollingHash2 - (power2 * (int)text[i-m])%mod2;
		rollingHash2 = (rollingHash2 + mod2)%mod2;
		rollingHash2 = (rollingHash2 * b2)%mod2;
		rollingHash2 = (rollingHash2 + (int)text[i])%mod2;

		if(rollingHash1 == patternHash1 && rollingHash2 == patternHash2)
			return i-m+1;
	}

	return -1;

}


int main()
{
    int n;
    int m;
    string text,pattern;

    cin>>text>>pattern;

    n = text.size();
    m = pattern.size();

	cout<<match(text,pattern,n,m);

    return 0;
}
