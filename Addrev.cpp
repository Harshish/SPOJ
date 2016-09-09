#include <iostream>

using namespace std;

int digRev(int num)
{
	int temp = num;
	int dig = 0;
	while(temp!=0)
	{
		dig = dig * 10 + temp % 10;
		temp /= 10;
	}
	return dig;
}

int main()
{
	int tca,b;
	cin >> tc;
	for (int i = 0; i < tc; ++i)
	{
		cin >> a >> b;
		a = digRev(a);
		b = digRev(b);
		cout << digRev(a+b) << "\n";
	}
    return 0;
}
