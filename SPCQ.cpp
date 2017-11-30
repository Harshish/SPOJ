#include <iostream>

using namespace std;

int digSum(unsigned long long n)
{
	int digS = 0;
	while(n!=0)
	{
		digS += n%10;
		n /= 10;
	}
	return digS;
}

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		unsigned long long n;
		cin >> n;
		while(n%digSum(n)!=0)
			n++;
		cout << n << "\n";
	}
   	return 0;
}
