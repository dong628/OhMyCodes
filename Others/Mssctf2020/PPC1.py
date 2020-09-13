from math import sqrt

def gc(num):
	a=int(); b=int();
	for i in range(2, int(sqrt(num))+1):
		if(num%i==0):
			a=i;
			b=int(num/i);
			break;
	return (a, b)
	
t = int(input());
for i in range(t):
	tmp = input().split();
	n=int(tmp[0]); e=int(tmp[1]);
	zys = gc(n);
	phin = (zys[0]-1)*(zys[1]-1);
	c = 1;
#	print(phin)
#	print(e)
	while(True):
		if((phin*c+1)%e==0):
			d = (phin*c+1)//e;
			break;
		else:
			c+=1;
#			print(phin*c+1)
	print(d, end='\n');
