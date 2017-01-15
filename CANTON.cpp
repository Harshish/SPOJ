#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int term;
		cin >> term;
		int temp = term;
		int i = 1,j = 1;
		bool flag = true;
		while(flag)
		{

			while(i>=1 && flag)
			{
				term--;
				if(term==0)
					flag = false;
				if(flag)
				{
					i--;
					j++;
				}
			}
			if(flag)
				i++;


			while(j>=1 && flag)
			{
				term--;
				if(term==0)
					flag = false;
				if(flag)
				{
					j--;
					i++;
				}
			}
			if(flag)
				j++;
		}
		cout << "TERM " << temp << " IS " << i << "/" << j << "\n";
	}
	return 0;
}