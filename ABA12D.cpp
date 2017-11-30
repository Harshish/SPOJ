#include <iostream>
#include <cmath>

using namespace std;

#define MAX 1000000
long long primeArray[MAX-1];

void divsorsAddition(int num,int *cnt)
{
	int sum = 1,i;
	for (i = 2; i <= num; ++i)
		if(num%i==0)
			sum += i;
	i = 0;
	while(primeArray[i]<=sum)
	{
		if(sum==primeArray[i])
			(*cnt)++;
		i++;
	}
}

int main()
{
	for (int i = 2; i <= MAX; ++i)
		primeArray[i-2] = i;

	for (int i = 0; i <= MAX-2; ++i)
	{
		long long p = primeArray[i];
		if(p > 1)
		{
			for (long long j = p*p; j <=MAX ; j += p)
				primeArray[j-2] = -1;
		}
	}
	int tc;
	cin >> tc;
	while(tc--)
	{
		int a,b;
		cin >> a >> b;
		int arr = 0;
		int *cnt = new int();
		for (int i = 0; i <= b-a; ++i)
		{
			arr = i + a;
			divsorsAddition(arr,cnt);
		}
		cout << *cnt << "\n";
	}
	return 0;
}