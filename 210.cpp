#include <cstdio>
#include <iostream>

const int Maxn = 205;
int a[Maxn][Maxn];

int main(){
	freopen("data.in", "r", stdin);

	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int minn = 0x3f3f3f3f;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			if(j*(i-j+1)<=k){
				minn = minn<a[i][j]?minn:a[i][j];
			}
		}
	}
	printf("%d", minn);

	return 0;
}
