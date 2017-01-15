#include <bits/stdc++.h>

using namespace std;

vector<int> a[100];

bool chkDiff(vector<int> &v)
{
	for (int i = 0; i < v.size(); ++i)
		if(v[0]!=v[i])
			return false;
	return true;
}

int main()
{
	int tc,n,c;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		scanf("%d",&c);
		int var;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&var);
			a[0].push_back(var);
		}
		bool flag = true;
		int diff,size = 0;
		while(flag)
		{
			if(chkDiff(a[size]))
				flag = false;
			else
			{
				size++;
				for (int j = 0; j < a[size-1].size()-1; ++j)
				{
					diff = a[size-1][j+1] - a[size-1][j];
					a[size].push_back(diff);
				}
			}
		}

		int index = a[size].size() - 1;
		for (int j = 0; j < c; ++j)
			a[size].push_back(a[size][index]);

		for (int i = size-1; i >= 0; i--)
		{
			index = a[i].size() - 1;	
			for (int j = 0; j < c; ++j)
			{
				a[i].push_back(a[i][index] + a[i+1][index]);
				index++;	
			}
		}

		for (int i = n; i < n+c; ++i)
			cout << a[0][i] << " ";
		cout << "\n";

		for (int i = 0; i <= size; ++i)
			a[i].clear();
	}
	return 0;
}