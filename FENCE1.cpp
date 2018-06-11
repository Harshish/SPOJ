#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    const float PI = 3.14159;
    while(cin >> n && n > 0)
    {
        float ans = (n * n)/(2*PI);
        printf("%.2lf\n",ans);
    }
    return 0;
}
