#include <bits/stdc++.h>
#define MAX 111

using namespace std;

int main()
{

	int n,e,t,m,a,b,p;
	cin >> n >> e >> t >> m;
	int dmat[MAX][MAX];
	memset(dmat,32,sizeof(dmat));

	dmat[e][e] = 0;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> p;
		dmat[a][b] = p;
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dmat[i][j] = min(dmat[i][j],dmat[i][k]+dmat[k][j]);

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if(dmat[i][e] <= t)
			ans++;
	printf("%d\n",ans);
	return 0;
}                                            