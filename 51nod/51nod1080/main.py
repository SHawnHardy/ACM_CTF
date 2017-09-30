from math import *

n=input()
flag=True

t=0
while True:
	if (t*t>n):
		break
	tt=int(floor(sqrt(n-t*t)))
	
	if (tt<t):
		break
	if tt*tt+t*t==n:
		print "%d %d" % (t,tt)
		flag=False
	t+=1
			

if flag:
	print "No Solution"
	
