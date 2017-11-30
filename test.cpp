#include <bits/stdc++.h>

using namespace std;

void printNum(unsigned long long x)
{
	//cout << x;
	getchar();
	if(x < 1){return;}else if(x==1){printf("2(0)");}else if(x==2){printf("2");}else if(x==3){printf("2+2(0)");}
	int n = log2(x);printf("2(");printNum(n);printf(")");unsigned long long num = x - pow(2,n);
	if(num > 0){printf("+");printNum(num);}
}

int main()
{
	unsigned long long x;
	while (scanf("%llu", &x) != EOF){printf("%llu=",x);getchar();printNum(x);}
	return 0;
}