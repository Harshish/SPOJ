#include <iostream>

using namespace std;

long long int maxCoins(long long int a,long long int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int main()
{
	int tc,k = 1;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		long long int a[n],d[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		d[0] = a[0];
		d[1] = max(d[0],a[1]);
        if(n==0)
        	cout << "Case " << k << ": 0" << "\n";
        else if(n==1)
        	cout << "Case " << k << ": " << d[0] << "\n";
        else if(n==2)
        	cout << "Case " << k << ": " << d[1] << "\n";
        else
        {
        	for (int i = 2; i < n; i++)
        		d[i] = max(d[i-1],a[i]+d[i-2]);
        	cout << "Case " << k << ": " << d[n-1] << "\n";
        }
        k++;
	}
   	return 0;
}
