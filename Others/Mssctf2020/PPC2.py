a = int(input())
for i in range(a):
	ans = int(1)
	n = int(input())
	a = input().split()
	for i in range(n):
		ans*=int(a[i]);
	if(ans>1e18):
		print(-1, end='\n')
	else:
		print(ans, end='\n')
