#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n,k = 0;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a,a+n);
		for (int i = 0; i < n/2 - 1; ++i)
		{
			if (a[i]!=0)
			{
				int temp = a[i]*2;
				for (int j = n-1; j>=0; j--)
				{
					if(a[j]==temp)
					{
						a[j] = 0;
						k++;
						j = -1;
					}
				}
			}
		}
		cout << k << "\n";
	}
   	return 0;
}
