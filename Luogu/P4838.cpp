#include <cstdio>
#include <iostream>

typedef long long lol;
lol Mod = 19260817;
lol n;
lol mul(lol, lol, lol);
struct Matrix{
	lol n, m, val[4][4]={0};
	Matrix operator * (Matrix b){
		Matrix ans; ans.n = this->n; ans.m = b.m;
		for(int i=0; i<this->n; i++){
			for(int j=0; j<b.m; j++){
				for(int k=0; k<this->m; k++){
					ans.val[i][j] += (this->val[i][k]*b.val[k][j])%Mod;
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
} xx, aans;
Matrix qpow(Matrix, lol);

int main(){
	freopen("data.in", "r", stdin);

	int t;
	scanf("%d", &t);
	for(int cst=0; cst<t; cst++){
		scanf("%lld", &n);
		Matrix base;
		xx.n = 4; xx.m = 1;
		base.n = 4; base.m = 4;
		xx.val[0][0] = 1; xx.val[1][0] = 1; xx.val[2][0] = 1; xx.val[3][0] = 1; 
		base.val[0][0] = 1; base.val[0][2] = 1; base.val[1][0] = 1; base.val[1][2] = 1; base.val[2][1] = 1; base.val[2][3] = 1; base.val[3][1] = 1; 

		if(n==1){
			printf("2\n");
			continue;
		}
		base = base ^ (n-2);
		aans = base * xx;
		printf("%lld\n", (aans.val[0][0]+aans.val[1][0]+aans.val[2][0]+aans.val[3][0])%Mod);
	}

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
