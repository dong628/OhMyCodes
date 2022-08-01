#include <cstdio>
#include <iostream>
#include <cstring>
#define int long long

const int Maxn = 105, Maxm = 2e3+5, Mod = 998244353;
int n, m, a[Maxn][Maxm], fhfa[Maxn], ftot[Maxn], tot, bhf[Maxn][Maxn*2], bhfs, ans;

signed main(){
	freopen("data.in", "r", stdin);

	scanf("%lld %lld", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%lld", &a[i][j]);
			fhfa[i] += a[i][j];
			fhfa[i] %= Mod;
		}
	}

	ftot[0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=n; j>=1; j--){
			ftot[j] = ftot[j] + ftot[j-1]*fhfa[i];
			ftot[j] %= Mod;
		}
	}
	for(int i=1; i<=n; i++){
		tot += ftot[i];
		tot %= Mod;
	}

	for(int k=1; k<=m; k++){
		memset(bhf, 0, sizeof(bhf));
		bhf[0][n] = 1;
		for(int i=1; i<=n; i++){
			for(int j=n-i; j<=n+i; j++){
				bhf[i][j] = bhf[i-1][j] + bhf[i-1][j-1]*a[i][k] + bhf[i-1][j+1]*(fhfa[i]-a[i][k]);
				bhf[i][j] %= Mod;
			}
		}
		for(int i=1; i<=n; i++){
			bhfs += bhf[n][i+n];
			bhfs %= Mod;
		}
	}
	ans = tot - bhfs;
	ans %= Mod; ans += Mod; ans %= Mod;
	printf("%lld", ans);

	return 0;
}
