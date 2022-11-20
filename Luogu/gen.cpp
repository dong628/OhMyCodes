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

	int n, m, l, r, opt, v;
	n = 10; m = 6;
	printf("%d %d\n", n, m);
	for(int i=0; i<m; i++){
		opt = rand()%3+1;
		l = rand()%n+1;
		r = rand()%n+1;
		printf("%d ", opt);
		if(opt == 1){
			v = rand()%10-5;
			printf("%d %d %d\n", min(l, r), max(l, r), v);
		}
		else{
			printf("%d %d\n", min(l, r), max(l, r));
		}
	}

	return 0;
}
