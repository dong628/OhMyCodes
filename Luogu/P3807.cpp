#include <cstdio>
#include <iostream>

typedef long long lol;
const int Maxn = 2e6+5;
lol lucas(int, int, lol);
lol C(int, int, lol);
lol qpow(lol, lol, lol);
lol jc[Maxn], p;

int main(){
	freopen("data.in", "r", stdin);
	int m, n, tt;
	scanf("%d", &tt);
	jc[0] = 1;
	for(int cst=0; cst<tt; cst++){
		scanf("%d %d %lld", &n, &m, &p);
		for(int i=1; i<=n+m; i++){
			jc[i] = (jc[i-1]*i)%p;
		}
		printf("%lld\n", lucas(n, n+m, p));
	}

	return 0;
}

lol lucas(int n, int m, lol p){
	if(m==0) return 1;
	return (lucas(n/p, m/p, p) * C(n%p, m%p, p)) % p;
}

lol C(int x, int y, lol p){
	if(x>y) return 0;
	lol ans = 1;
	ans *= (jc[y] * qpow(jc[y-x], p-2, p)) % p;
	ans %= p;
	ans *= qpow(jc[x], p-2, p);
/*
	for(int i=y; i>y-x; i--){
		ans *= i;
		ans %= p;
	}
	for(int i=1; i<=x; i++){
		ans /= i;
	}
*/
	return ans%p;
}

lol qpow(lol a, lol b, lol p){
	lol ans = 1, base = a;
	while(b){
		if(b&1){
			ans *= base;
			ans %= p;
		}
		base *= base;
		base %= p;
		b >>= 1;
	}
	return ans;
}
