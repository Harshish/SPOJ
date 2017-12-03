#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int,long> &a,const pair<int,long> &b)
{
    return b.second > a.second;
}

void print(vector< pair<int,long> > v,int st,int n)
{
    for(int i = st; i < n;i++)
        cout << v[i].first << "\n";
}

int main()
{
    int n;
    scanf("%d",&n);
    vector< pair<int,long> > v;
    long temp,sum = 0,mid;
    for(int i = 0; i < n; i++)
    {
        scanf("%ld",&temp);
        v.push_back(make_pair(i+1,temp));
    }
    sort(v.begin(),v.end(),cmp);
    int i = 0,j = v.size() - 1;
    long s1 = v[i].second,s2 = v[j].second;
    j--;
    i++;
    while(i <= j)
    {
        if(s1 < s2)
        {
            s1 += v[i].second;
            i++;
        }
        else
        {
            s2 += v[j].second;
            j--;
        }
    }
    if(s1 > s2)
        print(v,0,i);
    else
        print(v,j+1,n);
    return 0;
}