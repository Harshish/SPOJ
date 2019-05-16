//TODO: Why WA?

#include <bits/stdc++.h>
using namespace std;

set<int> lis(int *a,int st,int n)
{
    set<int> s;
    s.insert(a[st]);
    int prev = a[st];
    for(int i = st+1; i < n; i++)
    {
        if(a[i] > prev)
        {
            s.insert(a[i]);
            prev = a[i];
        }
    }
    return s;
}

int main() {
	int tc = 10;
	while(tc--)
	{
	    int n;
        cin >> n;
        int *a = new int[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        set<int> s,k;
        for(int i = 0; i < n-1 && n-i > k.size(); i++)
        {
            k = lis(a,i,n);
            if(k.size() > s.size())
                s = k;
            else if(k.size() == s.size())
            {
                set<int>::iterator it;
                for(it = k.begin(); it!=k.end(); it++)
                    s.insert(*it);
            }
        }
        cout << s.size() << "\n";
        set<int>::iterator it;
        for(it = s.begin(); it!=s.end(); it++)
            cout << *it << " ";
        cout << "\n";
	}
	return 0;
}
