#include <bits/stdc++.h>

using namespace std;

void dyzio(string pat,int d,int *it,int *md,int *mc,int *cnt)
{
    if(pat[*it]=='1')
    {
        *mc += 1;
        if(d > *md)
        {
            *md = d;
            *cnt = *mc;
        }
        *it += 1;
        dyzio(pat,d+1,it,md,mc,cnt);
        *it += 1;
        dyzio(pat,d+1,it,md,mc,cnt);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 10;
    while(tc--)
    {
        int n,it = 0,md = -1,mc = 0,cnt = 0;
        string pat;
        cin >> n;
        cin >> pat;
        dyzio(pat,0,&it,&md,&mc,&cnt);
        cout << cnt << "\n";
    }
    return 0;
}
