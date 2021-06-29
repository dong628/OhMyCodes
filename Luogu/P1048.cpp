#include <cstdio>
#include <iostream>
using std::max;

const int Maxm=105, Maxt=1005;
int t, m, v[Maxm], c[Maxm], a[Maxm][Maxt], maxx;

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d %d", &t, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d", &c[i], &v[i]);
	}
	for(int i=0; i<=t; i++){
		a[0][i]=0;
	}
	for(int i=1; i<=m; i++){
		for(int j=0; j<c[i]; j++){
			a[i][j]=a[i-1][j];
		}
		for(int j=c[i]; j<=t; j++){
			a[i][j]=max(a[i-1][j], a[i-1][j-c[i]]+v[i]);
		}
	}
	for(int i=0; i<=t; i++){
		maxx=maxx>a[m][i]?maxx:a[m][i];
	}
	printf("%d", maxx);

	return 0;
}
