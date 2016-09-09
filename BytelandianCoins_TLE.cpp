#include <iostream>

using namespace std;

long maxCoins(long long n)
{
	if(n<=4)
		return n;
	long long k = maxCoins(n/2) + maxCoins (n/3) + maxCoins(n/4);
	if(k > n)
		return k;
	else
		return n;
}

int main()
{
	short int tc;
	cin >> tc;
	while(tc--)
	{
		long long n;
		cin >> n;
		cout << maxCoins(n) << "\n";
	}
   	return 0;
}
