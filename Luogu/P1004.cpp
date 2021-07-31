#include <cstdio>
#include <iostream>
using std::max;
using std::min;

const int Maxn=19;
int n, x, y, s, m[Maxn][Maxn], dp[Maxn][Maxn][Maxn], ans;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	while(true){
		scanf("%d %d %d", &x, &y, &s);
		if(x==0 && y==0 && s==0) break;
		m[x][y]=s;
	}
/*	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	dp[0][1][1] = m[1][1];
	for(int step=1; step<=2*n-3; step++){
		for(int i=max(1, step-7); i<=min(step+1, n); i++){
			for(int j=max(1, step-7); j<=min(step+1, n); j++){
				if(i!=j){
					dp[step][i][j]= max(max(max(dp[step-1][i-1][j],
							dp[step-1][i-1][j-1]),
							dp[step-1][i][j-1]),
							dp[step-1][i][j]) + m[i][step-i+2] + 
							m[j][step-j+2];
				}
				ans = ans>dp[step][i][j]?ans:dp[step][i][j];
			}
		}
	}

/*	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				printf("%d ", dp[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}*/


	printf("%d", ans+m[n][n]);

	return 0;
}
