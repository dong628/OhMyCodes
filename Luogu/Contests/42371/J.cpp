#include <cstdio>
#include <iostream>

const int Max=3e5+5;
int n, a[Max];

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n/2; i+=2){
		printf("%d ", a[i]);
	}
	for(int i=1; i<n; i+=2){
		printf("%d ", a[i]);
	}
	for(int i=n/2; i<n; i+=2){
		printf("%d ", a[i]);
	}

	return 0;
}
