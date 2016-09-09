#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		cout << "\n";
		int n,m,val,i,j;
		cin >> n >> m;
		vector<int> a,b;
		for (i = 0; i < n; ++i)
		{
			cin >> val;
			a.push_back(val);
		}
		for (j = 0; j < m; ++j)
		{
			cin >> val;
			b.push_back(val);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		i = 0;
		j = 0;
		while(i!=a.size() && j!=b.size())
		{
			if(a[i] > b[j])
				j++;
			else if(a[i] < b[j])
				i++;
			else
				j++;
		}
		if(i!=a.size())
			cout << "Godzilla" << "\n";
		else if(j!=b.size())
			cout << "MechaGodzilla" << "\n";
		else
			cout << "uncertain" << "\n";
	}
    return 0;
}
