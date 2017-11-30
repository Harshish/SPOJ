#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc,n;
	cin >> tc;
	while(tc--)
	{
		cin >> n;
		long long x = pow(2,n-1);
		long long val = x/2;
		val = val * (n-1);
		val += x;
		cout << x << " " << val << "\n";
	}
	return 0;
}
