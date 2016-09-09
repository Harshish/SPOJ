#include <iostream>

using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	while(1)
	{
		if(a==0 && b==0 && c==0)
			break;
		if(b-a == c-b)
			cout << "AP " << c + b - a << "\n";
		else
			cout << "GP " << c * (b/a) << "\n";
		cin >> a >> b >> c;
	}
    return 0;
}
