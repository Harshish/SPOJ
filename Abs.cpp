#include <iostream>

using namespace std;

int main()
{
	int tc,n;
	long long int a[10000];
	long long int sum[10000] = {0};
	cin >> tc;
	for (int j = 0; j < tc; ++j)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int k = n-1; k >= 0; k--)
            sum[j] += a[k] * k - (n-k-1) * a[k];
	}
	for (int l = 0; l < tc; ++l)
		cout << sum[l] << "\n";
    return 0;
}
