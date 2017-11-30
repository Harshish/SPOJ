#include <bits/stdc++.h>

using namespace std;

int main()
{
	int plen;
	while(scanf("%d",&plen)!=EOF)
	{
		string txt,pat;
		cin >> pat;
		cin >> txt;
		
		int j = 0,i = 1;
		int *prefix = new int[plen]();
		while(i < plen)
		{
			if(pat[j]==pat[i])
			{
				j++;
				prefix[i] = j;
				i++;
			}
			else
			{
				if(j!=0)
					j = prefix[j-1];
				else
					i++;
			}

		}
		j = 0;
		i = 0;
		vector<int> index;
		while(i < txt.length())
		{
			if(pat[j]==txt[i])
			{
				i++;
				j++;
			}
			else
			{
				if(j!=0)
					j = prefix[j-1];
				else
					i++;
			}
			if(j==plen)
			{
				index.push_back(i - plen);
				i = i - plen + 1;
				j = 0;
			}

		}
		for (int i = 0; i < index.size(); ++i)
			cout << index[i] << "\n";
		cout << "\n";
	}
	return 0;
}                                            