#include <iostream>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n,j,s = 0;
		cin >> n;
		int m[n],f[n],a[11] = {0},b[11] = {0};
		for (int i = 0; i < n; ++i){
			cin >> m[i];
			a[m[i]] += 1;
		}
		for (int i = 0; i < n; ++i){
			cin >> f[i];
			b[f[i]] += 1;
		}
		int i=10,j=10;
		while(i > 0 && j > 0)
		{
			while(a[i]==0)
				i--;
			while(b[j]==0)
				j--;
			if(a[i]==b[j]){
				s += i*j*a[i];
				i--;
				j--;
			}
			else if(a[i] > b[j])
			{
				s += i*j*b[j];
				a[i] -= b[j];
				j--;	
			}
			else
			{
				s += i*j*a[i];
				b[j] -= a[i];
				i--;
			}

			cout << s << "\n";
		}
		
	}
   	return 0;
}
