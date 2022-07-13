#include <cstdio>
#include <iostream>

const int Maxn = 105, Mod = 1e9+7;
typedef long long lol;
struct Matrix{
	int n, m;
	lol val[Maxn][Maxn] = {0};
}trans, anss, ii, init;
lol k;
int n, t;
Matrix qpow(Matrix, int);

Matrix operator*(const Matrix&x, const Matrix&y){
	Matrix ans; ans.n = x.n; ans.m = y.m;
	int tmp;
	for(int i=0; i<x.n; i++){
		for(int j=0; j<y.m; j++){
			tmp = 0;
			for(int k=0; k<x.m; k++){
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

	ii.n = 3; ii.m = 3;
	for(int i=0; i<3; i++) ii.val[i][i] = 1;

	trans.n = 3; trans.m = 3;
	trans.val[0][0] = 1; trans.val[0][2] = 1; trans.val[1][0] = 1; trans.val[2][1] = 1;
	init.n = 3; init.m = 1;
	init.val[0][0] = 1; init.val[1][0] = 1; init.val[2][0] = 1;
	scanf("%d", &t);
	for(int cst = 0; cst < t; cst++){
		scanf("%d", &n);
		anss = qpow(trans, n-1);
		anss = anss * init;
		printf("%lld\n", anss.val[2][0]);
	}

	return 0;
}

Matrix qpow(Matrix x, int b){
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
