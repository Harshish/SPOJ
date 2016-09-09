#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		float s = 0;
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i)
			s += (float)1/i;
		s *= n;
		printf("%.2f\n",s);
	}
	return 0;
}