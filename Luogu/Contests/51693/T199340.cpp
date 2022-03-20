#include <cstdio>
#include <iostream>

int n;

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	scanf("%d", &n);
	printf("1 2\n");
	printf("2 3\n");
	printf("3 4\n");
	printf("4 5\n");
	printf("5 6\n");
	printf("1 7\n");
	printf("7 8\n");
	printf("8 9\n");

	for(int i=10; i<=n; i++){
		if((i&1)==0){
			printf("1 %d\n", i);
		}
		else{
			printf("%d %d\n", i-1, i);
		}
	}

	return 0;
}
