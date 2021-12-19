#include <cstdio>
#include <vector>
#include <iostream>
using std::vector;

const int Maxn = 305;
vector<int> mapp[Maxn];
int ans, maxx, kk, n, m, a[Maxn], dp[Maxn][Maxn], cnt[Maxn];
void dfs(int);
int max(int xx, int yy) { return xx>yy?xx:yy; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &kk, &a[i]);
		mapp[kk].push_back(i);
		cnt[kk]++;
	}
	dfs(0);
	for(int i=0; i<=m; i++) ans = max(ans, dp[i][m]);
	printf("%d", dp[0][m+1]);

	return 0;
}

void dfs(int point){
	if(cnt[point]==0){
		dp[point][0] = 0;
		for(int k=1; k<=m; k++)
			dp[point][k] = a[point];
		return;
	}
	for(int i=0; i<cnt[point]; i++){
		dfs(mapp[point][i]);
	}
	for(int i=1; i<=m; i++){
		dp[point][i] = a[point];
	}
	for(int p=0; p<cnt[point]; p++){
		for(int j=m+1; j>=1; j--){
//			maxx = 0;
			for(int k=j-1; k>=0; k--){
				dp[point][j] = max(dp[point][j], dp[point][j-k]+dp[mapp[point][p]][k]);
			}
//			dp[point][j] = maxx;
		}
	}
}
