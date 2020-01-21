#include <bits/stdc++.h>

using namespace std;

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,prev;
    cin >> n;
    vector<int> a(n);
    fr(i,0,n-1)
        cin >> a[i];

    vector<int> lis(n,1);
    fr(i,1,n-1)
        fr(j,0,i-1)
            if(abs(a[j]) < abs(a[i]) && (a[j]/abs(a[j]))!=(a[i]/abs(a[i])))
                lis[i] = max(lis[i],lis[j] + 1);

    cout << *max_element(lis.begin(),lis.end()) << "\n";
    return 0;
}
