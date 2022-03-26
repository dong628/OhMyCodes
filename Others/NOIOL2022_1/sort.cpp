#include <cstdio>
#include <iostream>

const int Maxn = 1e4+5, Inf = 0x3f3f3f3f;
int m, n, a[Maxn][Maxn], minn, maxx;
long long ans;

int main(){
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);

	scanf("%d %d", &m, &n);
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			maxx = 0; minn = Inf;
			for(int k=1; k<=m; k++){
				maxx = maxx>a[k][i]+a[k][j]?maxx:a[k][i]+a[k][j];
				minn = minn<a[k][i]+a[k][j]?minn:a[k][i]+a[k][j];
			}
			ans += maxx+minn;
		}
	}

	printf("%lld", ans);

	return 0;
}
