#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MX 107

int prime[(MX/64)+7];
vector<int>allprimes;

bool ifnotPrime(int x)
{
    return (prime[x/64] & (1 << ((x >> 1) & 31)));
}

bool makeComposite( int x)
{
    prime[x/64] |= (1 << ((x >> 1) & 31));
}

void bitWiseSieve()
{
    int lim = sqrt(MX+7);



    for (int i = 3; i < lim; i += 2)
    {
        if (!ifnotPrime(i))
        {

            for (int j = i * i, k = i << 1; j < MX; j += k)
            {
                makeComposite(j);
            }
        }
    }

    allprimes.pb(2);

    for (int i = 3; i <MX; i += 2)
    {
        if (!ifnotPrime(i))
        {
            allprimes.pb(i);
        }
    }
}

int main()
{
    bitWiseSieve();



    return 0;
}
