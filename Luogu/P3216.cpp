#include <cstdio>
#include <iostream>

const int Maxn = 5;
typedef long long lol;
int Mod;
struct Matrix{
	int n, m;
	lol val[Maxn][Maxn] = {0};
}trans, anss, ii, init, tmp;
lol n;
Matrix qpow(Matrix, lol);
lol pow(int, int);

Matrix operator*(const Matrix&x, const Matrix&y){
	Matrix ans; ans.n = x.n; ans.m = y.m;
	lol tmp;
	for(int i=0; i<x.n; i++){
		for(int j=0; j<y.m; j++){
			tmp = 0;
			for(int k=0; k<x.m; k++){
				tmp += ((x.val[i][k]%Mod)*(y.val[k][j]%Mod))%Mod;
				tmp %= Mod;
			}
			ans.val[i][j] = tmp;
		}
	}
	return ans;
}

int main(){
//	freopen("data.in", "r", stdin);

	ii.n = 3; ii.m = 3;
	anss.n = 3; anss.m = 3;
	for(int i=0; i<3; i++){
		ii.val[i][i] = 1;
		anss.val[i][i] = 1;
	}

	trans.n = 3; trans.m = 3;
	trans.val[0][1] = 1; trans.val[0][2] = 1; trans.val[1][1] = 1; trans.val[1][2] = 1; trans.val[2][2] = 1;
	init.n = 3; init.m = 1;
	init.val[0][0] = 1; init.val[1][0] = 1; init.val[2][0] = 1;
	scanf("%lld %d", &n, &Mod);
//	n--;

	for(int i=1; i<=18; i++){
		if(n>=pow(10, i)){
			trans.val[0][0] = pow(10, i);
			if(i==1){
				anss = qpow(trans, pow(10, i)-pow(10, i-1)-1) * anss;
//				printf("%d %lld ", i, pow(10, i)-pow(10, i-1)-1);
			}
			else{
				anss = qpow(trans, pow(10, i)-pow(10, i-1)) *anss;
//				printf("%d %lld ", i, pow(10, i)-pow(10, i-1));
			}
			tmp = anss * init;
//			printf("%d\n", tmp.val[0][0]);
		}
		else{
			trans.val[0][0] = pow(10, i);
			n -= pow(10, i-1)-1;
			anss = qpow(trans, n)*anss;
//			printf("%d %lld\n", i, n);
			break;
		}
	}
	
	anss = anss * init;
	printf("%lld", anss.val[0][0]);

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

lol pow(int a, int b){
	lol ans = 1;
	for(int i=0; i<b; i++){
		ans *= a;
	}
	return ans;
}
