#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn=1e4+5;
bool vis[Maxn];
int mapp[Maxn][Maxn], dist[Maxn], n, m, s, u, v, w;
int min(int xx, int yy) { return xx<yy?xx:yy; }
void dijkstra(void);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &n, &m, &s);
	memset(mapp, 0x3f, sizeof(mapp));
	for(int i=0; i<=n; i++) mapp[i][i] = 0;
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &u, &v, &w);
		mapp[u][v] = min(w, mapp[u][v]);
	}
	dijkstra();
	for(int i=1; i<=n; i++){
		printf("%d ", dist[i]);
	}
	printf("\n");


	return 0;
}

void dijkstra(void){
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	dist[s]=0;
	int x=0;
	for(int i=1; i<n; i++){
		x=0;
		for(int j=1; j<=n; j++){
			if((!vis[j]) && (x==0 || dist[j]<dist[x])) x=j;
		}
		vis[x] = true;
		for(int j=1; j<=n; j++){
			if(dist[j] > dist[x]+mapp[x][j]) dist[j] = dist[x]+mapp[x][j];
		}
	}
}
