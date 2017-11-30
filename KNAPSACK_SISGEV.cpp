#include <bits/stdc++.h>

using namespace std;

void subsets(int **mat,int t,int n)
{
	for (int i = 0; i < t; ++i)
		for (int j = 0; j < n; ++j)
			if(i & (1<<j))
				mat[i][j] = 1;
}

int main()
{
	int s,n;
	cin >> s >> n;
	int *w = new int[n];
	int *val = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> w[i] >> val[i];
	int t = pow(2,n);
	int **mat = new int*[t]();
	for (int i = 0; i < t; ++i)
		mat[i] = new int[n+1]();
	subsets(mat,t,n);
	for (int i = 0; i < t; ++i)
	{
		int v = 0,wt = 0;
		for (int j = 0; j < n; ++j)
		{
			if(mat[i][j])
			{
				v += val[j];
				wt += w[j];
			}
		}
		if(wt <= s)
			mat[i][n] = v;
		else
			mat[i][n] = -1;
	}

	int max = 0;
	for (int i = 0; i < t; ++i)
		if(mat[i][n] > max)
			max = mat[i][n];

	cout << max << "\n";
}                                            