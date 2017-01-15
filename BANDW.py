while(1):
	s,t = raw_input().split()
	if s=="*":
		break
	cnt = 0
	flag = 1
	for i,j in zip(s,t) : 
		if i!=j and flag :
			cnt += 1
			flag = 0
		if i==j and not(flag) :
			flag = 1
	print(cnt)