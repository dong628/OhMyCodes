#include <cstdio>
#include <iostream>
#define int long long

const int Maxn = 100005, Mod = 19260817;
int a[Maxn];

signed main(){
	freopen("data.in", "r", stdin);

	int n, m, l, r, k, d, gd, fib1, fib2, ans, op, tmp;

	scanf("%lld %lld %lld", &n, &m, &gd);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	while(m--){
		scanf("%lld", &op);
		if(op==1){
			scanf("%lld %lld %lld %lld", &l, &r, &k, &d);
			for(int i=l; i<=r; i++){
				a[i] += k;
				k += d;
				a[i] %= Mod; k %= Mod;
			}
		}
		if(op==2){
			scanf("%lld %lld %lld", &l, &r, &k);
			for(int i=l; i<=r; i++){
				a[i] += k;
				k *= gd;
				a[i] %= Mod; k %= Mod;
			}
		}
		if(op==3){
			scanf("%lld %lld", &l, &r);
			fib1 = 0; fib2 = 1;
			for(int i=l; i<=r; i++){
				a[i] += fib2;
				tmp = fib1; fib1 = fib2; fib2 += tmp;
				a[i] %= Mod; fib2 %= Mod;
			}
		}
		if(op==4){
			ans = 0;
			scanf("%lld %lld", &l, &r);
			for(int i=l; i<=r; i++){
				ans += a[i];
				ans %= Mod;
			}
			printf("%lld\n", ans);
		}
	}

	return 0;
}
