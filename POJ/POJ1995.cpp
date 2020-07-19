#include <iostream>
#include <cstdio>
#define ull long long
using namespace std;

ull qpow(ull a, ull b, ull m){
	ull base=a, ans=1;
	while(b){
		if(b&1){
			ans *= base;
			ans %= m;
		}
		base *= base;
		base %= m;
		b >>= 1;
	}
	return ans;
}

int main(){
	freopen("data.in", "r", stdin);
	ull z, m, a, b, h, sum;
	scanf("%lld", &z);
	for(int x=0; x<z; x++){
		sum = 0;
		scanf("%lld", &m); scanf("%lld", &h);
		for(int i=0; i<h; i++){
			scanf("%lld %lld", &a, &b);
			sum += qpow(a, b, m);
			sum %= m;
		}
		printf("%lld\n", sum);
	}

	return 0;
}
