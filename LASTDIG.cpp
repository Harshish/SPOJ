#include <iostream>

using namespace std;

void modexp(int a,long long b)
{
	long long d = 1;
	while(b)
	{
		if(b%2)
			d = (d*a)%10;
		b /= 2;
		a = (a*a)%10;
	}
	cout << d << "\n";
}

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int a;
		long long b;
		cin >> a >> b;
		if(b==0)
			cout << "1" << "\n";
		else
            modexp(a,b);
	}
   	return 0;
}
