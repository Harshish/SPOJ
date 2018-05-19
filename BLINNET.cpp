#include <bits/stdc++.h>
using namespace std;

typedef struct edges
{
    int s,d,w;
}EDGE;

void printVector(vector<EDGE> v)
{
    for(int i = 0; i < v.size(); i++)
        cout << "S: " << v[i].s << " D: " << v[i].d << " W: " << v[i].w << "\n";
}

int find(int *parent,int x)
{
    if(parent[x]==-1)
        return x;
    parent[x] = find(parent,parent[x]);
    return parent[x];
}

void Union(int x,int y,int *parent)
{
    int s1 = find(parent,x);
    int s2 = find(parent,y);
    parent[s2] = s1;
}

bool isCycle(int x,int y,int *parent)
{
    if(find(parent,x)==find(parent,y))
        return true;
    Union(x,y,parent);
    return false;
}

bool compareEdge(EDGE e1, EDGE e2)
{
    return (e1.w < e2.w);
}

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string s;
        int n;
        cin >> n;
        vector<EDGE> v;
        for(int i = 1; i <= n; i++)
        {
            cin >> s;
            int k,d,w;
            cin >> k;
            for(int j = 0; j < k; j++)
            {
                cin >> d >> w;
                EDGE e;
                e.s = i;
                e.d = d;
                e.w = w;
                v.push_back(e);
            }
        }
        sort(v.begin(),v.end(),compareEdge);
        int *parent = new int[n+1]();
        memset(parent,-1,(n+1) * sizeof(parent[0]));

        int wt = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(!isCycle(v[i].s,v[i].d,parent))
                wt += v[i].w;
        }
        cout << wt << "\n";
    }
    return 0;
}
