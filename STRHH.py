import sys
t = raw_input()
for x in range(0,int(t)):
	string = raw_input()
	k = len(string)/2
	for i in range(0,int(k),2):
		sys.stdout.write(string[i])
	print
