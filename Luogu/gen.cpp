#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <time.h>

const int Maxadd = 1e2, Maxn = 1e2+5;
int n, m, r, p, mode, x, y;
int q, ai, l;
int k, opt;
bool tmp, xh[Maxn][Maxn];

int main(){
	freopen("data.in", "w", stdout);
	
	srand(time(0));
	n = 1e6;
	printf("%d\n", n);
	for(int i=0; i<n; i++){
		printf("%d %d\n", rand()%(n/100)+1, rand()%(n/100)+1);
	}

	return 0;
}
