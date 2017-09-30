str=raw_input()
[n,mod]=[int(n) for n in str.split()]
ans=1

for i in range(1,n+1):
	ans*=i
	ans%=mod
print ans
