#include <cstdio>
#include <iostream>

typedef long long lol;
const int Mod = 1e9+7, Maxr = 1e5+5;
int t;
lol ans, fm[Maxr], r, k;
lol qpow(lol, lol, lol);
lol f(lol);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int cst=0; cst<t; cst++){
		ans = 0;
		scanf("%lld %lld", &r, &k);
		for(int i=0; i<=r; i++){
			ans += qpow(f(i), k, Mod);
			ans %= Mod;
		}
		printf("%lld\n", ans);
	}

	return 0;
}

lol f(lol x){
	if(fm[x]) return fm[x];
	if(x==0) return 0;
	if(x==1) return 1;
	if(x&1){
		fm[x] = (2*f((x-1)/2)+2*f((x-1)/2)/(x-1)+x) % Mod;
		return fm[x];
	}
	fm[x] = 2*f(x/2);
	return fm[x];
}

lol qpow(lol a, lol b, lol mod){
	lol ans=1, base=a;
	while(b){
		if(b&1) ans *= base;
		ans %= mod;
		base *= base;
		base %= mod;
		b >>= 1;
	}
	return ans;
}
