#include <cstdio>
#include <iostream>

typedef long long lol;
lol Mod, n, m;
lol mul(lol, lol, lol);
struct Matrix{
	lol n, m, val[2][2]={0};
} base, x, aans;
Matrix qpow(Matrix, lol);

Matrix operator*(const Matrix&x, const Matrix&y){
        Matrix ans; ans.n = x.n; ans.m = y.m;
        for(int i=0; i<x.n; i++){
                for(int j=0; j<y.m; j++){
                        for(int k=0; k<x.m; k++){
                                ans.val[i][j] += mul((x.val[i][k]%Mod), (y.val[k][j]%Mod), Mod);
                                ans.val[i][j] %= Mod;
                        }
                }
        }
        return ans;
}


int main(){
	freopen("data.in", "r", stdin);

	x.n = 2; x.m = 1; x.val[1][0] = 1;
	base.n = 2; base.m = 2; base.val[1][1] = 1;

	scanf("%lld %lld %lld %lld %lld %lld", &Mod, &base.val[0][0], &base.val[0][1], &x.val[0][0], &n, &m);
	base = qpow(base, n);
	aans = base * x;
	printf("%lld", aans.val[0][0]%m);

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

Matrix qpow(Matrix a, lol b){
	Matrix ans, base = a; ans.n = a.n; ans.m = a.m;
	for(int i=0; i<a.n; i++) ans.val[i][i] = 1;
	while(b){
		if(b&1){
			ans = ans * base;
		}
		base = base * base;
		b >>= 1;
	}
	return ans;
}

