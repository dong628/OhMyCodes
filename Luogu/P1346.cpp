#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn=105;
int dist[Maxn], n, a, b, ki, x, mapp[Maxn][Maxn];
bool vis[Maxn];
void dijkstra(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &n, &a, &b);
	memset(mapp, 0x3f, sizeof(mapp));
	for(int i=0; i<=n; i++) mapp[i][i]=0;
	for(int i=1; i<=n; i++){
		scanf("%d", &ki);
		for(int j=1; j<=ki; j++){
			scanf("%d", &x);
			if(j==1) mapp[i][x] = 0;
			else mapp[i][x] = 1;
		}
	}
	dijkstra(a);
	if(dist[b]!=0x3f3f3f3f)
		printf("%d", dist[b]);
	else
		printf("-1");

	return 0;
}

void dijkstra(int s){
	memset(vis, 0, sizeof(vis));
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0;
	int x;
	for(int i=1; i<n; i++){
		x=0;
		for(int j=1; j<=n; j++){
			if((!vis[j]) && (x==0 || dist[j]<dist[x])) x=j;
		}
		vis[x] = true;
		for(int j=1; j<=n; j++){
			if(dist[j]>dist[x]+mapp[x][j]) dist[j]=dist[x]+mapp[x][j];
		}
	}
}
