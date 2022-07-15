#include <cstdio>
#include <iostream>

typedef long long lol;
lol n, m;
const int Mod = 1e9+7;
lol mul(lol, lol, lol);
struct Matrix{
	lol n, m, val[2][2]={0};
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
} base, x, aans;
Matrix qpow(Matrix, lol);



int main(){
	freopen("data.in", "r", stdin);

	x.n = 2; x.m = 1; x.val[1][0] = 1; x.val[2][0] = 0;
	base.n = 2; base.m = 2;
	base.val[0][0] = 1;
	base.val[0][1] = 1;
	base.val[1][0] = 1;

	scanf("%lld", &n);

	base = base ^ n;
	aans = base * x;
	printf("%lld", aans.val[0][0]%Mod);

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
