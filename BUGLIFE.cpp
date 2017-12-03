//GIVES WA HAVE TO FIGURE OUT WHY?

#include <bits/stdc++.h>

using namespace std;

bool isBipartite(vector<int> v[],int *grp,int n,int src)
{
    queue<int> q;
    q.push(src);
    for(int i = 0; i <= n; i++)
        grp[i] = -1;
    grp[src] = 1;
    while(!q.empty())
    {
        int i = q.front();
        q.pop();
        for(int j = 0; j < v[i].size(); j++)
        {
            if(i==v[i][j])
                return false; 

            if(grp[v[i][j]]==-1)
            {
                q.push(v[i][j]);
                grp[v[i][j]] = 1 - grp[i];
            }
            else if(grp[i]==grp[v[i][j]])
                return false;
        }
    }
    return true;
}

int main()
{
    int tc,cnt = 1;
    cin >> tc;
    while(tc--)
    {
        int n,e;
        cin >> n >> e;
        vector<int> v[n+1];
        int s,d;
        for(int i = 0;i < e; i++)
        {
            cin >> s >> d;
            v[s].push_back(d);
            v[d].push_back(s);
        }
        int *grp = new int[n+1];
        printf("Scenario #%d:\n",cnt);
        if(isBipartite(v,grp,n,1))
            printf("No suspicious bugs found!\n");
        else
            printf("Suspicious bugs found!\n");
        cnt++;
    }
    return 0;
}