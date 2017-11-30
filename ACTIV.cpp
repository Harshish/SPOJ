//Credits:
//Sumit Vohra
//https://www.quora.com/How-do-I-come-up-with-a-solution-for-SPOJ-ACTIV-Activities

#include <bits/stdc++.h>

using namespace std;

#define MOD 100000000
#define MAX 100003

int dp[MAX][2];

void getPermutation(vector< pair<int,int> > &v,int n)
{
	vector<int> entime;
	memset(dp,0,sizeof(dp[0][0])*2*MAX);
	entime.push_back(v[0].first);
	dp[0][1] = 1;
	for (int i = 1; i < n; ++i)
	{
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		if(dp[i][0] >= MOD)
			dp[i][0] -= MOD;
		if(v[i].second < entime[0])
			dp[i][1] = 1;
		else
		{
			int index = upper_bound(entime.begin(),entime.end(),v[i].second) - entime.begin();
			index--;
			dp[i][1] = 1 + dp[index][0] + dp[index][1];
			if(dp[i][0] >= MOD)
				dp[i][0] -= MOD;
		}
		entime.push_back(v[i].first);
	}
	printf("%0.8d\n",(dp[n-1][0]+dp[n-1][1])%MOD);
}

int main()
{
	int n;
	while(1)
	{
		cin >> n;
		if(n==-1)
			break;
		int s,e;
		vector< pair<int,int> > timings;
		for (int i = 0; i < n; ++i)
		{
			cin >> s >> e;
			timings.push_back(make_pair(e,s));
		}
		sort(timings.begin(),timings.end());
		getPermutation(timings,n);
	}
	return 0;
}