#include <cstdio>
#include <iostream>

int f[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int g[4][2]={{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
int n, t, a, fac, fan, xdelta, ydelta, x, y;
inline int abss(int xx) { return xx>0?xx:-xx; }

int main(){
	freopen("robot.in", "r", stdin);
	freopen("robot.out", "w", stdout);

	scanf("%d %d", &n, &t);
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		xdelta += a*f[fac][0];
		ydelta += a*f[fac][1];
		fac+=a; fac%=4;
	}
//	printf("%d %d %d", xdelta, ydelta, fac);
	for(int i=0; i<t; i++){
		x += xdelta*g[fan][0];
		y += ydelta*g[fan][1];
		fan+=fac; fan%=4;
	}
	printf("%d", abss(x)+abss(y));

	return 0;
}
/*
void turn(int x){
	x%=4;
	
}*/
