#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10007
struct matrix
{
    int a[3][3];
    matrix operator*(matrix rhs)
    {
        matrix temp;
        int i,j,k,s;
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                s=0;
                for(k=0; k<3; k++)
                {
                    s=(s+(a[i][k]*rhs.a[k][j]))%mod;
                }
                temp.a[i][j]=s;
            }
        }
        return temp;
    }

};


matrix unit()
{
    matrix temp;
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(i==j)
                temp.a[i][j]=1;
            else
                temp.a[i][j]=0;

        }
    }
    return temp;
}
matrix init()
{
    matrix temp;
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            temp.a[i][j]=0;

        }
    }
    return temp;
}


matrix matrix_power(matrix a,int x)
{

    matrix result=unit();
    while(x>0)
    {
        if(x%2)
            result=result*a;
        a=a*a;
        x=x/2;
    }

    return result;
}



int main()
{

    ios::sync_with_stdio(false);
    int t,tc;
    scanf("%d",&t);
    matrix base=init(),m=init();
    for(tc=1; tc<=t; tc++)
    {
        ll n;
        scanf("%lld",&n);
        base.a[0][0]=1,base.a[0][1]=1,base.a[0][2]=2;
        m.a[0][2]=1,m.a[1][0]=1,m.a[2][1]=1,m.a[2][2]=2;
        if(n>2)
        {
            matrix ans;
            ans=base*(matrix_power(m,n-3+1));
            printf("Case %d: %d\n",tc,ans.a[0][2]);
        }
        else
        {
            printf("Case %d: %d\n",tc,base.a[0][n]);
        }

    }
    return 0;
}



















