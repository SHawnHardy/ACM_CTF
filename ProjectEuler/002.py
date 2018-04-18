limit=4000000
ans=0

a=0
b=1
while b<limit:
	if (b%2==0):
		ans+=b
	a=a+b
	a,b=b,a
print(ans)
