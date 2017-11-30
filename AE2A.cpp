#include <bits/stdc++.h>

using namespace std;

double dp[560][3400];

int main()
{
	int tc;
	memset(dp,0,sizeof(dp));
	for (int i = 1; i < 7; ++i)
			dp[1][i] = (double)1.0/6.0;
	for (int i = 2; i <= 550; ++i)
	{
		for (int j = 1; j <= 3400; ++j)
		{
			for (int k = 1; k < 7; ++k)
				if(j-k > 0)
					dp[i][j] += dp[i-1][j-k]/6.0;
		}
	}
	scanf("%d",&tc);
	while(tc--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(n > 560 || k > 3400)
		{
			printf("0\n");
			continue;
		}
		else
		{
			long long int ans = dp[n][k] * 100;
			printf("%lld\n",ans);
		}
	}
	return 0;
}