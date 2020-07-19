#include <iostream>
#include <cstdio>
#define llo long long
using namespace std;

void mul(llo a, llo b, llo p){
	llo base=a, ans=0;
	while(b){
		if(b&1){
			ans += base;
			ans %= p;
		}
		base += base;
		base %= p;
		b >>= 1;
	}
	printf("%lld", ans);
}

int main(){
	llo a, b, p;
	scanf("%lld %lld %lld", &a, &b, &p);
	mul(a, b, p);

	return 0;
}

