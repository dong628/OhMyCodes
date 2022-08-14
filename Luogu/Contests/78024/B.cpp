#include <cstdio>
#include <iostream>

int main(){
	int n;
	scanf("%d", &n);
	if(n <= 356){
		printf("%d\n", 2*n);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				printf("%d %d %d %d %d\n", 2, i, i, j+n, j);
			}
		}
	}

	return 0;
}
