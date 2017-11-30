tc = int(input())
while tc > 0:
    n = int(input())
    
    x = 0
    if n%4!=0:
        x = int(n/4) + 1
    else:
        x = n/4

    x = 2*x -1
    
    if(n % 4)==0:
        print(int(-(x+1)),int(-(x+1)))
    elif (n % 4)==1:
        print(x,int(-(x-1)))
    elif (n % 4) == 2:
        print(x, int(x + 1))
    elif (n % 4) == 3:
        print(int(-(x + 1)), int(x + 1))
    tc -= 1
