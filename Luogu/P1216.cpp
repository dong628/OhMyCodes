#include <cstdio>
#include <iostream>

const int Max=1005;
int a[Max][Max], n;
int maxx(int, int);

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i=n-1; i>0; i--){
		for(int j=1; j<=i; j++){
			a[i][j]+=maxx(a[i+1][j], a[i+1][j+1]);
		}
	}
	printf("%d", a[1][1]);

	return 0;
}

int maxx(int x, int y){
	return x>y?x:y;
}
