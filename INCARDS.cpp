#include <bits/stdc++.h>

using namespace std;

void dijikstraPQ(vector< pair<int,int> > adj[],int *dist,int n,int src)
{
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
    pq.push(make_pair(src,0));
    dist[src] = 0;
    while(!pq.empty())
    {
        pair<int,int> e = pq.top();
        int x = e.first;
        int wt = e.second;
        pq.pop();
        for(int i = 0; i < adj[x].size(); i++)
        {
            if(dist[adj[x][i].first] > wt + adj[x][i].second)
            {
                dist[adj[x][i].first] = wt + adj[x][i].second;
                pq.push(make_pair(adj[x][i].first,dist[adj[x][i].first]));
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int p,q,src,dst,wt;
        cin >> p >> q;
        vector < pair<int,int> > fwd[p+1],bk[p+1];
        for(int i = 0; i < q; i++)
        {
            cin >> src >> dst >> wt;
            fwd[src].push_back(make_pair(dst,wt));
            bk[dst].push_back(make_pair(src,wt));
        }
        int *dist1 = new int[p+1];
        int *dist2 = new int[p+1];
        fill(dist1,dist1+p+1,INT_MAX);
        fill(dist2,dist2+p+1,INT_MAX);
        dijikstraPQ(fwd,dist1,p,1);
        dijikstraPQ(bk,dist2,p,1);
        int ans = 0;
        for(int i = 2; i <= p; i++)
            ans += dist1[i] + dist2[i];
        cout << ans << '\n';
    }
    return 0;
}
