#include <iostream>
#include <cstdio>

int n = 7, m = 8;

int main(){
	freopen("data.in", "w", stdout);

	int seed;
	scanf("%d", &seed);
	srand(seed);
	printf("%d\n", n);
	for(int i=2; i<=n; i++){
		printf("%d %d %d\n", (rand()%(i-1))+1, i, rand()%10);
	}
	int opt, a, b;
	for(int i=1; i<=m; i++){
		opt = rand()%4;
		if(opt == 0){
			printf("Change %d %d\n", rand()%(n-1)+1, rand()%10);
		}
		else if(opt == 1){
			printf("Cover %d %d %d\n", rand()%n+1, rand()%n+1, rand()%10);
		}
		else if(opt == 2){
			printf("Add %d %d %d\n", rand()%n+1, rand()%n+1, rand()%10);
		}
		else{
			do{
				a = rand()%n+1; b = rand()%n+1;
			}while(a == b);
			printf("Max %d %d\n", a, b);
		}
	}
	printf("Stop");

	return 0;
}
