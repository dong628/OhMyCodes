#include <cstdio>
#include <iostream>

const int Maxn=125;
int n, a, summ[Maxn][Maxn], maxs=-0x7fffffff, s;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", &a);
			summ[i][j]=summ[i-1][j]+summ[i][j-1]-summ[i-1][j-1]+a;
		}
	}

	for(int xo=1; xo<=n; xo++){
		for(int xt=xo; xt<=n; xt++){
			for(int yo=1; yo<=n; yo++){
				for(int yt=yo; yt<=n; yt++){
					s=summ[xt][yt]-summ[xo-1][yt]-summ[xt][yo-1]+summ[xo-1][yo-1];
					maxs=maxs>s?maxs:s;
				}
			}
		}
	}
	printf("%d", maxs);

	return 0;
}
