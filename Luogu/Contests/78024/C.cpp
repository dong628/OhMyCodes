#include <cstdio>
#include <iostream>

typedef long long lol;
const int Maxn = 35, Mod = 998244353;
int n, k;
lol a[Maxn], asum, water[Maxn], ans, tmp;
void dfs(int, int, lol);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
		asum += a[i];
	}
	if(k == 0){
		ans = 1;
		for(int i=1; i<=n; i++){
			ans *= a[i];
			ans %= Mod;
		}
		printf("%lld", ans);
	}
	else if(asum < n){
		printf("0");
	}
	else if(asum == n){
		printf("1");
	}
	else if(n <= 5){
		ans = 0;
		dfs(1, 0, a[1]);
		printf("%lld", ans);
	}

	return 0;
}

void dfs(int cs, int drop, lol rem){
	if(cs+drop == n || drop == k){
		if(cs == n){
			water[cs] += rem;
			tmp = 1;
			for(int i=1; i<=n; i++){
				tmp *= water[i];
				tmp %= Mod;
			}
			ans += tmp;
			ans %= Mod;
			water[cs] -= rem;
		}
		else{
			water[cs+drop] += rem;
			dfs(cs+1, 0, a[cs+1]);
			water[cs+drop] -= rem;
		}
		return;
	}
	for(int i=0; i<=rem; i++){
		water[cs+drop] += i;
		dfs(cs, drop+1, rem-i);
		water[cs+drop] -= i;
	}
}
