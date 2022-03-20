#include <cstdio>
#include <iostream>

int n, k;

int main(){
	scanf("%d %d", &n, &k);
	if(k==1){
		printf("%d", n+1);
	}
	else{
		printf("%d", n);
	}

	return 0;
}
