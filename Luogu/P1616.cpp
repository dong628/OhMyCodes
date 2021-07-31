#include <cstdio>
#include <iostream>

const int Maxm=1e4+5, Maxt=1e7+5;
int t, m, v[Maxm], w[Maxm];
long long dp[Maxt], maxx;
long long max(long long a, long long b) { return a>b?a:b; }

int main(){
	scanf("%d %d", &t, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d", &v[i], &w[i]);
	}
	for(int i=1; i<=m; i++){
		for(int j=0; j<=t; j++){
			if(j>=v[i]){
				dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
			}
		}
	}
	for(int i=1; i<=t; i++){
		maxx = maxx>dp[i]?maxx:dp[i];
	}
	printf("%lld", maxx);

	return 0;
}
