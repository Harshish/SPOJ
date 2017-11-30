#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float n;
	float k;
	while(1)
	{
		cin >> n;
		if(n==-1)
			break;
		if(n%2)
        {
        	for (int i = 1; i < sqrt(n); ++i)
        	{
        	   	if(n==3*(i-1)*i+1)
        	   	{
        	   		cout << "Y" << "\n";
        	   		break;
        	   	}
        	}   
        }
        else
            cout << "N" << "\n";
	}
    return 0;
}
