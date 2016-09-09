#include <iostream>

using namespace std;

int a[100][100],c;

int maxResult(int row,int col)
{
	int ak,b,ck;
	if(row<0 || col<0 || col > c-1)
		return 0;
    if(row==0)
        return a[row][col];
	ak = maxResult(row-1,col-1) + a[row][col];
	b = maxResult(row-1,col) + a[row][col];
	ck = maxResult(row-1,col+1) + a[row][col];
	if(ak >= b && ak >= ck)
		return ak;
	else if (b >= ak && b >= ck)
		return b;
	else
		return ck;
}


int main()
{
	int tc,i,j,r,max = 0;
	cin >> tc;
	while(tc--)
	{
		cin >> r >> c;
		for (i = 0; i < r; ++i)
			for (j = 0; j < c; ++j)
				cin >> a[i][j];
		for (i = c-1; i >= 0 ; i--)
		{
			j = maxResult(r-1,i);
			if (max < j)
				max = j;
		}
		cout << max << "\n";
	}
    return 0;
}
