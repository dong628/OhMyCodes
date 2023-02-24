#include <cstdio>
#include <iostream>

const int n = 1e5, q = 1e5;

int main(){
	freopen("data.in", "w", stdout);

	int seed;
	scanf("%d", &seed);
	srand(seed);
	printf("%d %d\n", n, q);
	for(int i=2; i<=n; i++){
		printf("%d %d\n", i, (rand()%(i-1))+1);
	}
	for(int i=0; i<q; i++){
		printf("%d %d\n", rand()%2, (rand()%n)+1);
	}

	return 0;
}
