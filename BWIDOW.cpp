#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        long long int a[n][2],max = 0,max2 = 0;
        int index;
        for(int i = 0; i < n; i++)
        {
            scanf("%lld%lld",&a[i][0],&a[i][1]);
            if(a[i][0] > max)
            {
                max = a[i][0];
                index = i;
            }
            else if(a[i][1] > max2)
                max2= a[i][1];
        }

        if(max > max2)
            printf("%d\n",index+1);
 	    else
            printf("-1\n");
    }
    return 0;

}