def func(x,m):
	re=0
	for i in range(1,x):
		re+=m
		re%=(i+1)
	return re



[n,m]=[int(x) for x in raw_input().split()]

print func(n,m)+1
