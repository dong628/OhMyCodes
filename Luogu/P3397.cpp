#include <cstdio>
#include <iostream>

const int Maxn=1e3+5;
int n, m, xo, yo, xt, yt, xf[Maxn][Maxn], mapp[Maxn][Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%d %d %d %d", &xo, &yo, &xt, &yt);
		xf[xo][yo]++;
		xf[xt+1][yt+1]++;
		xf[xt+1][yo]--;
		xf[xo][yt+1]--;

	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			mapp[i][j]=mapp[i][j-1]+mapp[i-1][j]-mapp[i-1][j-1]+xf[i][j];
			printf("%d ", mapp[i][j]);
		}
		printf("\n");
	}

	return 0;
}
