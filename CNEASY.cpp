#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		string s;
		double a[n],x;
		for (int i = 0; i < n; ++i)
			cin >> s >> a[i];
		sort(a,a+n);
		double la = a[n-1] - a[0];
		for (int i = 1; i < n; ++i)
		{
			x = 360.0 - a[i] + a[i-1];
			if(x < la)
				la = x;
		}	
		la *= 12.0;
		int ans = ceil(la);
		cout << ans << "\n";
	}
	return 0;
}