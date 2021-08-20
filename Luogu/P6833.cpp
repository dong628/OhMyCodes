#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

struct Point{
	int x, y;
	long long value;
} tmpoi;
bool operator <(const Point &a, const Point &b){
	return a.value>b.value;
}

const int Inf=0x3f3f3f3f, Maxn=1e3+5;
std::priority_queue<Point> queue;
long long dist[3][Maxn][Maxn], mapp[Maxn][Maxn], mindist, ans, minn=0x3f3f3f3f3f3f3f3f;
int n, m, a, b, c;
int minx, miny;
bool vis[Maxn][Maxn];
void dij(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
	for(int i=n; i>=1; i--){
		for(int j=1; j<=m; j++){
			scanf("%lld", &mapp[i][j]);
		}
	}
	memset(dist, 0x3f, sizeof(dist));
	dij(n, a, 0);
	dij(1, b, 1);
	dij(1, c, 2);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			ans = dist[0][i][j]+dist[1][i][j]+dist[2][i][j]-2*mapp[i][j];
			if(ans>0)
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
	printf("%lld", minn);

	return 0;
}

void dij(int x, int y, int tmp){
	memset(vis, 0, sizeof(vis));
	dist[tmp][x][y] = mapp[x][y];
	tmpoi.value = mapp[x][y];
	tmpoi.x = x; tmpoi.y = y;
	queue.push(tmpoi);
	minx=x; miny=y;
	for(int cs=1; cs<n*m; cs++){
/*		mindist=Inf;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(!vis[i][j] && mindist>dist[tmp][i][j]){
					minx=i;
					miny=j;
					mindist=dist[tmp][i][j];
				}
			}
		}*/
		minx = queue.top().x; miny = queue.top().y;
		queue.pop();
		vis[minx][miny]=true;
		if(minx<n && (!vis[minx+1][miny]) && dist[tmp][minx+1][miny]>dist[tmp][minx][miny]+mapp[minx+1][miny]){
			dist[tmp][minx+1][miny] = dist[tmp][minx][miny]+mapp[minx+1][miny];
			tmpoi.x = minx+1; tmpoi.y = miny;
			tmpoi.value = dist[tmp][minx+1][miny];
			queue.push(tmpoi);
		}
		if(minx>1 && (!vis[minx-1][miny]) && dist[tmp][minx-1][miny]>dist[tmp][minx][miny]+mapp[minx-1][miny]){
			dist[tmp][minx-1][miny] = dist[tmp][minx][miny]+mapp[minx-1][miny];
			tmpoi.x = minx-1; tmpoi.y = miny;
			tmpoi.value = dist[tmp][minx-1][miny];
			queue.push(tmpoi);
		}
		if(miny<m && (!vis[minx][miny+1]) && dist[tmp][minx][miny+1]>dist[tmp][minx][miny]+mapp[minx][miny+1]){
			dist[tmp][minx][miny+1] = dist[tmp][minx][miny]+mapp[minx][miny+1];
			tmpoi.x = minx; tmpoi.y = miny+1;
			tmpoi.value = dist[tmp][minx][miny+1];
			queue.push(tmpoi);
		}
		if(miny>1 && (!vis[minx][miny-1]) && dist[tmp][minx][miny-1]>dist[tmp][minx][miny]+mapp[minx][miny-1]){
			dist[tmp][minx][miny-1] = dist[tmp][minx][miny]+mapp[minx][miny-1];
			tmpoi.x = minx; tmpoi.y = miny-1;
			tmpoi.value = dist[tmp][minx][miny-1];
			queue.push(tmpoi);
		}
	}
}
