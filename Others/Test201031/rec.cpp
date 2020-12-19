#include <cstdio>
#include <iostream>

const int Max=255;
int n, m;
long long a, b, summ[Max][Max], su, cnt, mapp[Max][Max];

int main(){
	freopen("rec.in", "r", stdin);
	freopen("rec.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%lld", &mapp[i][j]);
		}
	}
	scanf("%lld %lld", &a, &b);
	summ[1][1]=mapp[1][1];
	for(int i=2; i<=n; i++) summ[i][1]=summ[i-1][1]+mapp[i][1];
	for(int i=2; i<=m; i++) summ[1][i]=summ[1][i-1]+mapp[1][i];
	for(int i=2; i<=n; i++){
		for(int j=2; j<=m; j++){
			summ[i][j]=mapp[i][j]+summ[i][j-1]+summ[i-1][j]-summ[i-1][j-1];
		}
	}
	for(int i1=0; i1<n; i1++){
		for(int j1=0; j1<m; j1++){
			for(int i2=i1+1; i2<=n; i2++){
				for(int j2=j1+1; j2<=m; j2++){
					su=summ[i2][j2]-summ[i2][j1]-summ[i1][j2]+summ[i1][j1];
					if(su>=a && su<=b) cnt++;
				}
			}
		}
	}
	printf("%lld", cnt);

	return 0;
}
