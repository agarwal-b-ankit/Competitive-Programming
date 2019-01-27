t=int(input())
for k in range(t):
	n=int(input())
	s=input().split()
	lis=[int(x) for x in s]
	m = {}
	for item in lis:
	    if item not in m:
	        m[item]=0
	    m[item]+=1
	ans=0
	tsum=pow(2,n-1)
	for k,v in m.items():
	    if k >= tsum:
	        ans = ans+k*v
	print(ans%1000000007)
