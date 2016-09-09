#include <iostream>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		long long n,s = 0;
		cin >> n;
		for (int i = 5; i <= n; i *= 5)
			s += n/i;
		cout << s << "\n";
	}
   	return 0;
}
