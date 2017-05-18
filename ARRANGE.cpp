#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,ip,one = 0,k = 0;
        cin >> n;
        int *a = new int[n];
        for(int i = 0; i < n; i++)
        {
            cin >> ip;
            if(ip==1)
                one++;
            else
                a[k++] = ip;
        }
        sort(a,a+k);
        while(one--)
            cout << "1 ";
        if(k==2 && a[0]==2 && a[1]==3)
            cout << 2 << " " << 3;
        else
        {
            for(int i = k-1; i >=0 ; i--)
                cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}