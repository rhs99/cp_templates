#include<bits/stdc++.h>
using namespace std;
#define MX 100001


int N ;
int SA[MX];
int P [20][MX];
//P[i][j] denotes rank of suffix at position 'j' when all suffixes are sorted by their first '2^i' characters
int pwr [20];

struct Tuple
{
    int first, second, index;
    Tuple() {}
    Tuple(int x,int y,int z)
    {
        first = x;
        second = y;
        index = z;
    }
    bool operator<(const Tuple &rhs)const
    {
        if(first == rhs.first)
            return second<rhs.second;
        return first<rhs.first;
    }
};

Tuple L[MX];


int main()
{

    string s;
    cin>>s;
    N = s.size();
    int i,j;

    pwr[0]=1;
    for(i=1; i<=20; i++)
    {
        pwr[i] = pwr[i-1]*2;
    }

    for(i=1; i<=N; i++)
    {
        P[0][i] = s[i-1]-'a';
        // Give initial rank when suffixes are sorted by their first 2^0 = 1 character.
    }


    int step = 1;

    for (i = 1; pwr[i-1]<N; i++, step++)
    {
        for (j = 1 ; j<=N; j++)
        {
            L[j].index = j;
            L[j].first = P[i-1][j];
            L[j].second = (j+pwr[i-1]<=N ? P[i-1][j+pwr[i-1]] : -1);
        }

        sort(L+1,L+N+1);

        for (j = 1; j<=N; j++)
        {
            P[i][L[j].index] = ((j>1 and L[j].first==L[j-1].first and L[j].second==L[j-1].second) ? P[i][L[j-1].index] : j);
            //Assign same rank to suffixes which have same number in the first and second fields of their respective tuples
        }
    }

    step = step - 1;

    if(N==1)
    {
        P[0][1] = 1;
    }

    for (i = 1; i<=N; i++)
    {
        SA[P[step][i]] = i;
    }

    for(i=1; i<=N; i++)
    {
        cout<<i<<" "<<SA[i]<<endl;
    }

    return 0;
}
