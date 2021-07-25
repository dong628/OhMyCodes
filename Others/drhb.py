import requests as r
import time

url = 'https://www.luogu.com.cn/paintBoard/paint'
headers = {'cookie':'UM_distinctid=17604f1e0a5899-04447031f97d6c-10201b0b-144000-17604f1e0a6c33; __client_id=c560a3693966c704531f4f4d235245966044fd74; _uid=161876; CNZZDATA5476811=cnzz_eid%3D1202225481-1590275550-%26ntime%3D1609627432', 'user-agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.88 Safari/537.36'}

f = open("pic.txt", 'r');
fs = f.read();
a = fs.split()
print(a);

csx=400
csy=200

for i in range(50):
	for j in range(40):
		val=int(a[i*40+j]);
		data={'x':csx+j, 'y':csy+i, 'color':val};
		res = r.post(url, headers=headers, data=data)
		print(csx+j, csy+i, val)
		print(res.raw);
		time.sleep(30.5);

