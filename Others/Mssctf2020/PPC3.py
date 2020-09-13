t=int(input())
for x in range(t):
	n=int(input())
	st=input()
	li=[]
	stl=len(st)
	less=stl-(stl//n)*n
#	print(less)
	for i in range(less):
		li.append(st[i*(stl//n+1):(i+1)*(stl//n+1)])
	for i in range(n-less):
		li.append(st[less*(stl//n+1)+i*(stl//n) : less*(stl//n+1)+(i+1)*(stl//n)])
#	print(li)
	for ind in range(stl//n+1):
		for i in li:
			try:
				print(i[ind], end='')
			except:
				pass
	print()
