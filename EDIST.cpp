#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        int m = s1.length();
        int n = s2.length();
        int dp[m+1][n+1];
        for(int i = 0; i < m+1 ; i++)
        {
            for(int j = 0; j < n+1 ; j++)
            {
                if(i==0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
                else
                {
                    if(s1[i-1]==s2[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
                }
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}