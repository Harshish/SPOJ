#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
	string s;
	char str[10];
	while(tc--)
	{
        cin >> s;
        count = s.length();
        int chk = 0;
        strcpy(str,s.c_str());
        for (int i = 0; i < count; i++)
        	if (a[i] != a[count-j-1] )
        		chk = 1;
        if (chk==0)
        	cout << "YES\n";
        else
        	cout << "NO\n";
	}
    return 0;
}
