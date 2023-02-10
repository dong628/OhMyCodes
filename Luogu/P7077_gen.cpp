#include <iostream>
#include <cstdio>
#include <random>
#include <algorithm>

const int N = 10, M = 5, Q = 5, C = 10, V = 20;
int topo[M+5], h[M+5];
typedef unsigned int uint;

int main(){
	freopen("data.in", "w", stdout);

	int seed;
	scanf("%d", &seed);
	std::mt19937 rng(seed);
	
	printf("%d\n", N);
	for(int i=1; i<=N; i++){
		printf("%d ", uint(rng())%V);
	}
	putchar('\n');

	for(int i=1; i<=M; i++) topo[i] = i;
	std::shuffle(topo+1, topo+M+1, rng);
	for(int i=1; i<=M; i++) h[topo[i]] = i;

	printf("%d\n", M);
	int type, c;
	for(int i=1; i<=M; i++){
		type = uint(rng()) % 3 + 1;
		if(h[i] == M){
			type = uint(rng()) % 2 + 1;
		}
		printf("%d ", type);
		if(type == 1){
			printf("%d %d\n", uint(rng())%N+1, uint(rng())%V);
		}
		else if(type == 2){
			printf("%d\n", uint(rng())%V);
		}
		else{
			c = uint(rng())%C+1;
			printf("%d ", c);
			for(uint j=0; j<c; j++){
				printf("%d ", topo[uint(rng())%(M-h[i])+h[i]+1]);
			}
			putchar('\n');
		}
	}

	printf("%d\n", Q);
	for(int i=1; i<=Q; i++){
		printf("%d ", uint(rng())%M+1);
	}

	return 0;
}
