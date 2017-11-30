tc = input()
while tc > 0 :
	fn = input()
	if fn%11==0:
		print 0
	elif fn%11==1:
		print 3 
	elif fn%11==2:
		print 6 
	elif fn%11==3:
		print 9 
	elif fn%11==4:
		print 1
	elif fn%11==5:
		print 4
	elif fn%11==6:
		print 7
	elif fn%11==7:
		print 10
	elif fn%11==8:
		print 2
	elif fn%11==9:
		print 5
	elif fn%11==10:
		print 8	 
	tc -= 1