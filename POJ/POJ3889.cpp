#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define ull unsigned long long
using namespace std;

int t, n;
ull l, h, o, xc, yc;
struct Point{
	ull x;
	ull y;
}p, p1;

Point calc(int, ull);

int main(){
//	freopen("my.out", "w", stdout);
//	freopen("data.in", "r", stdin);
	scanf("%d", &t);
	for(int x=0; x<t; x++){
		scanf("%d %llu %llu", &n, &h, &o);
		Point a=calc(n, h-1);
		Point b=calc(n, o-1);
		xc=a.x-b.x; yc=a.y-b.y;
		printf("%.0f\n", double(sqrt(xc*xc+yc*yc))*10);
//		printf("%llu\n", l);
	}

	return 0;
}

Point calc(int level, ull nu){
	if(level==0){
/*		switch(nu){
			case 0 : p.x=0; p.y=0; break; 
			case 1 : p.x=0; p.y=1; break; 
			case 2 : p.x=1; p.y=1; break; 
			case 3 : p.x=1; p.y=0; break; 
		}; */
		p.x=0; p.y=0;
		return p;
	}
	else{
		ull pre=(ull)(pow(4,level-1));
		p=calc(level-1, nu%pre);
		if(nu/pre == 0) { p1.x=p.y; p1.y=p.x; }
		if(nu/pre == 1) { p1.x=p.x; p1.y=p.y+pow(2,level-1); }
		if(nu/pre == 2) { p1.x=p.x+pow(2,level-1); p1.y=p.y+pow(2,level-1); }
		if(nu/pre == 3) { p1.x=pow(2,level)-p.y-1; p1.y=pow(2,level-1)-p.x-1; }
		return p1;
	}
}
