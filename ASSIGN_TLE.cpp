#include <bits/stdc++.h>

using namespace std;

void assign(int **mat,int *v,int *sum,int n,int *row)
{
	if(*row==n)
	{
		(*sum)++;
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if(!v[i] && mat[*row][i])
		{
			v[i] = 1;
			(*row)++;
			assign(mat,v,sum,n,row);
			(*row)--;
			v[i] = 0;
		}
	}
}

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		int **mat = new int*[n];
		for (int i = 0; i < n; ++i)
		{
			mat[i] = new int[n];
			for (int j = 0; j < n; ++j)
				cin >> mat[i][j];
		}
		int sum = 0,row = 0;
		int *v = new int[n]();
		assign(mat,v,&sum,n,&row);		
		cout << sum << "\n";
	}
	return 0;
}