#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

ULL findMin(ULL *d,ULL *mst,ULL n)
{
    ULL wt = INT_MAX, mindex = -1;
    for(ULL i = 1; i <= n; i++)
    {
        if(wt > d[i] && !mst[i])
        {
            wt = d[i];
            mindex = i;
        }
    }
    return mindex;
}

ULL findMST(ULL **mat,ULL n)
{
    ULL *parent = new ULL[n+1]();
    ULL *mst = new ULL[n+1]();
    ULL *dst = new ULL[n+1]();
    for(ULL i = 0; i <= n; i++)
        dst[i] = INT_MAX;
    dst[1] = 0;
    for(ULL i = 0; i < n; i++)
    {
        ULL v = findMin(dst,mst,n);
        mst[v] = 1;
        for(ULL j = 1; j <= n; j++)
        {
            if(mat[v][j] && dst[j] > mat[v][j] && !mst[j])
            {
                dst[j] = mat[v][j];
                parent[j] = v;
            }
        }
    }

    ULL wt = 0;
    for(ULL i = 1; i <= n; i++)
        if(parent[i])
            wt += mat[parent[i]][i];

    return wt;
}

int main()
{
    ULL v,e; 
    cin >> v >> e;
    ULL s,d,w;

    //GRAPH
    ULL **mat = new ULL*[v+1]();
    for(ULL i = 0; i <= v; i++)
        mat[i] = new ULL[v+1]();
    for(ULL i = 0; i < e; i++)
    {
        cin >> s >> d >> w;
        mat[s][d] = w;
        mat[d][s] = w;
    }

    cout << findMST(mat,v) << "\n";
    return 0;
}
