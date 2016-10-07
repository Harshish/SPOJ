#include <bits/stdc++.h>

using namespace std;

int insertion(char *a,int st,int end)
{
	if(st==end-1 && a[st]!=a[end])
		return 1;
	if(st>=end)
		return 0;
	if(a[st]==a[end])
		return insertion(a,st+1,end-1);
	int val1 = insertion(a,st,end-1);
	int val2 = insertion(a,st+1,end);
	if(val2 > val1)
		return val1 + 1;
	else
		return val2 + 1;
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
		cout << insertion(str,0,len-1) << "\n";
	}
	return 0;
}