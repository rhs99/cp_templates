#include <bits/stdc++.h>
using namespace std;
#define mx 100001
int a[mx],tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return ;
    }
    int left,right,mid;
    left = node<<1;
    right = left+1;
    mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(e<i||b>j)
        return 0;
    if(b>=i&&e<=j)
    {
        return tree[node];
    }
    int left,right,mid,p1,p2;
    left = node<<1;
    right = left+1;
    mid = (b+e)/2;
    p1 = query(left,b,mid,i,j);
    p2 = query(right,mid+1,e,i,j);
    return p1+p2;
}

void update(int node,int b,int e,int i,int NewValue)
{
    if(e<i||b>i)
        return;
    if(b>=i&&e<=i)
    {
        tree[node] = NewValue;
        return ;
    }
    int left,right,mid,p1,p2;
    left = node<<1;
    right = left+1;
    mid = (b+e)/2;
    update(left,b,mid,i,NewValue);
    update(right,mid+1,e,i,NewValue);
    tree[node] = tree[left]+tree[right];
}

int main()
{
    return 0;
}
