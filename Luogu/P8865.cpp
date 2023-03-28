#include <cstdio>
#include <iostream>
#include <cstring>
#define int long long

const int Mod = 998244353, Maxn = 1005;

bool mapp[Maxn][Maxn];
int down[Maxn][Maxn], right[Maxn][Maxn], up[Maxn][Maxn];

signed main(){
	freopen("data.in", "r", stdin);

	int t, id, n, m, c, f, cntc = 0, cntf = 0;
	char x;

	scanf("%lld %lld", &t, &id);
	while(t --> 0){
		cntc = 0; cntf = 0;
		memset(down, 0, sizeof(down));
		memset(up, 0, sizeof(up));
		memset(right, 0, sizeof(right));

		scanf("%lld %lld %lld %lld\n", &n, &m, &c, &f);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				x = getchar();
				if(x == '1') mapp[i][j] = true;
				else mapp[i][j] = false;
			}
			getchar();
		}
		
		for(int i=1; i<=m; i++){
			mapp[0][i] = true;
			mapp[n+1][i] = true;
		}
		for(int i=1; i<=n; i++){
			mapp[i][0] = true;
			mapp[i][m+1] = true;
		}

		for(int j=1; j<=m; j++){
			for(int i=n; i>=1; i--){
				if(mapp[i+1][j]) down[i][j] = 0;
				else down[i][j] = down[i+1][j] + 1;
			}
		}

		for(int i=1; i<=n; i++){
			for(int j=m; j>=1; j--){
				if(mapp[i][j+1]) right[i][j] = 0;
				else right[i][j] = right[i][j+1] + 1;
				if(mapp[i][j]) up[i][j] = 0;
				else up[i][j] = up[i-1][j] + right[i][j];
			}
		}
/*
		printf("right\n");
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				printf("%d ", right[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		printf("up\n");
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				printf("%d ", up[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		printf("down\n");
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				printf("%d ", down[i][j]);
			}
			printf("\n");
		}
*/

		for(int i=2; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(mapp[i][j] || mapp[i-1][j]) continue;
				cntc += (right[i][j] * up[i-2][j]) % Mod;
				cntf += ((right[i][j] * up[i-2][j]) % Mod) * down[i][j];
				cntc %= Mod;
				cntf %= Mod;
			}
		}

		printf("%lld %lld\n", cntc*c, cntf*f);
	}

	return 0;
}
