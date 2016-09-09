#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
	int a[110],i,j,t,c,k,len;
	char br[110];
	while(scanf("%s",br)!=EOF)
	{
		j = 0;
		len = strlen(br);
		if(len==1 && br[0]==49)
			printf("1\n");
		else
		{
			for (i = len-1; i >= 0; i--)
			{
				a[j] = br[i]-'0';
				j++;
			}
			c=0;
			for (i = 0; i < len; ++i)
			{
				t = a[i]*2 + c;
				a[i] = t%10;
				c = t/10;
			}
			if(c>0)
			{
				a[len] = c;
				k = len + 1;
			}
			else
				k = len;
			c = 2;
			for (i = 0; i < k; ++i)
			{
				if(a[i] >= c)
				{
					a[i] -= c;
					break;
				}
				else
				{
					a[i] = a[i] + 10 - c;
					c = 1;
				}
			}

			for (i = k-1; i >=0; i--)
				cout << a[i];
			cout << "\n";
		}
	}
    return 0;
}
