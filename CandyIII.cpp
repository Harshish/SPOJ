#include <iostream>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		cout << endl;
		unsigned long long a[n],sum = 0,n,i;
		cin >> n;
		
		for (i = 0; i < n; ++i)
		{
			cin >> a[i];
			sum = (sum+a[i]) % n;
		}
		if(sum)
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";	
	}
   	return 0;
}
