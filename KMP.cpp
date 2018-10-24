#include<bits/stdc++.h>
using namespace std;
#define MX 100001

string text,pattern;
int n,m;
int failure[MX];

void makeFailureTable()
{
    int i,j;
    for(i=2; i<=m; i++)
    {
        j = failure[i-1];
        while(true)
        {
            if(pattern[j] == pattern[i-1])
            {
                failure[i] = j+1;
                break;
            }

            if(j==0)
            {
                failure[i] = 0;
                break;
            }
            else
            {
                j = failure[j];
            }
        }

    }
}

int match()
{
    int i=0,j=0;
    while(true)
    {

        if(i == n)
            return -1;
        if(text[i] == pattern[j])
        {
            i++;
            j++;

            if(j == m)
            {
                return i-m;
            }
        }
        else
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                j = failure[j];
            }
        }

    }
    return -1;
}

int main()
{
    cin>>text>>pattern;

    n = text.size();
    m = pattern.size();

    makeFailureTable();

    cout<<match();

    return 0;
}
