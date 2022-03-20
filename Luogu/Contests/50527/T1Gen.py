from random import randint

with open("data.in", "w") as file:
	n = randint(9e4, 1e5)
	file.write(str(n)+'\n')
	for i in range(n):
		file.write(str(randint(8e8, 1e9))+' ')
