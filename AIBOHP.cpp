#include <bits/stdc++.h>

using namespace std;

int insertion(char *a,int n)
{
	int table[n][n];
	int l,h;
	memset(table,0,sizeof(table));
	for (int i = 1; i < n; ++i)
		for (l = 0,h = i; h < n; ++h,++l)
			table[l][h] = (a[l]==a[h]) ? table[l+1][h-1] : min(table[l][h-1],table[l+1][h]) + 1;
	return table[0][n-1];
}

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		string str1;
		cin >> str1;
		int len = str1.length();
		char str[len];
		strcpy(str,str1.c_str());
		cout << insertion(str,len) << "\n";
	}
	return 0;
}