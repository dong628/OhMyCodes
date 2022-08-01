#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <time.h>

int n, m, r, p, mode, x, y;
int q, ai, l;

int main(){
	freopen("data.in", "w", stdout);
	
	srand(time(0));
	n = 20; q = 20;
	printf("%d %d\n", n, q);
	for(int i=1; i<n; i++){
		ai = rand()%500;
		printf("%d ", ai);
	}
	ai = rand()%500;
	printf("%d\n", ai);
	for(int i=0; i<q; i++){
		m = rand()%2;
		l = rand()%n+1;
		r = rand()%(n-l)+l+1;
		x = rand()%200;
		if(m) printf("M %d %d %d\n", l, r, x);
		else printf("A %d %d %d\n", l, r, x);
	}

	return 0;
}
