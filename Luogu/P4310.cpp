#include <cstdio>
#include <iostream>
#include <cmath>

const int Maxn = 1e5+5;
int n, a[Maxn], dp[Maxn], maxx, ans;
int max(int xx, int yy) { return xx>yy?xx:yy; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
//	for(int i=0; i<=log(n)/log(2); i++) dp[i] = 1;
	for(int i=1; i<=n; i++){
		maxx = 1;
		for(int j=0; j<=30; j++){
			if(a[i]&(1<<j)){
				maxx = max(maxx, dp[j]+1);
			}
		}
		for(int j=0; j<=30; j++){
			if(a[i]&(1<<j)){
				dp[j] = max(maxx, dp[j]);
			}
		}
		ans = max(maxx, ans);
	}

	printf("%d", ans);
	
	return 0;
}
