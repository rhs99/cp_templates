#include<bits/stdc++.h>
using namespace std;

const int MX = 100001;
int a[MX],node[MX];
int n;

int getPar(int index)
{
    return index - (index & (-index));
}

int getNext(int index)
{
    return index+(index & (-index));
}

void updateBit(int index,int val)
{
    while(index<=n)
    {
        node[index] += val;
        index = getNext(index);
    }
}

void createBit()
{
    for(int i=1; i<=n; i++)
    {
        updateBit(i,a[i-1]);
    }
}


int getSum(int index)
{
    index++;
    int sum=0;
    while(index>0)
    {
        sum+=node[index];
        index = getPar(index);
    }
    return sum;
}


int main()
{
    int t,tc,i,q,ty,j;
    scanf("%d",&t);
    for(tc=1; tc<=t; tc++)
    {
        scanf("%d%d",&n,&q);
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            node[i]=0;
        }
        node[i]=0;
        createBit();
        printf("Case %d:\n",tc);
        while(q--)
        {
            scanf("%d",&ty);
            if(ty==1)
            {
                scanf("%d",&i);
                printf("%d\n",a[i]);
                updateBit(i+1,-a[i]);
                a[i]=0;
            }
            else if(ty==2)
            {
                scanf("%d%d",&i,&j);
                updateBit(i+1,j);
                a[i]+=j;
            }
            else
            {
                scanf("%d%d",&i,&j);
                printf("%d\n",getSum(j)-getSum(i-1));
            }
        }

    }

return 0;
}

