#include<bits/stdc++.h>
using namespace std;

int allmask;

long long assign(int **mat,long long *dp,int mask,int n)
{
    int index = __builtin_popcount(mask);
    if(index==n && mask==allmask)
        return 1;
    if(dp[mask]!=-1)
        return dp[mask];
    long long cnt = 0;
    for(int j = 0; j < n; j++)
    {
        if(!mat[index][j] || (mask & (1<<j)))
            continue;
        cnt += assign(mat,dp,mask | (1<<j),n);
    }
    dp[mask] = cnt;
    return dp[mask];
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 1<<21;
    long long *dp = new long long[N];
    int tc;
    cin >> tc;   
    while(tc--)
    {
        int n;
        cin >> n;
        int **mat = new int*[n];
        for(int i = 0; i < n; i++)
        {
            mat[i] = new int[n];
            for(int j = 0; j < n; j++)
                cin >> mat[i][j];
        }
        memset(dp,-1,N*sizeof(dp[0]));
        allmask = pow(2,n) - 1;
        cout << assign(mat,dp,0,n) << "\n";
    }
    return 0;
}
