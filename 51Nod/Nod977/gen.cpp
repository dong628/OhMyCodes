#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <time.h>

const int Maxadd = 1e2, Maxn = 1e2+5;
int n, m, r, p, mode, x, y;
int q, ai, l;
int k, opt, d;
bool tmp, xh[Maxn][Maxn];

int main(){
	freopen("data.in", "w", stdout);
	
	srand(time(0));
	n = 10000; m = 10000; q = 10;
	printf("%d %d %d\n", n, m, q);
	for(int i=0; i<n; i++){
		printf("%d ", rand()%10000);
	}
	printf("\n");
	for(int i=0; i<m; i++){
		opt = rand()%4+1;
		l = rand()%n+1; r = std::min(l+rand()%n, n);
		k = rand()%n; d = rand()%n;
		printf("%d ", opt);
		switch(opt){
			case 1: printf("%d %d %d %d", l, r, k, d); break;
			case 2: printf("%d %d %d", l, r, k); break;
			case 3: printf("%d %d", l, r); break;
			case 4: printf("%d %d", l, r); break;
		}
		printf("\n");
	}

	return 0;
}
