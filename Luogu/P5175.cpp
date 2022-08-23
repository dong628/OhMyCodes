#include <cstdio>
#include <iostream>

typedef long long lol;
const int Maxn = 10, Mod = 1e9+7;

struct Matrix{
	lol val[Maxn][Maxn] = {0}, n, m;
	Matrix operator * (Matrix b){
		Matrix ans; ans.n = n; ans.m = b.m;
		for(int i=0; i<n; i++){
			for(int j=0; j<b.m; j++){
				for(int k=0; k<m; k++){
					ans.val[i][j] += val[i][k] * b.val[k][j];
				}
				ans.val[i][j] %= Mod;
			}
		}
		return ans;
	}
	Matrix operator ^ (lol b){
		Matrix ans, base = *this; ans.n = n; ans.m = m;
		for(int i=0; i<n; i++) ans.val[i][i] = 1;
		while(b){
			if(b & 1) ans = ans * base;
			base = base * base;
			b >>= 1;
		}
		return ans;
	}
} tr, a;

int main(){
	freopen("data.in", "r", stdin);

	int t;
	lol n, a1, a2, x, y;
	scanf("%d", &t);
	while(t--){
		for(int i=0; i<6; i++){
			for(int j=0; j<6; j++) tr.val[i][j] = 0;
		}
		scanf("%lld %lld %lld %lld %lld", &n, &a1, &a2, &x, &y);
		a.n = 6; a.m = 1;
		a.val[0][0] = a1; a.val[1][0] = a2; a.val[2][0] = a1*a1%Mod;
		a.val[3][0] = (a2*a2)%Mod; a.val[4][0] = (a1*a1+a2*a2)%Mod; a.val[5][0] = a1*a2%Mod;
		tr.n = 6; tr.m = 6;
		tr.val[0][1] = 1; tr.val[1][0] = y; tr.val[1][1] = x; tr.val[2][3] = 1;
		tr.val[3][2] = y*y%Mod; tr.val[3][3] = x*x%Mod;
		tr.val[4][2] = y*y%Mod; tr.val[4][3] = x*x%Mod;
		tr.val[4][4] = 1;
		tr.val[3][5] = 2*x*y%Mod; tr.val[4][5] = 2*x*y%Mod;
		tr.val[5][3] = x; tr.val[5][5] = y;

		if(n >= 2){
			tr = tr ^ (n-2);
			a = tr * a;
			printf("%lld\n", a.val[4][0]);
		}
		else printf("%lld\n", a1*a1%Mod);
	}

	return 0;
}
