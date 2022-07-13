#include <cstdio>
#include <iostream>

const int Maxn = 105, Mod = 1e9+7;
struct Matrix{
	int n;
	long long val[Maxn][Maxn] = {0};
}a, anss, ii;
typedef long long lol;
lol k;
Matrix qpow(Matrix, lol);

Matrix operator*(const Matrix&x, const Matrix&y){
	Matrix ans; ans.n = x.n;
	int tmp;
	for(int i=0; i<x.n; i++){
		for(int j=0; j<x.n; j++){
			tmp = 0;
			for(int k=0; k<x.n; k++){
				tmp += (x.val[i][k]*y.val[k][j])%Mod;
				tmp %= Mod;
			}
			ans.val[i][j] = tmp;
		}
	}
	return ans;
}

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %lld", &a.n, &k);
	for(int i=0; i<a.n; i++){
		for(int j=0; j<a.n; j++){
			scanf("%d", &a.val[i][j]);
		}
	}
	ii.n = a.n;
	for(int i=0; i<a.n; i++){
		ii.val[i][i] = 1;
	}
	anss = qpow(a, k);
	for(int i=0; i<anss.n; i++){
		for(int j=0; j<anss.n; j++){
			printf("%lld ", anss.val[i][j]);
		}
		printf("\n");
	}

	return 0;
}

Matrix qpow(Matrix x, lol b){
	Matrix base = x, ans = ii;
	while(b){
		if(b & 1){
			ans = ans * base;
		}
		base = base * base;
		b >>= 1;
	}
	return ans;
}
