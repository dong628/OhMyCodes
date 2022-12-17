#include <cstdio>
#include <iostream>
using std::max;

const int Maxn = 505, Mod = 1e9+7;
char s[Maxn];
int n, k;
bool vis[Maxn][Maxn][10];
long long f[Maxn][Maxn][10];
long long dp(int l, int r, int tp);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d\n", &n, &k);

	for(int i=1; i<=n; i++){
		s[i] = getchar();
	}

	printf("%lld", dp(1, n, 3));

	return 0;
}

long long dp(int l, int r, int tp){
	if(l == r){
		if((tp == 0 || tp == 5) && (s[l] == '*' || s[l] == '?')) return 1;
		else return 0;
	}
	if(vis[l][r][tp]) return f[l][r][tp];
	if(tp == 0){
		if(r - l + 1 > k) f[l][r][tp] = 0;
		else f[l][r][tp] = dp(l, r-1, tp) * (s[r] == '*' || s[r] == '?');
	}
	else if(tp == 1){
		if((s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?')){
			if(r == l+1) f[l][r][tp] = 1;
			else{
				f[l][r][tp] += dp(l+1, r-1, 0);
				f[l][r][tp] += dp(l+1, r-1, 2);
				f[l][r][tp] += dp(l+1, r-1, 3);
				f[l][r][tp] += dp(l+1, r-1, 4);
				f[l][r][tp] %= Mod;
			}
		}
	}
	else if(tp == 2){
		for(int i=l+1; i<=r; i++){
			f[l][r][tp] += dp(l, i-1, 3) * dp(i, r, 0);
			f[l][r][tp] %= Mod;
		}
	}
	else if(tp == 3){
		for(int i=l+1; i<=r; i++){
			f[l][r][tp] += dp(l, i-1, 2) * dp(i, r, 1);
			f[l][r][tp] += dp(l, i-1, 3) * dp(i, r, 1);
			f[l][r][tp] %= Mod;
		}
		f[l][r][tp] += dp(l, r, 1);
		f[l][r][tp] %= Mod;
	}
	else if(tp == 4){
		for(int i=l+1; i<=r; i++){
			f[l][r][tp] += dp(l, i-1, 4) * dp(i, r, 1);
			f[l][r][tp] += dp(l, i-1, 5) * dp(i, r, 1);
			f[l][r][tp] %= Mod;
		}
	}
	else{
		for(int i=l+1; i<=r; i++){
			f[l][r][tp] += dp(l, i-1, 4) * dp(i, r, 0);
			f[l][r][tp] %= Mod;
		}
		f[l][r][tp] += dp(l, r, 0);
		f[l][r][tp] %= Mod;
	}
	vis[l][r][tp] = true;
	return f[l][r][tp];
}
