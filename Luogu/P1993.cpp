#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn = 2e4+5;
struct Edge{
	int u, v, val;
} edges[Maxn];
int dis[Maxn], cnt;

int main(){
	freopen("data.in", "r", stdin);

	int n, m, a, b, w, tp;

	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++){
		edges[cnt].u = 0;
		edges[cnt].v = i;
		edges[cnt].val = 0;
		cnt++;
	}
	for(int i=1; i<=m; i++){
		scanf("%d", &tp);
		if(tp == 1){
			scanf("%d %d %d", &a, &b, &w);
			edges[cnt].u = a;
			edges[cnt].v = b;
			edges[cnt].val = -w;
			cnt++;
		}
		else if(tp == 2){
			scanf("%d %d %d", &a, &b, &w);
			edges[cnt].u = b;
			edges[cnt].v = a;
			edges[cnt].val = w;
			cnt++;
		}
		else{
			scanf("%d %d", &a, &b);
			edges[cnt].u = b;
			edges[cnt].v = a;
			edges[cnt].val = 0;
			cnt++;
			edges[cnt].u = a;
			edges[cnt].v = b;
			edges[cnt].val = 0;
			cnt++;
		}
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
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");

	return 0;
}
