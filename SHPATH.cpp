#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

unordered_map<string,int> hm;
vector<vector<pair<int,int> > > adj(10002);
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>> > pq;

int dijikstra(int src,int dst,int n){
    vector<int> dist(n+1,INF);

    pq.push(make_pair(0,src));
    dist[src] = 0;

    while(!pq.empty()){
        int index = pq.top().second;
        pq.pop();

        for(int j = 0; j < adj[index].size(); j++){
            int k = adj[index][j].first;
            int c = adj[index][j].second;
            if(dist[k] > dist[index] + c){
                dist[k] = dist[index] + c;
                pq.push(make_pair(dist[k],k));
            }
        }
    }
    return dist[dst];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,p,nr,cost,r,src,dst;
        char name[20],name2[20];
        
        scanf("%d",&n);

        for(int i = 0; i < n; i++){
            scanf("%s",name);
            scanf("%d",&p);
            hm[name] = i+1;
            for(int j = 0; j < p ; j++){
                scanf("%d %d",&nr,&cost);

                adj[i+1].push_back(make_pair(nr,cost));
            }
        }

        scanf("%d",&r);
        for(int i = 0; i < r; i++){
            scanf("%s%s",name,name2);
            src = hm[name];
            dst = hm[name2];
            printf("%d\n",dijikstra(src,dst,n));
        }

        hm.clear();
        for(int i = 1; i <= n; i++) adj[i].clear();

    }
    return 0;
}
