#include <iostream>
#include <cstdio>
using namespace std;

int qpow(int a, int b, int m){
	int base=a, ans=1;
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
	int z, m, a, b, h, sum;
	scanf("%d", &z);
	for(int x=0; x<z; x++){
		sum = 0;
		scanf("%d", &m); scanf("%d", &h);
		for(int i=0; i<h; i++){
			scanf("%d %d", &a, &b);
			sum += qpow(a, b, m);
			sum %= m;
		}
		printf("%d\n", sum);
	}

	return 0;
}
