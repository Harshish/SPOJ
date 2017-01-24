#include <bits/stdc++.h>

using namespace std;

long long getValue(long long n)
{
	if(n==0)
		return 0;
	if(n==1 || n==2 || n==3 || n==4 || n==5 || n==6 
		|| n==7 || n==8 || n==9 || n==10 || n==11 
		|| n==13 || n==14 || n==15 || n==17 || n==19
		|| n==23)
		return n;
	long long a = getValue(n/2) + getValue(n/3) + getValue(n/4);
	if(a < n)
		return n;
	else
		return a;
}

int main()
{
	long long n;
	while(scanf("%lld", &n) != EOF)
		cout << getValue(n) << "\n";
	return 0;
}
