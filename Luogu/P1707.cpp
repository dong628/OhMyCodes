#include <cstdio>
#include <iostream>

typedef long long lol;
lol n, p, q, r, t, u, v, w, x, y, z;
lol Mod;
lol mul(lol, lol, lol);
struct Matrix{
	lol n, m, val[11][11]={0};
	Matrix operator * (Matrix b){
		Matrix ans; ans.n = this->n; ans.m = b.m;
		for(int i=0; i<this->n; i++){
			for(int j=0; j<b.m; j++){
				for(int k=0; k<this->m; k++){
					ans.val[i][j] += mul(this->val[i][k], b.val[k][j], Mod);
					ans.val[i][j] %= Mod;
				}
			}
		}
		return ans;
	}
	Matrix operator ^ (lol b){
		Matrix ans, base = *this; ans.n = n; ans.m = m;
		for(int i=0; i<n; i++) ans.val[i][i] = 1;
		while(b){
			if(b&1){
				ans = ans * base;
			}
			base = base * base;
			b >>= 1;
		}
		return ans;
	}
} base, xx, aans;
Matrix qpow(Matrix, lol);

int main(){
	freopen("data.in", "r", stdin);

	xx.n = 11; xx.m = 1;
	base.n = 11; base.m = 11;

	scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &n, &Mod, &p, &q, &r, &t, &u, &v, &w, &x, &y, &z);

	base.val[0][1] = 1; base.val[1][3] = 1; base.val[1][5] = 1; base.val[1][10] = 1;
	base.val[2][3] = 1; base.val[3][1] = 1; base.val[3][5] = 1; 
	base.val[3][6] = 1; base.val[4][5] = 1; base.val[5][1] = 1; base.val[5][3] = 1;
	base.val[5][7] = 1; base.val[5][8] = 1; base.val[5][10] = 2; 
	base.val[8][8] = 1; base.val[9][8] = 2; base.val[9][9] = 1; base.val[9][10] = 1; base.val[10][10] = 1;
	base.val[1][0] = q; base.val[1][1] = p; base.val[1][8] = t; base.val[1][9] = r; base.val[3][2] = v; base.val[3][3] = u;
	base.val[5][4] = y; base.val[5][5] = x; base.val[6][6] = w; base.val[7][7] = z; base.val[8][10] = 1;
	xx.val[0][0] = 1; xx.val[1][0] = 3; xx.val[2][0] = 1; xx.val[3][0] = 3; xx.val[4][0] = 1; xx.val[5][0] = 3;
	xx.val[6][0] = w; xx.val[7][0] = z; xx.val[8][0] = 1; xx.val[9][0] = 1; xx.val[10][0] = 1;
/*
	for(int i=0; i<11; i++){
		for(int j=0; j<11; j++){
			printf("%lld ", base.val[i][j]);
		}
		printf("\n");
	}
*/
	base = base ^ (n-1);
	aans = base * xx;
	printf("nodgd %lld\n", aans.val[0][0]%Mod);
	printf("Ciocio %lld\n", aans.val[2][0]%Mod);
	printf("Nicole %lld\n", aans.val[4][0]%Mod);

	return 0;
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
