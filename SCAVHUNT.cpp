#include <bits/stdc++.h>
using namespace std;

void toposort(vector< vector<int> > &v,int x,stack<int> &s,int *visited)
{
    visited[x] = 1;
    for(int i = 0; i < v[x].size(); i++)
        if(!visited[v[x][i]])
            toposort(v,v[x][i],s,visited);
    s.push(x);
}

int main()
{
    int tc;
    cin >> tc;
    int cnt = 1;
    while(tc--)
    {
        int n;
        cin >> n;
        string s,d;

        vector< vector<int> > v(n);

        map<string, int> hm;
        map<int, string> rmap;
        int st = 0;
        for(int i = 0; i < n-1; i++)
        {
            
            cin >> s >> d;
            if(hm.find(s)==hm.end())
            {
                hm[s] = st;
                rmap[st] = s;
                st++;
            }

            if(hm.find(d)==hm.end())
            {
                hm[d] = st;
                rmap[st] = d;
                st++;
            }
            v[hm[s]].push_back(hm[d]);
        }

        stack<int> stk;
        int *visited = new int[n]();
        for(int i = 0; i < n; i++)
            if(!visited[i])
                toposort(v,i,stk,visited);

        cout << "Scenario #" << cnt << ":\n";
        cnt++;
        while(!stk.empty())
        {
            cout << rmap[stk.top()] << "\n";
            stk.pop();
        }
        cout << "\n";
    }
    return 0;
}
