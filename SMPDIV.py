k =  raw_input()
for j in xrange(0,int(k)):
	n,x,y = raw_input().split()
	for i in xrange(1,int(n)):
		if (i%int(x)==0) and (i%int(y)!=0):
			print (i),
	print 
