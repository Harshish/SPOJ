/*
Courtesy https://github.com/dexter1691/Algorithms/blob/master/Spoj/ABCD.cpp
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	long n;
	int i;
	scanf("%d",&n);
	getchar();
	char a[2][200000];
	for(i=0;i<2*n;i++)
		scanf("%c",&a[0][i]);
	for (int i = 0; i < 2*n; i+=2)
	{
		int p1 = -1,p2 = -1;
		int colors[4] = {1,1,1,1};
		colors[mat[0][i]-65] = 0;
		colors[mat[0][i+1]-65] = 0;
		for (int j = 0; j < 4; ++j)
		{
			if(colors[j])
			{
				if(p1==-1)
					p1 = j;
				else
					p2 = j;
			}
		}
		if(mat[1][i-1] - 65==p1)
		{
			mat[1][i] = p2 + 65;
			mat[1][i+1] = p1;
		}
		else
		{
			mat[1][i] = p1 + 65;
			mat[1][i+1] = p2 + 65;
		}
	}
	cout << mat[1];
}                                            