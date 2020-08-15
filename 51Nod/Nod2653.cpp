#include <cstdio>
#include <iostream>
#include <cmath>

int ans, a, b, bi, len;

int main(){
	scanf("%d %d", &a, &b);
	bi=log(a)/log(2);
	if(bi*bi<a) bi++;
	len=log(b-bi)/log(2);
	for(int i=a; i<bi*bi; i++){
		ans = ans^i;
	}
	for(int i=bi*bi+len*len; i<=b; i++){
		ans = ans^i;
	}
	printf("%d", ans);
	
	return 0;
}
