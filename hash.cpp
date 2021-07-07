#include<bits/stdc++.h>
using namespace std;

#define p 101
#define MOD 1000000007
#define MX 100001

string str;
int n;

unsigned long long int power[MX],prefix[MX],suffix[MX];


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

void computePrefixHash()
{
    prefix[0] = 0;
    prefix[1] = str[0];

    for (int i=2; i<=n; i++)
        prefix[i] = (prefix[i-1]%MOD +
                     (str[i-1]%MOD * power[i-1]%MOD)%MOD)%MOD;

    return;
}


void computeSuffixHash()
{
    suffix[0] = 0;
    suffix[1] = str[n-1];

    for (int i=n-2, j=2; i>=0 && j<=n; i--,j++)
        suffix[j] = (suffix[j-1]%MOD +
                     (str[i]%MOD * power[j-1]%MOD)%MOD)%MOD;
    return;
}

bool query(int l,int r)
{

    int L = l;
    int R = r;

    unsigned long long hash_LR =
        ((prefix[R+1]-prefix[L]+MOD)%MOD *
         findMMI(power[L])%MOD)%MOD;


    unsigned long long reverse_hash_LR =
        ((suffix[n-L]-suffix[n-R-1]+MOD)%MOD *
         findMMI(power[n-R-1])%MOD)%MOD;

    if (hash_LR == reverse_hash_LR )
    {
        return 1;

    }

    return 0;
}

void computePowers(unsigned long long int power[], int n)
{
    power[0] = 1;
    for(int i=1; i<=n; i++)
        power[i] = (power[i-1]%MOD * p%MOD)%MOD;
    return;
}

int main()
{




    return (0);
}

