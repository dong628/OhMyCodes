#include <cstdio>
#include <iostream>

//const int Mod = 1e9+7, Maxn = 35;
const int Mod = 1e9+7, Maxn = 25;
char s[Maxn];
int n, mk, f[Maxn][Maxn][Maxn][Maxn];

int dp(int, int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d\n", &n, &mk);

	s[0] = '0';
	for(int i=1; i<=n; i++){
		s[i] = getchar();
	}

	int ans = 0;
	for(int i=0; i<=mk; i++){
		ans += dp(n, 0, i, 0);
		ans %= Mod;
	}

	printf("%d", ans);

	return 0;
}

int dp(int i, int j, int k, int st){
	if(f[i][j][k][st] != 0) return f[i][j][k][st];
	if(i == 0){
		if(j == 0 && k == 0 && st == 0) return 1;
		else return 0;
	}
	if((s[i] == '?' || s[i] == '(') && j > 0 && k == 0 && st > 0){
		for(int dk=0; dk<=mk; dk++){
			f[i][j][k][st] += dp(i-1, j-1, dk, st-1);
		}
	}
	if((s[i] == '?' || s[i] == ')') && k == 0){
		for(int dk=0; dk<=mk; dk++){
			f[i][j][k][st] += dp(i-1, j+1, dk, st+1);
			f[i][j][k][st] += dp(i-1, j+1, dk, st);
		}
	}
	if((s[i] == '?' || s[i] == '*') && k > 0){
		if(k > 1) f[i][j][k][st] += dp(i-1, j, k-1, st);
		else f[i][j][k][st] += dp(i-1, j, k-1, st+1);
	}

	return f[i][j][k][st];
}
