#include <bits/stdc++.h>

using namespace std;

#define INF 9999999

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int e,f,n,w;

        scanf("%d%d%d",&e,&f,&n);
        int coin[n],wt[n];
        w = f - e;
        for(int i=0;i<n;i++)
            scanf("%d%d",&coin[i],&wt[i]);

        int dp[w+1];
        dp[0] = 0;

        for(int  i = 1; i<=w; i++){
            dp[i] = INF;
            for(int j = 0; j < n; j++){
                if(wt[j] <= i){
                    dp[i] = min(dp[i],coin[j] + dp[i - wt[j]]);
                }
            }
        }
        
        if(dp[w]==INF) 
            printf("This is impossible.\n");
        else 
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[w]);
    }
    return 0;
}
