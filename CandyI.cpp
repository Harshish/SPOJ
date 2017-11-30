#include <iostream>
#include <vector>

using namespace std;

int main()
{
	while(true)
	{
		int n;
		cin >> n;
		if(n==-1)
			break;
		int chk,val;
		long long count = 0,d;
		vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			cin >> val;
			count += val;
			v.push_back(val);
		}
		d = count/v.size();

		if(count % v.size()!=0)
			chk = 1;
		else
			chk = 0;

		if(chk)
			cout << "-1" << "\n";
		else
		{
			int i = v.size();
			count = 0;
			i--;
			while(v[i]>d)
			{
				count += v[i] - d;
				i--;
			}
			cout << count << "\n";
		}
	}
   return 0;
}
