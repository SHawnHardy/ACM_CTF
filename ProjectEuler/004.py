ans=101*101
for i in range(100,1000):
	for j in range(100,1000):
		if i*j < ans:
			continue
		num=str(i*j)
		if num==num[::-1]:
			ans=i*j
print(ans)
