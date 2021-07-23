jud = input()[::-1]
a=list()
b=list()
flag=True
fflag=True


for ind in range(len(jud)):
	if(flag==False and jud[ind]=='Z'):
		print(-1)
		fflag=False
		break
	elif jud[ind]=="Z":
		a.append(7);
		b.append(7);
	else:
		flag=False
		if jud[ind]=='X':
			a.append(3)
			b.append(7)
		else:
			a.append(7)
			b.append(3)

a.reverse()
b.reverse()
if fflag:
	for i in a:
		print(i, end='')
	print()
	for i in b:
		print(i, end='')
