#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<iomanip>
#include<queue>
#include<map>
#include<list>
#include<stack>
#define fl(i,s,n) for(i=s;i<n;i++)
#define flr(i,s,n) for(i=s;i>n;i--)
#define ls(i,s) for(i=0;s[i]!='\0';i++)
#define gi(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define checkline(x) while(x!='\0' && x!='\n')
#define pt(s) printf(s)
#define PI acos(-1)
#define in(i,j,k) ((j<=i) && (i<k))
#define ull unsigned long long int
#define lli long  long int
#define ld long double
#define sd(x) scanf("%d",&x)
#define sl(x) scanf("%ld",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define r0 return 0
#define mod 1000000007
#define f_in freopen("input.txt","r",stdin)
#define f_out freopen("output.txt","w",stdout)
using namespace std;
int **mat1 , **mat2;
int d1(int **mat ,int x1,int y1 ,int x2 ,int y2)
{
    return mat[x2][y2]-mat[x1-1][y1-1];
}
int d2(int **mat ,int x1,int y1 ,int x2 ,int y2)
{
    return mat[x2][y2]-mat[x1-1][y1+1];
}
void csumDiag1(int **mat1 , int ** mat2)
{
    int i,j;
    fl(i,1,1800)
        fl(j,1,1800)
            mat1[i][j] += mat1[i-1][j-1];
    fl(i,1,1800)
        fl(j,0,1799)
            mat2[i][j] += mat2[i-1][j+1];
}
int noH(int **mat1 ,int **mat2 ,int d,int x,int y)
{
    int ans = 0;
    ans += d1(mat1,x-d,y,x,y+d);
    ans += d1(mat1,x,y-d,x+d,y);
    ans += d2(mat2,x-d+1,y-1,x-1,y-d+1);
    ans += d2(mat2,x+1,y+d-1,x+d-1,y+1);
    return ans;
}
int prog() {
    int i, j, k, x, y, z, n, m ,d;
    char ch;
    fl(i, 0, 1800)
        fl(j, 0, 1800)
            mat1[i][j] = mat2[i][j] = 0;
    sd2(n, m);
    long *dp = new long [n+m];
    fl(i,0,n+m)
        dp[i] = 0;
    getchar();
    fl(i, 0, n)
    {
        fl(j, 0, m)
        {
            ch = getchar();
            mat1[i + 600][j + 600] = mat2[i + 600][j + 600] = (ch - 48);
        }
        getchar();
    }
    csumDiag1(mat1,mat2);
    fl(i,600,600+n)
        fl(j,600,600+m)
        {
            if(mat1[i][j]-mat1[i-1][j-1])
            {
                fl(d,1,n+m-1)
                    dp[d]+=noH(mat1,mat2,d,i,j);
            }
        }
        fl(i,1,n+m-1)
            cout<<(dp[i]>>1)<<' ';

}
int main() {
    //f_in;
    int i, t;
    mat1 = new int *[1800];
    mat2 = new int *[1800];
    fl(i, 0, 1800)
    {
        mat1[i] = new int[1800];
        mat2[i] = new int[1800];
    }
    sd(t);
    while(t--)
        prog();
    r0;
}