#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <time.h>

const int Maxadd = 1e2, Maxn = 1e2+5;
int n, m, r, p, mode, x, y;
int q, ai, l;
int k, opt;
bool tmp, xh[Maxn][Maxn];

int main(){
	freopen("data.in", "w", stdout);
	
	srand(time(0));
	n = 50; q = rand()%n;
	printf("%d %d\n", n, q);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			tmp = bool(rand()%2);
			xh[i][j] = tmp;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(xh[i][j]){
				putchar('Y');
			}
			else putchar('N');
		}
		printf("\n");
	}

	return 0;
}
