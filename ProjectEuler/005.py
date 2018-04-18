def gcd(x,y):
	return y if (x%y==0) else gcd(y,x%y)

def lcm(x,y):
	return x//gcd(x,y)*y

ans=1
for i in range(1,21):
	ans=lcm(ans,i)
print(ans)
