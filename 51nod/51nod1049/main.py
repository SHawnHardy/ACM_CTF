n=input()
num=[]
for i in range(n):
	t=input()
	num.append(t)
dp=[0 for i in range(n)]
ans=0
for i in range(n):
	dp[i]=max(dp[i-1]+num[i],num[i])
	ans=max(ans,dp[i])

print ans
