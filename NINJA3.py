def gcd(a,b):
    while b:
        a,b = b, a%b
    return a

n = int(input())
while n > 0:
    N,a,b = input().split(' ')
    n1 = int(a)
    n2 = int(b)
    val = gcd(n1,n2)
    print(N*val)
    n -= 1