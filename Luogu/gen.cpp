#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <time.h>

const int Maxadd = 1e3;
int n, m, r, p, mode, x, y;
int q, ai, l;
int k, opt;

int main(){
	freopen("data.in", "w", stdout);
	
	srand(time(0));
	n = 1e5; q = 1e5;
	printf("%d %d\n", n, q);
	for(int i=0; i<n; i++){
		ai = rand()%500;
		printf("%d ", ai);
	}
	printf("\n");
	for(int i=0; i<q; i++){
		opt = rand()%2+1;
		l = rand()%n+1;
		r = rand()%n+1;
		if(opt == 1) k = rand()%(r-l+1);
		else k = rand()%Maxadd;
		if(l>r) std::swap(l, r);
		printf("%d %d %d %d\n", opt, l, r, k);
	}

	return 0;
}
