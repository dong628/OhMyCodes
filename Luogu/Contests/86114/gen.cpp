#include <cstdio>
#include <iostream>
using std::min, std::max;

int main(){
	freopen("data.in", "w", stdout);
	
	srand(time(0));
	int n = 2e5, m = 1e5, k = 2e5, a, b, opt;
	printf("%d %d %d\n", n, m, k);
	for(int i=0; i<n; i++){
		a = rand()%(k+1);
		b = rand()%(k+1);
		printf("%d %d\n", min(a, b), max(a, b));
	}
	for(int i=0; i<m; i++){
		opt = rand()%3;
		a = rand()%(k+1);
		b = rand()%(k+1);
		printf("%d %d %d\n", opt, min(a, b), max(a, b));
	}

	return 0;
}
