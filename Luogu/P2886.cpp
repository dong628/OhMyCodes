#include <cstdio>
#include <algorithm>
#include <iostream>

const int Maxt = 105, Inf = 0x3f3f3f3f;

struct Matrix{
	int val[Maxt][Maxt] = {0};
	int n, m;
} mat;

Matrix mul(Matrix x, Matrix y){
	Matrix ans;
	ans.n = x.n; ans.m = y.m;
	if(x.m != y.n){
		return ans;
	}
	int minn;
	for(int i=1; i<=ans.n; i++){
		for(int j=1; j<=ans.m; j++){
			minn = Inf;
			for(int k=1; k<=x.n; k++){
				minn = minn < x.val[i][k] + y.val[k][j] ? minn : x.val[i][k] + y.val[k][j];
			}
			ans.val[i][j] = minn;
		}
	}
	return ans;
}

Matrix pow(Matrix x, int y){
	Matrix ans, base = x;
	ans.n = x.n; ans.m = x.m;
	for(int i=1; i<=ans.n; i++){
		for(int j=1; j<=ans.n; j++){
			ans.val[i][j] = Inf;
		}
	}
	for(int i=1; i<=ans.n; i++) ans.val[i][i] = 0;
	while(y){
		if(y&1){
			ans = mul(ans, base);
		}
		base = mul(base, base);
		y >>= 1;
	}
	return ans;
}

const int Maxn = 2005;
int mapp[Maxn], u[Maxn], v[Maxn], w[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	int n=100, t, s, e, kn;


	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			mat.val[i][j] = Inf;
		}
	}
	scanf("%d %d %d %d", &kn, &t, &s, &e);
	mat.n = n; mat.m = n;
	int cnt = 1;
	for(int i=0; i<t; i++){
		scanf("%d %d %d", &w[i], &u[i], &v[i]);
		mapp[cnt++] = u[i];
		mapp[cnt++] = v[i];
	}
	int uu, vv;
	std::sort(mapp+1, mapp+cnt+1);
	cnt = std::unique(mapp+1, mapp+cnt+1) - (mapp+1);
	for(int i=0; i<t; i++){
		uu = std::lower_bound(mapp+1, mapp+cnt+1, u[i]) - mapp;
		vv = std::lower_bound(mapp+1, mapp+cnt+1, v[i]) - mapp;
		mat.val[uu][vv] = w[i];
		mat.val[vv][uu] = w[i];
	}
/*
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf("%d ", mat.val[i][j]);
		}
		putchar('\n');
	}
*/

	Matrix ans = pow(mat, kn);

/*
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(mat.val[i][j] == Inf) printf("X ");
			else printf("%d ", mat.val[i][j]);
		}
		putchar('\n');
	}
*/

	s = std::lower_bound(mapp+1, mapp+cnt+1, s) - mapp;
	e = std::lower_bound(mapp+1, mapp+cnt+1, e) - mapp;
	printf("%d", ans.val[s][e]);

	return 0;
}
