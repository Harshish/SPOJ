#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n1,n2;
		cin >> n1;
		int *a1 = new int[n1];
		for (int i = 0; i < n1; ++i)
			cin >> a1[i];
		cin >> n2;
		int *a2 = new int[n2];
		for (int i = 0; i < n2; ++i)
			cin >> a2[i];
		int j = 0;
		int min = 10000000;
		for (int j = 0; j < n2; ++j)
		{
			for (int i = 0; i < n1; ++i)
			{
				int var = a2[j] -a1[i];
				if(var < 0)
					var *= -1;
				if(var < min)
					min = var;
			}
		}
		cout << min << "\n";
	}
	return 0;
}                                            