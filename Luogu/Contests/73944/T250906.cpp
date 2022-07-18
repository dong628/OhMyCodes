#include <cstdio>
#include <iostream>

typedef long long lol;
const int Maxn = 1e2+5, Maxm = 1e2+5;
const lol Mod = 720000054000001;
int n[Maxn], m[Maxm], maxm, tn, tm, cnt;
lol ans[Maxm], jc[Maxm];

lol C(int, int, lol);
lol lucas(int n, int m, lol p);
lol qpow(lol a, lol b, lol p);
lol mul(lol, lol, lol);
lol mmi(lol a, lol p);
lol exgcd(lol a, lol b, lol&x, lol&y);

int main(){
	freopen("data.in", "r", stdin);

	while(scanf("%d %d", &tn, &tm) != EOF){
		maxm = tm>maxm?tm:maxm;
		m[cnt] = tm; n[cnt] = tn;
		cnt++;
	}
	jc[0] = 1;
	for(int i=1; i<=maxm; i++){
		jc[i] = (jc[i-1]*i)%Mod;
	}
	for(int i=2; i<=maxm; i++){
		if(i%2 == 0){
			ans[i] = lucas(i/2, i, Mod);
		}
	}
	for(int i=0; i<cnt; i++){
		printf("%lld\n", ans[m[i]]);
	}

	return 0;
}

lol lucas(int n, int m, lol p){
	if(m==0) return 1;
	return mul(lucas(n/p, m/p, p), C(n%p, m%p, p), p) ;
}

lol C(int x, int y, lol p){
	if(x>y) return 0;
	lol ans = 1;
	ans = mul(ans, mul(jc[y], mmi(jc[y-x], p), p), p) ;
	ans = mul(ans, mmi(jc[x], p), p);
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
			ans = mul(ans, base, p);
			ans %= p;
		}
		base = mul(base, base, p);
		base %= p;
		b >>= 1;
	}
	return ans;
}

lol mul(lol a, lol b, lol mod){
	lol anss = 0, basse = a;
	while(b){
		if(b&1) anss += basse;
		anss %= mod;
		basse += basse;
		basse %= mod;
		b >>= 1;
	}
	return anss;
}

lol mmi(lol a, lol p){
	lol ans = 1, y = 0, gcd;
	gcd = exgcd(a, p, ans, y);
//	ans /= gcd;
	ans %= p; ans += p; ans %= p;
	return ans;
}

lol exgcd(lol a, lol b, lol&x, lol&y){
	if(b == 0){
		x = 1; y = 0;
		return a;
	}
	lol gcd = exgcd(b, a%b, y, x);
	y -= a/b*x;
	return gcd;
}
