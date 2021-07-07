#include<bits/stdc++.h>
using namespace std;
#define MX 100001

int tree[MX];
int lazy[MX];

int arr[] = {0,1, 3, 5, 7, 9, 11};
int n = 6;


void update(int node, int b, int e, int l,int r, int val)
{
    if (lazy[node] != 0)
    {
        tree[node] += (e-b+1)*lazy[node];
        if (b != e)
        {
            lazy[node*2]   += lazy[node];
            lazy[node*2 + 1]   += lazy[node];
        }
        lazy[node] = 0;
    }
    if (b>e || b>r || e<l)
        return ;
    if (b>=l && e<=r)
    {
        tree[node] += (e-b+1)*val;
        if (b != e)
        {
            lazy[node*2]   += val;
            lazy[node*2+1]   += val;
        }
        return;
    }
    int m = (b+e)/2;
    update(node*2, b, m, l, r, val);
    update(node*2+1, m+1, e, l, r, val);

    tree[node] = tree[node*2] + tree[node*2+1];
}




int query(int node,int b, int e, int l, int r)
{
    if (lazy[node] != 0)
    {
        tree[node] += (e-b+1)*lazy[node];
        if (b != e)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (b>e || b>r || e<l)
        return 0;

    if (b>=l && e<=r)
        return tree[node];
    int m = (b + e)/2;
    return query(2*node,b, m, l, r) + query(2*node+1,m+1, e, l, r);
}

void init(int node,int b, int e)
{

    if (b > e)
        return ;

    if (b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int m = (b+e)>>1;
    int left = node<<1,right=left+1;


    init(left,b,m);
    init(right,m+1,e);

    tree[node] = tree[left] + tree[right];
}




int main()
{



    init(1,1,n);
    int l=2,r=4,val=10;
    cout<<query(1,1,n,l,r)<<endl;
    update(1, 1, n, l, r, val);
    cout<<query(1,1,n,l,r)<<endl;

    return 0;
}

