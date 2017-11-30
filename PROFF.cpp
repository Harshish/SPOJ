#include <bits/stdc++.h>

using namespace std;

int convInt(char c)
{
	return c - '0';
}

int main()
{
	string a,b;
	while(1)
	{
		cin >> a >> b;
		if (a == "0" && b == "0")
			break;
		int i = a.length() - 1;
		int j = b.length() - 1;
		int carry = 0,sum,cnt = 0;
		while(i >=0 && j >= 0)
		{
			sum = convInt(a[i]) + convInt(b[j]) + carry;
			carry = sum/10;
			if(sum > 9)
				cnt++;
			i--;
			j--;
		}

		while(i >= 0)
		{
			sum = carry + convInt(a[i]);
			carry = sum/10;
			if(sum > 9) 
				cnt += 1;
			i--;
		}

		while (j >= 0)
		{
			sum = carry + convInt(b[j]);
			carry = sum / 10;
			if (sum > 9)
				cnt += 1;
			j--;
		}

		if(cnt==0)
			cout << "No carry operation.\n";
		else if(cnt==1)
			cout << "1 carry operation.\n";
		else
			cout << cnt << " carry operations.\n";
	}
	return 0;
}