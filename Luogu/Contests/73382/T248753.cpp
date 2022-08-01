#include <cstdio>
#include <iostream>

const int Max = 10000;
int qpow(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	int s, t, n, d;
	bool flag;

	scanf("%d\n", &s);
	scanf("%d\n", &t);
	while(t--){
		flag = false;
		scanf("%d %d\n", &n, &d);
		d = d%n;
		for(int i=1; i<Max; i++){
			if(qpow(i, i, n) == d){
				printf("%d\n", i);
				flag = true;
				break;
			}
		}
		if(!flag) printf("-1");
		if(t!=0) while(getchar()!='\n');
	}

	return 0;
}

int qpow(int a, int b, int mod){
	int ans = 1, base = a;
	while(b){
		if(b&1) ans *= base;
		ans %= mod;
		base *= base;
		base %= mod;
		b >>= 1;
	}
	return ans;
}
