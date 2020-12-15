#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
using namespace std;


int l,r,Row,Col,mat[300][300];

void rotation(int l, int m, int Row, int Col)
{
       int si,sj,i,j,t,f;
       si = l;
       sj = m;
      
       t = mat[l][m];
      //top row
       for(i=l+1;i<=Row;i++)
       {
              f = mat[i][m];
              mat[i][m] = t;
              t = f;
       }
       l++;
       //right col
       for(i=m+1;i<=Col;i++)
       {
              f = mat[Row][i];
              mat[Row][i] = t;
              t = f;
       }
       m++;
       //left col
       if(l-1 < Row)
       {
              for(i=Row-1;i>=l-1;i--)
              {
                     f = mat[i][Col];
                     mat[i][Col] = t;
                     t = f;
              }
       }
       Col--;
       //down row
       if(m-1 < Col)
       {
              for(i=Col;i>=m;i--)
              {
                     f = mat[l-1][i];
                     mat[l-1][i] = t;
                     t = f;
              }                         
       }
       Row--;
       mat[si][sj] = t;
       return;
}


int main()
{
       int n,m,k,i,j;
       scanf("%d%d%d",&n,&m,&k);
       int f,K;
       for(i=0;i<n;i++)
       {
              for(j=0;j<m;j++)
              {
                     scanf("%d",&mat[i][j]);
              }
       }
       l = 0;
       r = 0;
       Row = n-1;
       Col = m-1;
       while(l < Row && r < Col)
       {
              int rot = 2*(Row-l)+2*(Col-r);
              f = k%rot;
              for(i=1;i<=f;i++)
              {
                     rotation(l,r,Row,Col);
              }
              l++;
              r++;
              Row--;
              Col--;
       }     
       for(i=0;i<n;i++)
       {
              for(j=0;j<m;j++)
              {
                     printf("%d ",mat[i][j]);
              }
              printf("\n");
       }
    return 0;
}
