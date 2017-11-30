#include <bits/stdc++.h>

using namespace std;

int removeZeroes(int num)
{
	while(num%10==0 && num > 9)
		num = num/10;
	return num;
}

int main()
{
	int tc,num;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&num);
		bool flag = true;
		num = removeZeroes(num);
		double ul = num*1.05;
		double ll = num*0.95;
		int var1 = num - (num%10);
		if (var1 >= ll && var1 <= ul)
		{
			printf("absurd\n");
			continue;
		}
		int var2 = var1 + 5;
		if (var2 >= ll && var2 <= ul && var2 != num)
		{
			printf("absurd\n");
			continue;
		}
		int var3 = var2 + 5;
		if (var3 >= ll && var3 <= ul)
		{
			printf("absurd\n");
			continue;
		}
		else
			printf("not absurd\n");
	}
	return 0;
}