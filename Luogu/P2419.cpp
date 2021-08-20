#include <iostream>
#include <cstdio>

const int Maxn=105;
int n, m, a, b, ans;
bool vis[Maxn], flag, mapp[Maxn][Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		mapp[b][a] = true;
//		mapp[a][b] = true;
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(mapp[i][k]&mapp[k][j]) mapp[i][j] = true;
			}
		}
	}
//	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			flag=true;
			for(int k=1; k<=n; k++){
				if((!mapp[k][j])&&(!mapp[j][k])&&(!vis[k])&&(j!=k)){
					flag=false;
					break;
				}
			}
			if(flag){
				vis[j] = true;
			}
		}
//	}
	for(int i=1; i<=n; i++){
		if(vis[i]) ans++;
	}
	printf("%d", ans);

	return 0;
}
