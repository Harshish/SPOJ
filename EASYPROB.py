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
        
print("137={}".format(findRep(137)))
print("1315={}".format(findRep(1315)))
print("73={}".format(findRep(73)))
print("136={}".format(findRep(136)))
print("255={}".format(findRep(255)))
print("1384={}".format(findRep(1384)))
print("16385={}".format(findRep(16385)))
