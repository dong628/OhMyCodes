#include <cstdio>
#include <iostream>

const int Maxn=1e4+5;
int n, a[Maxn][Maxn]; 
int medium(int, int, int);

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[0][i]);
	}
	if(n==1){
		printf("%d", a[0][1]);
		return 0;
	}
	for(int i=1; i<=(n-1)/2; i++){
		for(int j=1; j<=n-2*i; j++){
			a[i][j] = medium(a[i-1][j], a[i-1][j+1], a[i-1][j+2]);
//			printf("%d ", a[i][j]);
		}
//		printf("\n");
	}
	printf("%d", a[(n-1)/2][1]);

	return 0;
}

int medium(int a, int b, int c){
	if(a>b){
		if(b>c) return b;
		else{
			if(a>c) return c;
			else return a;
		}
	}
	else{
		if(b<c) return b;
		else{
			if(a<c) return c;
			else return a;
		}
	}
}
