from math import ceil

tc = input()
while tc > 0:
	n = input()
	val = []
	for x in xrange(0,n):
		val.append(float(raw_input().split()[1]))
	val.sort()
	la = float(val[n-1] - val[0])
	for x in xrange(1,n):
		tmp = 360.0 - val[x] + val[x-1]
		la = min(la,tmp)
	la *= 12.0
	print "%d" % int(ceil(la))
	tc -= 1