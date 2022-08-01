n, k = map(int, input().split())
s = input()

f = [0]*(n+1)
for i in range(1, n):
	f[i] = int(s[0:i]);

for i in range(k):
	for j in range(n, 0, -1):
		for x in range(1, j-i):
			if x == 1:
				f[j] = f[j-x]*int(s[j-x:j])
				continue
			f[j] = max(f[j], f[j-x]*int(s[j-x:j]))
#	for j in f:
#		print(j, end=" ")
#	print()

print(f[n])
