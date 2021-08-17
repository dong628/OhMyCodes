#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn=1e4+5;
int a[Maxn][2], ans[Maxn][Maxn], n, m, l, r;
bool point[Maxn];

int main(){
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for(int i=1; i<n; i++){
		scanf("%d %d", &a[i][0], &a[i][1]);
	}
	for(int i=1; i<n; i++){
		memset(point, 0, sizeof(point));
		for(int j=i; j<n; j++){
			if(a[j][0]>a[j][1] && a[j][1]>=i){
				point[a[j][0]] = true;
			}
			else if(a[j][0]<a[j][1] && a[j][0]>=i){
				point[a[j][1]] = true;
			}
			if(point[j]){
				ans[i][j] = ans[i][j-1];
			}
			else{
				ans[i][j] = ans[i][j-1]+1;
			}
		}
		if(point[n]){
			ans[i][n] = ans[i][n-1];
		}
		else{
			ans[i][n] = ans[i][n-1]+1;
		}
	}
	for(int i=1; i<=m; i++){
		scanf("%d %d", &l, &r);
		if(l==r && l==n){
			printf("1\n");
		}
		else{
			printf("%d\n", ans[l][r]);
		}
	}

	return 0;
}
