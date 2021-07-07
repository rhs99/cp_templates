#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int n = 11, A[] = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4};
int L[MAX_N], L_id[MAX_N], P[MAX_N]= {-1};
int lis = 0, lis_end = 0;

void print(int e)
{
    if(P[e]==-1)
    {
        cout<<A[e]<<" ";
        return ;
    }
    print(P[e]);
    cout<<A[e]<<" ";
}

int main()
{
    memset(P,-1,sizeof(P));
    for (int i = 0; i < n; ++i)
    {
        int pos = lower_bound(L, L + lis, A[i]) - L;
        L[pos] = A[i];
        L_id[pos] = i;
        P[i] = pos ? L_id[pos - 1] : -1;
        if (pos + 1 > lis)
        {
            lis = pos + 1;
            lis_end = i;
        }
    }
    printf("Final LIS is of length %d: %d \n", lis,lis_end);
    print(lis_end);
    return 0;
}


