#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc,n;
	cin >> tc;
	while(tc--)
	{
		string txt,pat;
		cin >> txt >> pat;
		int arr[pat.length()];
		int i = 1,j = 0;
		arr[0] = 0;
		while(i!=pat.length())
		{
			if(pat[j]==pat[i])
			{
				arr[i] = j + 1;
				j++;
			}
			else
			{
				while(pat[j]!=pat[i] && j-1 >= 0)
					j = arr[j-1];
				if(pat[j]==pat[i])
					arr[i] = j + 1;
				else
					arr[i] = 0;
			}
			i++;
		}
		int occ = 0;j = 0;
		vector<int> pos;
		for (i = 0; i < txt.length(); ++i)
		{
			if(pat[j]==txt[i])
			{
				j++;
				if(j==pat.length())
				{
					j = 0; occ++;
					pos.push_back(i-pat.length()+2);
				}
			}
			else
			{
				if(j > 0)
				{
					i--;
					j = arr[j - 1];
				}
				else
					j = 0;
			}
		}
		if(occ > 0)
		{
			printf("%d\n",occ);
			for (i = 0; i < pos.size(); ++i)
				cout << pos[i] << " ";
			cout << endl;
		}
		else
			printf("Not Found\n");
	}
	return 0;
}
