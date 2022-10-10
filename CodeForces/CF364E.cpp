#include <cstdio>
#include <iostream>

const int Maxn = 2505;
int mapp[Maxn][Maxn], sm[Maxn][Maxn];

int main(){
	freopen("data.in", "r", stdin);

	int n, m, kk, flag;
	long long ans = 0;

	scanf("%d %d %d\n", &n, &m, &kk);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			mapp[i][j] = getchar()-'0';
		}
		getchar();
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			sm[i][j] = sm[i-1][j]+sm[i][j-1]-sm[i-1][j-1]+mapp[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			flag = m;
			for(int k=i+1; k<=n; k++){
				for(int l=j+1; l<=n; l++){
					if(sm[k][l]-sm[k][j]-sm[i][l]+sm[i][j] == kk){
						ans++;
					}
					else if(sm[k][l]-sm[k][j]-sm[i][l]+sm[i][j] > kk){
						flag = l-1;
						break;
					}
					if(flag == l) break;
				}
			}
		}
	}
	printf("%lld", ans);

	return 0;
}
