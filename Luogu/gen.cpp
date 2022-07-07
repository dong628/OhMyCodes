#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <time.h>

int n, m, r, p, mode, x, y;

int main(){
	freopen("data.in", "w", stdout);
	
	srand(time(0));
	n = 15; m = 30; r = 1; p = 1e9+7;
	printf("%d %d %d %d\n", n, m, r, p);
	for(int i=0; i<n; i++){
		printf("%d ", rand()%100);
	}
	printf("\n");
	for(int i=2; i<=n; i++){
		printf("%d %d\n", i, rand()%(i-1)+1);
	}
	for(int i=0; i<m; i++){
		mode = rand()%3+1;
		do{
			x = rand()%n+1; y = rand()%n+1;
		}while(x==y);
		switch(mode){
			case 1: printf("%d %d %d %d\n", mode, x, y, rand()%100); break;
			case 2: printf("%d %d %d\n", mode, x, y); break;
			case 3: printf("%d %d %d\n", mode, x, rand()%100); break;
			case 4: printf("%d %d\n", mode, x); break;
		}
	}

	return 0;
}
