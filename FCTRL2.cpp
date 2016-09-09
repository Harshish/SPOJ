#include <iostream>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		if(n==0)
			cout << "1" << "\n";
		else
		{
			int a[200] = {0},size = 0,k;
			k = n;
			while(n!=0)
			{
				a[size] = n%10;
				n /= 10;
				size++;
			}
			int c,x;
			for (int i = 2; i < k; ++i)
			{
				c = 0;
				for (int j = 0; j < size; ++j)
				{
					x = a[j]*i + c;
					a[j] = x%10;
					c  = x/10;
				}
				while(c!=0)
				{
					a[size] = c%10;
					size++;
					c /= 10;
				}

			}
			for (int i = size-1; i >= 0; i--)
				cout << a[i];
			cout << "\n";
		}
	}
   	return 0;
}
