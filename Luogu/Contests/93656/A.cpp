#include <cstdio>
#include <iostream>
#include <cmath>
#define int long long

const int Mod = 998244353, Dta = 54;
long long fab1, fxy1, fab2, fxy2, fabi, fxyi;

long long qpow(long long a, long long b){
	long long base = a%Mod, ans = 1;
	while(b){
		if(b & 1) { ans *= base; ans %= Mod; }
		base *= base;
		base %= Mod;
		b >>= 1;
	}
	return ans;
}

signed main(){
	freopen("data.in", "r", stdin);

	int t;
	long long n, a, b, x, y, ans = 1;

	scanf("%lld", &t);
	while(t-->0){
		ans = 1;
		scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &x, &y);
		fxy1 = x; fxy2 = y;
		fab1 = a; fab2 = b;
		ans *= fxy1 - fab1;
		ans %= Mod;
		if(n == 1){
			ans += Mod; ans %= Mod;
			printf("%lld\n", ans);
			continue;
		}
		ans *= fxy2 - fab2;
		ans %= Mod;
		if(n == 2){
			ans += Mod; ans %= Mod;
			printf("%lld\n", ans);
			continue;
		}
		for(int i=3; i<=std::min(n, (long long)(Dta+(n%2))); i++){
			fxyi = sqrtl((long double)(fxy1*fxy2)) + 1;
			fabi = sqrtl((long double)(fab1*fab2)) + 1;
			ans *= fxyi - fabi;
			ans %= Mod;
			fxy1 = fxy2; fxy2 = fxyi;
			fab1 = fab2; fab2 = fabi;
		}
		if(n > Dta+(n%2)){
			ans *= qpow(fxy2 - fab2, (n - (Dta+(n%2)))/2);
			ans %= Mod;
			ans *= qpow(fxy1 - fab1, (n - (Dta+(n%2)))/2);
			ans %= Mod;
		}
		ans += Mod; ans %= Mod;
		printf("%lld\n", ans);
	}

	return 0;
}
