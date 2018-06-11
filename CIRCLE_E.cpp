#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int tc;
    cin >> tc;   
    while(tc--)
    {
        double a,b,c;
        cin >> a >> b >> c;
        double term = 2.0 * sqrt(a * b * c * (a + b + c));
        double ans = (a * b * c)/(a * b + b * c + c * a + term);
        printf("%.6lf\n",ans);
    }
    return 0;
}
