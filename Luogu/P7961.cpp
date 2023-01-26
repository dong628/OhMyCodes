#include <iostream>
#include <cstdio>

const int Maxn = 35, Maxm = 105, Mod = 998244353;
int n, m, ki;
long long v[Maxm], c[Maxn][Maxn], vpow[Maxm][Maxn];
long long dp[Maxm][Maxn][Maxn][Maxn];

void init(void);
int popcount(int x){
	int ans = 0;
	while(x){
		ans += x&1;
		x >>= 1;
	}
	return ans;
}

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &n, &m, &ki);

	for(int i=0; i<=m; i++){
		scanf("%lld", &v[i]);
	}
	init();

	dp[0][0][0][0] = 1;
	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			for(int k=0; k<=ki; k++){
				for(int l=0; l<=j/2; l++){
					for(int t=0; t<=n-j; t++){
						dp[i+1][j+t][k+(t+l)%2][(t+l)/2] += ((dp[i][j][k][l] * vpow[i][t]) % Mod) * c[n-j][t];
						dp[i+1][j+t][k+(t+l)%2][(t+l)/2] %= Mod;
					}
				}
			}
		}
	}

	long long ans = 0;
	for(int kt=0; kt<=ki; kt++){
		for(int p=0; p<=n/2; p++){
			if(popcount(p) + kt <= ki){
				ans += dp[m+1][n][kt][p];
				ans %= Mod;
			}
		}
	}

	printf("%lld", ans);

	return 0;
}

void init(void){
	for(int i=0; i<=m; i++){
		vpow[i][0] = 1;
		for(int j=1; j<=n; j++){
			vpow[i][j] = (vpow[i][j-1] * v[i]) % Mod;
		}
	}
	for(int i=0; i<=n; i++) c[i][0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % Mod;
		}
	}
}
