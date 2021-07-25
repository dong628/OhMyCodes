#include <cstdio>
#include <iostream>

const int Maxn=1e3+5;
int n, a, c, summ[Maxn][Maxn], maxs=-0x7fffffff, s, maxx, maxy, m, xt, yt;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &n, &m, &c);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d", &a);
			summ[i][j]=summ[i-1][j]+summ[i][j-1]-summ[i-1][j-1]+a;
		}
	}

	for(int xo=1; xo<=n-c+1; xo++){
		for(int yo=1; yo<=m-c+1; yo++){
			xt=xo+c-1; yt=yo+c-1;
			s=summ[xt][yt]-summ[xo-1][yt]-summ[xt][yo-1]+summ[xo-1][yo-1];
			if(maxs<s){
				maxs=s;
				maxx=xo;
				maxy=yo;
			}
		}
	}

	printf("%d %d", maxx, maxy);

	return 0;
}
