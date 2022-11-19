#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <time.h>
using std::max, std::min;

const int Maxadd = 1e2, Maxn = 1e9;

int main(){
	freopen("data.in", "w", stdout);
	int seed;
	
	scanf("%d", &seed);
	srand(seed*115);

	int n, m, l, r;
	n = 10; m = 3;
	printf("%d %d\n", n, m);
	for(int i=0; i<m; i++){
		l = rand()%n+1;
		r = rand()%n+1;
		printf("%d %d\n", min(l, r), max(l, r));
	}

	return 0;
}
