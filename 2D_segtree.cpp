#include<bits/stdc++.h>
using namespace std;
#define MX 100

int n;
int mat[MX][MX];
int iSegTree[MX][4*MX];//for each row
int fSegTree[4*MX][4*MX];//merging row segment trees

void iSegTreeSet(int node,int b,int e,int rowNo)//making segment trees for row : rowNo
{
    if(b==e)
    {
        iSegTree[rowNo][node] = mat[rowNo][b];
        return;
    }

    int mid = (b+e)>>1;
    int left = node<<1,right = left+1;

    iSegTreeSet(left,b,mid,rowNo);
    iSegTreeSet(right,mid+1,e,rowNo);

    iSegTree[rowNo][node] = iSegTree[rowNo][left]+iSegTree[rowNo][right];

}

void fSegTreeSet(int node,int b,int e)//node contains the merged segment tree from row b to e
{
    if(b==e)
    {
        for(int i=1; i<4*MX; i++)
        {
            fSegTree[node][i] = iSegTree[b][i];
        }
        return ;
    }

    int mid = (b+e)>>1;
    int left = node<<1,right = left+1;

    fSegTreeSet(left,b,mid);
    fSegTreeSet(right,mid+1,e);

    for(int i=1; i<4*MX; i++)
    {
        fSegTree[node][i] = fSegTree[left][i]+fSegTree[right][i];
    }

}

int fQuery(int node,int b,int e,int l,int r,int Id)
{
    if(r<b||l>e)
        return 0;

    if(b>=l&&e<=r)
    {
        return fSegTree[Id][node];
    }

    int mid = (b+e)>>1;
    int left = node<<1,right = left+1;

    return fQuery(left,b,mid,l,r,Id) + fQuery(right,mid+1,e,l,r,Id);
}

int query(int node,int b,int e,int x1,int y1,int x2,int y2)
{
    if(x2<b||x1>e)
        return 0;

    if(b>=x1&&e<=x2)
    {
        return fQuery(1,1,MX-1,y1,y2,node);
    }

    int mid = (b+e)>>1;
    int left = node<<1,right = left+1;

    return query(left,b,mid,x1,y1,x2,y2) + query(right,mid+1,e,x1,y1,x2,y2);

}

void fUpdate(int node,int b,int e,int idx,int val,int Id)
{
    if(b==e)
    {
        fSegTree[Id][node] = val;
        return;
    }

    int mid = (b+e)>>1;
    int left = node<<1,right = left+1;

    if(idx<=mid)
    {
        fUpdate(left,b,mid,idx,val,Id);
    }
    else
    {
       fUpdate(right,mid+1,e,idx,val,Id);
    }

    fSegTree[Id][node] = fSegTree[Id][left]+fSegTree[Id][right];
}

void update(int node,int b,int e,int x,int y,int val)
{
    if(b==e)
    {
        fUpdate(1,1,MX-1,y,val,node);
        return ;
    }

    int mid = (b+e)>>1;
    int left = node<<1,right = left+1;

    if(x<=mid)
    {
        update(left,b,mid,x,y,val);
    }
    else
    {
       update(right,mid+1,e,x,y,val);
    }

    for(int i=1;i<4*MX;i++)
    {
        fSegTree[node][i] = fSegTree[left][i] + fSegTree[right][i];
    }


}


int main()
{
    cin>>n;

    int i,j;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin>>mat[i][j];
        }
    }

    for(i=1; i<=n; i++)
    {
        iSegTreeSet(1,1,MX-1,i);
    }

    fSegTreeSet(1,1,MX-1);

    cout<<query(1,1,MX-1,2,2,3,3)<<endl;

    update(1,1,MX-1,2,2,7);

    cout<<query(1,1,MX-1,2,2,3,3)<<endl;



    return 0;
}

/*
4
1 2 3 4
5 6 7 8
1 7 5 9
3 0 6 2
*/






