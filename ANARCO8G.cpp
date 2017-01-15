#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,tc = 1;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		int mat[n][n],initalCost = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%d",&mat[i][j]);
				initalCost += mat[i][j];
			}
		}

		int newCost = 0;
		for (int i = 0; i < n; ++i)
		{
			int out = 0,in = 0;
			for (int j = 0; j < n; ++j)
				out += mat[i][j];
			for (int j = 0; j < n; ++j)
				in += mat[j][i];
			int a = out - in;
			if(a>=0)
				newCost += a;
		}
		printf("%d. %d %d\n",tc,initalCost,newCost);
		tc++;
	}
	return 0;
}