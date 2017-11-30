import math
def findRep(x):
    if(x == 1):
        return "2(0)"
    elif(x == 2):
        return "2"
    elif(x == 3):
        return "2+2(0)"
    n = int(math.log2(x))
    s = "2({})".format(findRep(n))
    num = 2**n
    if x-num > 0:
        return s + "+" + findRep(x-num)
    else:
        return s
while 1:
    try:
       x = int(input())
       print(str(x) + "={}".format(findRep(x)))
    except:
        break        