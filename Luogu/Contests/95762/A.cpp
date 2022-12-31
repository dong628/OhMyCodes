#include <cstdio>
#include <iostream>
#include <cmath>

int main(){
	int n, t;

	scanf("%d", &t);
	while(t --> 0){
		scanf("%d", &n);
		if(!(n & 1)) printf("-1\n");
		else printf("%d\n", int(log(n)/log(2))+1);
	}

	return 0;
}
