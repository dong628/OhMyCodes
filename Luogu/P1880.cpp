#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn = 205;
int n, a[Maxn], s[Maxn], maxx[Maxn][Maxn], minn[Maxn][Maxn], ansx, ansn=0x7fffffff;
int min(int xx, int yy) { return xx<yy?xx:yy; }
int max(int xx, int yy) { return xx>yy?xx:yy; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		a[i+n] = a[i];
	}
	n*=2;
	for(int i=1; i<=n; i++){
		s[i] = s[i-1]+a[i];
	}
	memset(minn, 0x3f, sizeof(minn));
	for(int i=1; i<=n; i++){
		minn[i][i] = 0;
	}
	for(int l=1; l<=(n>>1)-1; l++){
		for(int i=1; i<=n-l; i++){
			for(int k=i; k<=i+l-1 && k<=n-1; k++){
				maxx[i][i+l] = max(maxx[i][i+l], maxx[i][k]+maxx[k+1][i+l]+s[i+l]-s[i-1]);
				minn[i][i+l] = min(minn[i][i+l], minn[i][k]+minn[k+1][i+l]+s[i+l]-s[i-1]);
			}
		}
	}
	for(int i=1; i<=(n>>1); i++){
		ansx = ansx>maxx[i][i+(n>>1)-1]?ansx:maxx[i][i+(n>>1)-1];
		ansn = ansn<minn[i][i+(n>>1)-1]?ansn:minn[i][i+(n>>1)-1];
	}
	printf("%d\n%d", ansn, ansx);

	return 0;
}
