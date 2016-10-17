#include <bits/stdc++.h>

using namespace std;

bool flag = false;

bool allset(int *cnt,int n)
{
	for (int i = 0; i < 4; ++i)
		if (cnt[i]!=n)
			return false;
	return true;
}

void setColor(char **mat,int *cnt,int n,string colors,int *col)
{

	if(*col==2*n)
	{
		if(allset(cnt,n))
			flag = true;
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		if(*col==0)
		{
			if(mat[0][*col]!=colors[i])
			{
				mat[1][*col] = colors[i];
				cnt[i]++;
				(*col)++;
				setColor(mat,cnt,n,colors,col);
				if(flag)
					return;
				(*col)--;
				cnt[i]--;
				mat[1][*col] = '\0';
			}
			
		}
		else
		{
			if(mat[0][*col]!=colors[i] && mat[1][*col-1]!=colors[i])
			{
				mat[1][*col] = colors[i];
				cnt[i]++;
				(*col)++;
				setColor(mat,cnt,n,colors,col);
				if(flag)
					return;
				cnt[i]--;
				(*col)--;
				mat[1][*col] = '\0';
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	char **mat = new char*[2]();
	mat[0] = new char[2*n]();
	mat[1] = new char[2*n+1]();
	string s;
	cin >> s;
	int *cnt = new int[4]();
	for (int i = 0; i < 2*n; ++i)
	{
		mat[0][i] = s[i];
		switch(s[i])
		{
			case 'A' : 	cnt[0]++;
						break;

			case 'B' : 	cnt[1]++;
						break;

			case 'C' : 	cnt[2]++;
						break;

			case 'D' : 	cnt[3]++;
						break;
		}
	}
	string colors = "ABCD";
	int col = 0;
	setColor(mat,cnt,n,colors,&col);
	if(flag)
		puts(mat[1]);
	else
		cout << "NOPE\n";
}                                            