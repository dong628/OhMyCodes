#include <cstdio>
#include <iostream>
#include <cmath>

int ans, a, b, bi, len;

int main(){
	scanf("%d %d", &a, &b);
	bi=log(a)/log(2);
	if((1<<bi)<a) bi++;
	len=log(b-(1<<bi)+1)/log(2);
	if(len==1 || (1<<bi)>=b) {
		for(int i=a; i<=b; i++) ans = ans^i;
	}
	else{
		for(int i=a; i<(1<<bi); i++){
			ans = ans^i;
		}
		for(int i=(1<<bi)+(1<<len); i<=b; i++){
			ans = ans^i;
		}
	}
	printf("%d", ans);
	
	return 0;
}
