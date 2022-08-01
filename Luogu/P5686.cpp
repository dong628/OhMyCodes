#include <cstdio>
#include <iostream>

const int Maxn = 5e5+5, Mod = 1e9+7;
int n;
long long a[Maxn], b[Maxn], asum[Maxn], bsum[Maxn], ans, tmp, mod, ass, bss;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
		asum[i] = a[i]+asum[i-1];
		asum[i] %= Mod;
	}
	for(int i=1; i<=n; i++){
		scanf("%lld", &b[i]);
		bsum[i] = b[i]+bsum[i-1];
		bsum[i] %= Mod;
	}
	for(int i=1; i<=n; i++){
		ans += asum[i]*bsum[i];
		ans %= Mod;
	}
	ans *= n+1; ans %= Mod;
	for(int i=1; i<=n; i++){
		ass += asum[i]; ass %= Mod;
		bss += bsum[i]; bss %= Mod;
	}
	ans -= (ass*bss)%Mod;
	ans %= Mod; ans += Mod; ans %= Mod;
	printf("%lld", ans);

	return 0;
}
