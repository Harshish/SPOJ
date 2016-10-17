#include <bits/stdc++.h>

using namespace std;

int knapsack(int w[],int val[],int W,int n)
{
	int k[n+1][W+1];
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= W; ++j)
		{
			if(i==0 ||  j==0)
				k[i][j] = 0;
			else if(w[i-1] <= j)
				k[i][j] = max(val[i-1] + k[i-1][j-w[i-1]],k[i-1][j]);
			else
				k[i][j] = k[i-1][j];
		}
	}
	return k[n][W];
}

int main()
{
	int s,n;
	cin >> s >> n;
	int *w = new int[n];
	int *val = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> w[i] >> val[i];
	cout << knapsack(w,val,s,n) << "\n";
}                                            