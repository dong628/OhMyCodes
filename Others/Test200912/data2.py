import random

f=open("sequence.in", "w");
ra=random.randint(10, 100000);
f.write('10 '+str(ra)+" ");
for i in range(10):
	f.write(str(random.randint(1, 10))+' ')
f.close()
