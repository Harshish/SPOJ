#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<long long> left,right,fin;
    long long *items = new long long[n];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> items[i];
    long long counter = pow(2,n) - 1;
    long long diff = 100000000000000,d;
    long long sum1,sum2;

    for(long long i = 0; i <= counter; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((1<<j) & i)
                left.push_back(j);
            else 
                right.push_back(j);
        }
        sum1 = 0;
        sum2 = 0;
        for(int k = 0; k < left.size(); k++)
            sum1 += items[left[k]];
        for(int k = 0; k < right.size(); k++)
            sum2 += items[right[k]];
        d = abs(sum1-sum2);

        if(d < diff)
        {
            diff = d;
            fin.clear();
            for(int k = 0; k < left.size(); k++)
                fin.push_back(left[k]);
        }
        left.clear();
        right.clear();
    }

    for(int k = 0; k < fin.size(); k++)
        printf("%lld\n",fin[k] + 1);
    return 0;
}