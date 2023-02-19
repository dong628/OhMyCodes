#include <cstdio>
#include <iostream>

const int Maxk = 10;
int n = 5, m = 5;

int main(){
	freopen("data.in", "w", stdout);

	int u, v, k, seed;

	scanf("%d", &seed);
	srand(seed*114);
	printf("%d\n", n);
	for(int i=2; i<=n; i++){
		u = (rand() % (i-1)) + 1;
		printf("%d %d\n", u, i);
	}
	printf("%d\n", m);
	for(int i=1; i<=m; i++){
		u = (rand() % n) + 1;
		v = (rand() % n) + 1;
		k = (rand() % Maxk) + 1;
		printf("%d %d %d\n", u, v, k);
	}

	return 0;
}
