#include <cstdio>
#include <iostream>
#include <cstring>

const int Inf=0x3f3f3f3f, Maxn=1e3+5;
int dist[3][Maxn][Maxn], mapp[Maxn][Maxn], n, m, a, b, c, minn=Inf;
int vis[Maxn][Maxn], minx, miny, mindist, ans;
void dij(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
	for(int i=n; i>=1; i--){
		for(int j=1; j<=m; j++){
			scanf("%d", &mapp[i][j]);
		}
	}
	memset(dist, 0x3f, sizeof(dist));
	dij(n, a, 0);
	dij(1, b, 1);
	dij(1, c, 2);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			ans = dist[0][i][j]+dist[1][i][j]+dist[2][i][j]-2*mapp[i][j];
			minn = minn<ans?minn:ans;
/*			printf("%d %d\n", i, j);
			for(int i=1; i<=n; i++){
				for(int j=1; j<=m; j++){
					printf("%d ", dist[i][j]);
				}
				printf("\n");
			}
			printf("\n");*/
		}
	}
	printf("%d", minn);

	return 0;
}

void dij(int x, int y, int tmp){
	memset(vis, 0, sizeof(vis));
	dist[tmp][x][y] = mapp[x][y];
	minx=x; miny=y;
	for(int cs=1; cs<n*m; cs++){
		mindist=Inf;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(!vis[i][j] && mindist>dist[tmp][i][j]){
					minx=i;
					miny=j;
					mindist=dist[tmp][i][j];
				}
			}
		}
		vis[minx][miny]=true;
		if(minx<n && dist[tmp][minx+1][miny]>dist[tmp][minx][miny]+mapp[minx+1][miny]){
			dist[tmp][minx+1][miny] = dist[tmp][minx][miny]+mapp[minx+1][miny];
		}
		if(minx>1 && dist[tmp][minx-1][miny]>dist[tmp][minx][miny]+mapp[minx-1][miny]){
			dist[tmp][minx-1][miny] = dist[tmp][minx][miny]+mapp[minx-1][miny];
		}
		if(miny<m && dist[tmp][minx][miny+1]>dist[tmp][minx][miny]+mapp[minx][miny+1]){
			dist[tmp][minx][miny+1] = dist[tmp][minx][miny]+mapp[minx][miny+1];
		}
		if(miny>1 && dist[tmp][minx][miny-1]>dist[tmp][minx][miny]+mapp[minx][miny-1]){
			dist[tmp][minx][miny-1] = dist[tmp][minx][miny]+mapp[minx][miny-1];
		}
	}
}
