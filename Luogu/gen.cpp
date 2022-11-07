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
	int n, m, q;
	n = 1e5; m = 1e5; q = 1e5;
	printf("%d %d %d\n", n, m, q);
	for(int i=0; i<n; i++){
		printf("%d ", rand()%(2*Maxn+1)-Maxn);
	}
	printf("\n");
	for(int i=0; i<n; i++){
		printf("%d ", rand()%(2*Maxn+1)-Maxn);
	}
	int l1, r1, l2, r2;
	for(int i=0; i<q; i++){
		l1 = (rand()%n)+1;
		r1 = (rand()%n)+1;
		l2 = (rand()%m)+1;
		r2 = (rand()%m)+1;

		if(rand()%2){
			l1 = r1;
		}
		else{
			l2 = r2;
		}

		printf("%d %d %d %d\n", min(l1, r1), max(l1, r1), min(l2, r2), max(l2, r2));
	}

	return 0;
}
