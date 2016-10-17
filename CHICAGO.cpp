#include <bits/stdc++.h>

using namespace std;

double maxl(double x,double y)
{
	if(x < y)
		return y;
	else
		return x;
}

int main()
{
	while(1)
	{
		int n,m,a,b,p;
		cin >> n;
		if(n==0)
			break; 
		cin >> m;
		double dmat[n][n];
		memset(dmat,0,n*n*sizeof(dmat[0][0]));

		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> p;
			dmat[a-1][b-1] = (double)p/100;
			dmat[b-1][a-1] = (double)p/100;
		}
		int *v = new int[n];
		double ans = 1,max;
		int index = 0;
		/*
		Alternate Solution : TLE
		do
		{
			max = 0;
			v[index] = 1;
			int i = index;
			for (int j = 0; j < n; ++j)
			{
				if(dmat[i][j] > max && v[j]==0)
				{
					max = dmat[i][j];
					index = j;
				}
			}

			ans = (double) ans*max;
		}while(index!=n-1);
		ans *= 100;
		printf("%6f percent\n",ans);*/

		for (int k = 0; k < n; ++k)
		{
			for (int i = 0; i < n; ++i)
			{
				if(i==k)
					continue;
				for (int j = 0; j < n; ++j)
					if(i!=j)
						dmat[i][j] = maxl(dmat[i][j],dmat[i][k]*dmat[k][j]);
			}
		}
		printf("%6f percent\n",dmat[0][n-1]*100);
	}
	return 0;
}                                            