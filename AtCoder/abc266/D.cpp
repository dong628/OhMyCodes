#include <cstdio>
#include <iostream>

const int Maxn = 1e5+5;
const long long Inf = 0x7fffffffffffffff;
int n;
long long dp[Maxn][5], mapp[Maxn][5];
int abs(int x) { return x>0?x:-x; }

int main(){
	freopen("data.in", "r", stdin);

	int t, x, maxt = 0;
	long long a;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d %lld", &t, &x, &a);
		mapp[t][x] += a;
		maxt = maxt>t?maxt:t;
	}
	dp[0][0] = mapp[0][0];
	for(int i=1; i<=maxt; i++){
		for(int j=0; j<5; j++){
//			if(i<j) dp[i][j] = -Inf;
			if(i<j) continue;
			for(int k=0; k<5; k++){
				if(i-abs(j-k)<0) continue;
				dp[i][j] = std::max(dp[i][j], dp[i-std::max(abs(j-k), 1)][k]+mapp[i][j]);
			}
//			if(i>=j) dp[i][j] += mapp[i][j];
		}
	}
	long long maxx = 0;
	for(int i=0; i<5; i++){
		maxx = maxx>dp[maxt][i]?maxx:dp[maxt][i];
	}
	printf("%lld", maxx);

	return 0;
}
