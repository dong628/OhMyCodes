#include <cstdio>
#include <iostream>

int lucas(int, int, int);
int C(int, int, int);

int main(){
	int m, n, p;
	scanf("%d", &t);
	for(int cst=0; cst<t; cst++){
		scanf("%d %d %d", &n, &m, &p);
		printf("%d", lucas(n, n+m, p));
	}

	return 0;
}

int lucas(int n, int m, int p){
	if(m==0) return 1;
	return lucas(m)
}

int C(int x, int y, int mod){
	for(int i=y; i>y-x; i--){
		ans *= i;
		ans %= p;
	}
	for(int i=1; i<=x; i++){
		ans /= i;
	}
	return ans%p;
}
