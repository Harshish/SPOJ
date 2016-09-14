#include <bits/stdc++.h>

using namespace std;

void favConditions(int n,int k,int adder,int *cnt)
{
	if(n==1)
	{
		if(adder+1==k || adder+2==k || adder+3==k || adder+4==k || adder+5==k || adder+6==k)
			(*cnt)++;
		return;
	}
	for (int i = 1; i < 7; ++i)
	{
		adder += i;
		favConditions(n-1,k,adder,cnt);
		adder -= i;
	}
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(n > 545 && k > 1908)
		{
			printf("0\n");
			continue;
		}
		int *cnt = new int();
		/*if(n > 545 && k > 1908)
		{
			printf("0\n");
			continue;
		}*/
		favConditions(n,k,0,cnt);
		int den = 1;
		for (int i = 0; i < n; ++i)
			den = den*6;
		int num = (*cnt) * 100;
		int ans = floor(num/den);
		printf("%d\n",ans);
	}
	return 0;
}