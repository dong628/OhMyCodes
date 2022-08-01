#include <cstdio>
#include <iostream>
#include <cstring>
using std::max;

const int Maxt = 105, Maxn = 105, Maxg = 1e4+5;
int t, n, m;
int p[Maxt][Maxn], f[Maxg], tmp, maxx;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &t, &n, &m);
	for(int i=1; i<=t; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", &p[i][j]);
		}
	}
	maxx = m;
	for(int i=1; i<=t-1; i++){
		memset(f, 0, sizeof(f));
		f[maxx] = maxx;
		for(int j=1; j<=n; j++){
			for(int k=maxx; k>=p[i][j]; k--){
				f[k-p[i][j]] = max(f[k-p[i][j]], f[k]+p[i+1][j]-p[i][j]);
			}
		}
		tmp = 0;
		for(int j=0; j<=maxx; j++){
			tmp = tmp>f[j]?tmp:f[j];
		}
		maxx = tmp;
	}
	printf("%d", maxx);

	return 0;
}
