import math

def eccentricity(x,y) :
	return math.sqrt((x*x - y*y)/(x*x))

tc = input()
while tc > 0 :
	a,b = raw_input().split()
	e = eccentricity(float(a),float(b))
	d = 2 * float(a) * e
	print("%.3f" % d)
	tc -= 1