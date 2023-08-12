str12c = 'x1 = old + gold'
str11c = 'x2 = play + odds'
str21c = 'c1 = mad + lady'
str22c = 'c2 = a * soul'

for y in range(10):
	for o in range(1, 10):
		for l in range(1, 10):
			for d in range(10):
				for g in range(1, 10):
					for p in range(1, 10):
						for a in range(10):
							for s in range(1, 10):
								for m in range(1, 10):
									for u in range(10):
										str12 = str12c
										str11 = str11c
										str22 = str22c
										str21 = str21c
										str12 = str12.replace("y", str(y))
										str12 = str12.replace("o", str(o))
										str12 = str12.replace("l", str(l))
										str12 = str12.replace("d", str(d))
										str12 = str12.replace("g", str(g))
										str12 = str12.replace("p", str(p))
										str12 = str12.replace("a", str(a))
										str12 = str12.replace("s", str(s))
										str12 = str12.replace("m", str(m))
										str12 = str12.replace("u", str(u))
										print(str12)
										exec(str12)
										str11 = str11.replace("y", str(y))
										str11 = str11.replace("o", str(o))
										str11 = str11.replace("l", str(l))
										str11 = str11.replace("d", str(d))
										str11 = str11.replace("g", str(g))
										str11 = str11.replace("p", str(p))
										str11 = str11.replace("a", str(a))
										str11 = str11.replace("s", str(s))
										str11 = str11.replace("m", str(m))
										str11 = str11.replace("u", str(u))
										exec(str11)
										str22 = str22.replace("y", str(y))
										str22 = str22.replace("o", str(o))
										str22 = str22.replace("l", str(l))
										str22 = str22.replace("d", str(d))
										str22 = str22.replace("g", str(g))
										str22 = str22.replace("p", str(p))
										str22 = str22.replace("a", str(a))
										str22 = str22.replace("s", str(s))
										str22 = str22.replace("m", str(m))
										str22 = str22.replace("u", str(u))
										exec(str22)
										str21 = str21.replace("y", str(y))
										str21 = str21.replace("o", str(o))
										str21 = str21.replace("l", str(l))
										str21 = str21.replace("d", str(d))
										str21 = str21.replace("g", str(g))
										str21 = str21.replace("p", str(p))
										str21 = str21.replace("a", str(a))
										str21 = str21.replace("s", str(s))
										str21 = str21.replace("m", str(m))
										str21 = str21.replace("u", str(u))
										exec(str21)
										if(x1==x2 and c1==c2):
											print(y, o, l, d, g, p, a, s, m, u)
