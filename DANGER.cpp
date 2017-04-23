#include <bits/stdc++.h>

using namespace std;

/*bool getSum(int *a,int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += a[i];
	if(sum==n-1)
		return false;
	return true;
}

int getVal(int n)
{
	if (n==1)
		return 1;
	int *a = new int[n]();
	int cnt = 1,i = 1;
	while(getSum(a,n))
	{
		if(cnt==1 && a[i]==0)
		{
			a[i] = 1;
			cnt = 0;
		}	
		else if(cnt==0 && a[i]==0)
			cnt++;
		i = (i+1)%n;
	}
	i = 0;
	while(a[i]!=0 && i < n)
		i++;
	return i+1;
}*/

int main()
{
	int x,y,z,n,temp;
	char s[5];
	while(1)
	{
		cin >> s;
		x = s[0] - '0';
		y = s[1] - '0';
		z = s[3] - '0';
		if(x==0 && y==0 && z==0)
			break;
		n = x*10 + y;
		n *= pow(10,z);
		temp = (int)log2(n);
		temp = pow(2,temp);
		int diff = n - temp;
		printf("%d\n",1 + diff*2);
	}
	/*for (int i = 1; i <= 50; ++i)
	{
		printf("FOR-> %d = %d\n",i,getVal(i));
	}*/
	return 0;
}
