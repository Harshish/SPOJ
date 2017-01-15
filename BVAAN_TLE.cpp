#include <bits/stdc++.h>

using namespace std;

int k,m = 0;

int maxof(int a,int b,int c)
{
	if(a >= b && a >= c)
		return a;
	else if (b >= c && b >= a)
		return b;
	else
		return c;
}	

int retStr(string b1,string b2,int i,int j,int lim)
{
	if(lim==k)
		return 0;
	if(i < 0 || j < 0)
		return 0;
	int a = 0,b = 0,c = 0;
	if(b1[i]==b2[j])
	{
		a += (int)b1[i];
		i--;
		j--;
		lim++;
		a += retStr(b1,b2,i,j,lim);
		if(lim > m)
			m = lim;
		lim--;
		i++;
		j++;
	}
	i--;
	b += retStr(b1,b2,i,j,lim);
	i++;
	j--;
	c += retStr(b1,b2,i,j,lim);
	j++;
	if(m < k)
		return 0;
	else
		return maxof(a,b,c);
}

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		string b1,b2;
		cin >> b1;
		cin >> b2;
		cin >> k;
		int i = b1.length() - 1,j = b2.length() - 1;
		cout << retStr(b1,b2,i,j,0) << "\n";
		m = 0;
	}
	return 0;
}