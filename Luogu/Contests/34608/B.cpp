#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

const int Max=1e2+5;
int n, m, a[Max][Max], b[Max][Max], minn=0x7fffffff, tmp;
void maxa(void);
int mmax(int x, int y) { return x>y?x:y; }

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			tmp=a[i][j];
			a[i][j]=0;
			maxa();
			minn=minn<b[1][1]?minn:b[1][1];
			a[i][j]=tmp;
		}
	}
	printf("%d", minn);
	

	return 0;
}

void maxa(void){
	memset(b, 0, sizeof(b));
	b[n][m]=a[n][m];
	for(int i=n-1; i>0; i--){
		b[i][m]=b[i+1][m]+a[i][m];
	}
	for(int i=m-1; i>0; i--){
		b[n][i]=b[n][i+1]+a[n][i];
	}
	for(int i=n-1; i>0; i--){
		for(int j=m-1; j>0; j--){
			b[i][j]=mmax(b[i+1][j], b[i][j+1])+a[i][j];
		}
	}
}
