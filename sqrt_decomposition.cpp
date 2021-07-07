#include<bits/stdc++.h>
using namespace std;
#define MX 100001

int n;
int a[MX];
int block[(int)sqrt(MX+0.0)];
int blk_sz;

void update(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val - a[idx];
    a[idx] = val;
}

int query(int l, int r)
{
    int sum = 0;
    while (l<r and l%blk_sz!=0 and l!=0)
    {
        sum += a[l];
        l++;
    }
    while (l+blk_sz <= r)
    {
        sum += block[l/blk_sz];
        l += blk_sz;
    }
    while (l<=r)
    {
        sum += a[l];
        l++;
    }

    return sum;
}

void preprocess()
{
    int blk_idx = -1;

    blk_sz = sqrt(n+0.0);

    for (int i=0; i<n; i++)
    {
        if (i%blk_sz == 0)
        {
            blk_idx++;
        }
        block[blk_idx] += a[i];
    }
}

int main()
{


    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    preprocess();

    return 0;
}
