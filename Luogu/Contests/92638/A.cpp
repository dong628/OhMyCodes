#include <cstdio>
#include <iostream>

long long abs(long long x){
	return x<0?-x:x;
}

int main(){
	long long a, b;
	scanf("%lld %lld", &a, &b);
	if(b<0){
		printf("%lld", -abs(a));
	}
	else{
		printf("%lld", abs(a));
	}

	return 0;
}
