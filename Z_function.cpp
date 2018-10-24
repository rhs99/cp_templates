#include<bits/stdc++.h>
using namespace std;
#define MX 100001

int Z[MX];

void makeZtable(const string &s,int len)
{
    int i,j,k,l=-1,r=-1;
    for(i=1; i<len; i++)
    {
        if(i>r)
        {
            l = r = i;
            while(r<len && s[r] == s[r-l])
            {
                r++;
            }
            Z[i] = r-l;
            r--;
        }
        else
        {
            k = i-l;
            if(Z[k]<r-i+1)
            {
                Z[i] = Z[k];
            }
            else
            {
                l = i;
                while(r<len && s[r-l] == s[r])
                {
                    r++;
                }
                Z[i] = r-l;
                r--;
            }
        }
    }

}

int main()
{
    string text,pattern;
    cin>>text>>pattern;

    string newStr = pattern + "$" + text;

    makeZtable(newStr,newStr.size());

    for(int i=pattern.size()+1; i<newStr.size(); i++)
    {

        if(Z[i] == pattern.size())
        {
            cout<<(i - (pattern.size()+1))<<endl;
        }
    }

    return 0;
}
