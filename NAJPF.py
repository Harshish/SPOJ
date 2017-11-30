n = int(input())
while n > 0:
    a,b = input().split(' ')
    val = a.count(b)
    if val==0 :
        print("Not Found")
        n -= 1
        continue
    print(val)
    index = 0
    while index < len(a):
        index = a.find(b,index)
        if index == -1:
            break
        print(index+1,end=' ')
        index += len(b) 
    print()
    n -= 1