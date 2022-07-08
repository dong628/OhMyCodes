#include <cstdio>
#include <iostream>

int n, a, b, c, d, x;

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		x = a+b+c+d;
		if(x==0) printf("0\n");
		else if(x<4) printf("1\n");
		else{
			printf("2\n");
		}
	}

	return 0;
}
