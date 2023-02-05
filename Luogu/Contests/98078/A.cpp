#include <cstdio>
#include <iostream>
#include <cmath>

int main(){
	freopen("data.in", "r", stdin);

	int t, n, k, m, maxbit;
	scanf("%d", &t);
	while(t --> 0){
		scanf("%d %d %d", &n, &k, &m);
		if(k <= m){
			printf("%d ", k);
			for(int i=1; i<n; i++) printf("0 ");
			printf("\n");
			continue;
		}
		maxbit = log(m) / log(2) + 1;
		if(k > (1 << maxbit) - 1 || n == 1){
			printf("-1\n");
			continue;
		}
		printf("%d %d ", 1 << (maxbit - 1), k ^ (1 << (maxbit - 1)));
		for(int i=2; i<n; i++) printf("0 ");
		printf("\n");
	}

	return 0;
}
