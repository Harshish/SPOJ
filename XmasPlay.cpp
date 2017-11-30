#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	short int tc;
    cin >> tc;
    while(tc--)
    {
    	vector<int> a;
    	int k,i;
    	int n,val,min=0;
    	cin >> n >> k;
    	for (int j = 0; j < n; ++j)
    	{
    		cin >> val;
    		a.push_back(val);
    	}
    	sort(a.begin(),a.end());
    	min = a[k-1] - a[0];
    	for (i = 1; i <= n-k; i++)
    		if(a[k+i-1]-a[i] < min)
    			min = a[k+i-1]-a[i];
    	cout << min << "\n";
    }
    return 0;
}
