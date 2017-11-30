#include <bits/stdc++.h>

using namespace std;

int allmask;

int assign(vector<int> v[],int mask,int n,int job,int **dp)
{
	if(mask==allmask) return 1;

	if(job > n) return 0;
	if(dp[mask][job]!=-1) return dp[mask][job];

	int sum = assign(v,mask,n,job + 1,dp);

	for (int i = 0; i < v[job].size(); ++i)
	{
		if (mask & (1<<v[job][i]))
			continue;
		else
			sum += assign(v,mask | (1<<v[job][i]),n,job + 1,dp);
	}
	dp[mask][job] = sum;
	return sum;
} 

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n,var;
		//sum = 0;
		cin >> n;
		vector<int> v[n+1];
		for(int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> var;
				if (var)
					v[j+1].push_back(i);
			}
		}
		allmask = (1<<n) - 1;
		int t = pow(2,n);
		int **dp = new int*[t];
		for (int i = 0; i < t; ++i)
		{
			dp[i] = new int[n+1];
			for (int j = 0; j <= n; ++j)
				dp[i][j] = -1;
		}
		cout << assign(v,0,n,1,dp) << "\n"; 
	}
	return 0;
}                                            