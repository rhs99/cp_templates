#include<bits/stdc++.h>
using namespace std;
long long mat[21][21][21];
long long temp[21];
int main()
{

    int t;
    int a,b,c,i,j,k,l,m;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        memset(mat,0,sizeof(mat));
        long long sum=LONG_LONG_MIN;
        cin>>a>>b>>c;
        for(i=0; i<a; i++)
        {
            for(j=0; j<b; j++)
            {
                for(k=0; k<c; k++)
                {
                    cin>>mat[i][j][k];
                    if(j>0)
                        mat[i][j][k]+=mat[i][j-1][k];
                    if(k>0)
                        mat[i][j][k]+=mat[i][j][k-1];
                    if(j>0&&k>0)
                        mat[i][j][k]-=mat[i][j-1][k-1];
                }
            }
        }

        //from here I have generated all possible 2D matrix
        //then I have calculated the sums of all 2d matrix of same size for the 3rd dimension and stored them in temp array
        // then run a kadane to that temp

        for(i=0; i<b; i++)
        {
            for(j=0; j<c; j++)
            {
                for(k=i; k<b; k++)
                {
                    for(l=j; l<c; l++)
                    {
                        memset(temp,0,sizeof(temp));
                        for(m=0; m<a; m++)
                        {
                            long long s=mat[m][k][l];
                            if(i>0)
                                s-=mat[m][i-1][l];
                            if(j>0)
                                s-=mat[m][k][j-1];
                            if(i>0&&j>0)
                                s+=mat[m][i-1][j-1];
                            temp[m]=s;

                        }

                        long long s=0;
                        for(m=0; m<a; m++)
                        {
                            s+=temp[m];
                            sum=max(sum,s);
                            if(s<0)
                                s=0;
                        }


                    }
                }
            }
        }
        if(tc>1)
            cout<<endl;
        cout<<sum<<endl;
    }
    return 0;
}
