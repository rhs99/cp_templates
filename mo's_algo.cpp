#include<bits/stdc++.h>
using namespace std;
#define MX 300001
struct query
{
    int l, r, id;
} q[MX];

int k = sqrt(MX);
int a[MX];
bool cmp(query &a, query &b)
{
    int block_a = a.l / k, block_b = b.l / k;
    if(block_a == block_b) return a.r < b.r;
    return block_a < block_b;
}

int l = 0, r = -1, sum = 0, ans[MX];

void add(int x)
{
    sum += a[x];
}
void remove(int x)
{
    sum -= a[x];
}

int main()
{
    int Q;
    for(int i = 0; i < Q; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q, q+Q, cmp);
    for(int i = 0; i < Q; i++)
    {
        while(l > q[i].l) add(--l);
        while(r < q[i].r) add(++r);
        while(l < q[i].l) remove(l++);
        while(r > q[i].r) remove(r--);
        ans[q[i].id] = sum;
    }
}
