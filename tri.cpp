#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

#define p 101
#define p2 31
#define MOD 1000000007
#define MOD2 1000000009
#define MX 100001

string str;
int n;
ll arr[MX];
unsigned long long int power[MX],power2[MX],prefix[MX],prefix2[MX];


unsigned long long int modPow(unsigned long long int base,
                              unsigned long long int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    unsigned long long int temp = modPow(base, exponent/2);

    if (exponent %2 ==0)
        return (temp%MOD * temp%MOD) % MOD;
    else
        return ((( temp%MOD * temp%MOD)%MOD) * base%MOD) % MOD;
}

unsigned long long int findMMI(unsigned long long int n)
{
    return modPow(n, MOD-2);
}

pii computePrefixHash()
{
    prefix[0] = 0;
    prefix[1] = str[0];
    prefix2[0] = 0;
    prefix2[1] = str[0];

    for (int i=2; i<=n; i++){
        prefix[i] = (prefix[i-1]%MOD +
                     (str[i-1]%MOD * power[i-1]%MOD)%MOD)%MOD;

         prefix2[i] = (prefix2[i-1]%MOD2 +
                     (str[i-1]%MOD2 * power2[i-1]%MOD2)%MOD2)%MOD2;
    }

    return pii(prefix[n],prefix2[n]);
}




void computePowers(int n)
{
    power[0] = 1,power2[0] = 1;
    for(int i=1; i<=n; i++){
        power[i] = (power[i-1]%MOD * p%MOD)%MOD;
        power2[i] = (power2[i-1]%MOD * p2%MOD2)%MOD2;
    }
    return;
}

struct node
{
    int smart;
    pii hashval;
    bool endmark;
    node* next[26];
    node()
    {
        smart=0;
        hashval=pii{-1,-1};
        endmark = false;
        for(int i=0; i<26; i++)
        {
            next[i] = NULL;
        }
    }
}*root;
void Insert(string & str,int len,pii hv,int sm)
{
    node* curr = root;
    int i,id;

    for(i=0; i<len; i++)
    {
        id = str[i]-'a';
        if(curr->next[id]==NULL)
        {
            curr->next[id] = new node();
            curr->next[id]->smart=sm;
            curr->next[id]->hashval=hv;
        }
        else
        {
            if(sm>curr->smart)
            {
                curr->next[id]->smart=sm;
                curr->next[id]->hashval=hv;

            }
        }
        curr = curr->next[id];
    }
    curr->endmark = true;
}
ll Search(string &str,int len,pii hv)
{
    node* curr = root;
    int i,id,temp=0;
    for(i=0; i<len; i++)
    {
        id = str[i]-'a';
        if(curr->next[id]==NULL)
        {
            if(hv==curr->hashval)
            {
                return max(temp,curr->smart+i);
            }
            return max(temp,i);
        }
        if(hv==curr->hashval)
        {
            temp= max(temp,curr->smart+i+1);
        }
        else temp=max(i+1,temp);

        curr = curr->next[id];
    }
    return temp;

}
void Delete(node* curr)
{
    for(int i=0; i<26; i++)
    {
        if(curr->next[i])
        {
            Delete(curr->next[i]);
        }
    }
    delete curr;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--)
    {
        root = new node();
        computePowers(MX-1);
        map<pii,ll>mp;
        int nn;
        cin>>nn;
        string s;
        int i;
        for(i=0; i<nn; i++)
            cin>>arr[i];
        pii hashval;
        for(i=0; i<nn; i++)
        {
            cin>>s;
            str=s;
            sort(str.begin(),str.end());
            n = str.size();
            hashval=computePrefixHash();
            mp[hashval]=max(mp[hashval],arr[i]);
            Insert(s,n,hashval,arr[i]);
        }
        int q;
        cin>>q;

        while(q--)
        {
            cin>>s;
            str=s;
            sort(str.begin(),str.end());
            n = str.size();
            hashval = computePrefixHash();

            ll ans = max(Search(s,n,hashval),mp[hashval]);
            cout<<ans<<"\n";


        }
        Delete(root);
    }





    return 0;
}








