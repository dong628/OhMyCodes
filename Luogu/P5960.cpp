#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn = 1e4+5;
struct Edge{
	int u, v, val;
} edges[Maxn];
int dis[Maxn], cnt;

int main(){
	freopen("data.in", "r", stdin);

	int n, m, u, v, w;

	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++){
		edges[cnt].u = 0;
		edges[cnt].v = i;
		edges[cnt].val = 0;
		cnt++;
	}
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &v, &u, &w);
		edges[cnt].u = u;
		edges[cnt].v = v;
		edges[cnt].val = w;
		cnt++;
	}

	memset(dis, 0x3f, sizeof(dis));
	dis[0] = 0;

	for(int i=0; i<n-1; i++){
		for(int j=0; j<cnt; j++){
			if(dis[edges[j].u] + edges[j].val < dis[edges[j].v]){
				dis[edges[j].v] = edges[j].val + dis[edges[j].u];
			}
		}
	}
	for(int j=0; j<cnt; j++){
		if(dis[edges[j].u] + edges[j].val < dis[edges[j].v]){
			printf("NO\n");
			return 0;
		}
	}

	for(int i=1; i<=n; i++){
		printf("%d ", dis[i]);
	}

	return 0;
}
