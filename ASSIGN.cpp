#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int N;
		cin >> N;
		int like[N][N];
		for(int i=0;i<N;++i)
		    for(int j=0;j<N;++j)
		        cin >> like[i][j];
	
		int NMAX = (1<<N);
		int dp[NMAX];
		for(int i=0;i<NMAX;++i) 
		    dp[i] = 0;
		
		dp[NMAX-1] = 1;
		for(int b=NMAX-1;b>=0; --b) 
		{
		    int n = b;
		    int k = 0;
		    while(n)
		    {
		        k += (n&1);
		        n /= 2;
		    }
		    if(k==N)
		    	continue;
		    for(int i=0;i<N;++i)
		    {
		        if(like[k][i] && !(b & (1<<i)))
		        {
		            dp[b] += dp[b | (1<<i)];

		        }
		    }
		}
		cout << dp[0]  << endl;
	}
	return 0;
}                                            