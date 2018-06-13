#include<bits/stdc++.h>
using namespace std;

int findSum(string s)
{
    int sum = 0;
    for(int i = 0; i < s.length(); i++)
        sum += s[i] - '0';
    return sum;
}

void getGroups(string s,int st,int n,string res,int prev,int *cnt)
{
    if(st==n)
    {
        (*cnt)++;
        return;
    }
    for(int i = 0; i < n-st; i++)
    {
        string temp = s.substr(st,i+1);
        int curr = findSum(temp);
        if(curr >= prev)
        {
            res += temp;
            res += '-';
            getGroups(s,st+temp.length(),n,res,curr,cnt);
            res.erase(res.length()-temp.length()-1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int i = 1;
    while(s!="bye")
    {
        string res = "";
        int cnt = 0;
        getGroups(s,0,s.length(),res,0,&cnt);
        cout << i << ". " << cnt << "\n";
        i++;
        cin >> s;
    }
    return 0;
}
