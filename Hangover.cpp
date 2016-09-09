#include <iostream>

using namespace std;

int main()
{
	float n = 1.00;
	cin >> n;
	while(n!=0)
	{
		int i = 2;
		float s = 0.00;
		while(s<n)
		{
			s += (float)1/i;
			i++;
			cout << "sum= " << s << "\n";
		}
		cout << i-1 << " card(s)" << "\n";
		cin >> n;
	}

   	return 0;
}
