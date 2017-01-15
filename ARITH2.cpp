#include <bits/stdc++.h>

using namespace std;

vector<long long int> numq;
vector<char> opq;

long long int calculate(long long int a,int op,int b)
{
	switch(op)
	{
		case '+' : return a + b;
		case '-' : return a - b;
		case '*' : return a * b;
		case '/' : return a / b;
	}
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		cout << "\n";
		int i = 1;
		bool flag = true;
		while(flag)
		{
			int a;
			char b;
			if(i%2)
			{
				cin >> a;
				numq.push_back(a);
			}
			else
			{
				cin >> b;
				if(b=='+' || b== '-' || b== '*' || b== '/')
					opq.push_back(b);
				else if(b=='=')
					flag = false;
			}
			i++;
		}
		int j = 0;
		long long int ans = numq[j];
		for (int i = 0; i < opq.size(); ++i)
		{
			j++;
			ans = calculate(ans,opq[i],numq[j]);
		}
		cout << ans << "\n";
		numq.clear();
		opq.clear();
	}
	return 0;
}