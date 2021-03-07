#include <iostream>
#include <cstdio>

int main(){
	int n, k, t;
	scanf("%d", &t);
	for(int x=0; x<t; x++){
		scanf("%d %d", &n, &k);
		printf("%d\n", (n-k)+(k/2));
		for(int i=(k+1)/2; i<k; i++){
			printf("%d ", i);
		}
		for(int i=k+1; i<=n; i++){
			printf("%d ", i);
		}
		printf("\n");
	}

	return 0;
}
