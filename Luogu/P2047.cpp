#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn = 105, Inf = 0x3f3f3f3f;
int dist[Maxn][Maxn], a, b, c, n, m;
long long nu[Maxn][Maxn];
double ans[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	memset(dist, 0x3f, sizeof(dist));
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = std::min(dist[a][b], c);
		dist[b][a] = std::min(dist[b][a], c);
		nu[a][b] = 1; nu[b][a] = 1;
	}
	for(int k=1; k<=n; k++){
		for(int x=1; x<=n; x++){
			for(int y=1; y<=n; y++){
				if(dist[x][k]!=Inf && dist[k][y]!=Inf){
					if(dist[x][k]+dist[k][y] < dist[x][y]){
						dist[x][y] = dist[x][k]+dist[k][y];
						nu[x][y] = nu[x][k] * nu[k][y];
					}
					else if(dist[x][k]+dist[k][y] == dist[x][y]){
						nu[x][y] += nu[x][k] * nu[k][y];
					}
				}
			}
		}
	}

	for(int x=1; x<=n; x++){
		for(int y=1; y<=n; y++){
			for(int k=1; k<=n; k++){
				if(x==y || k==x || k==y) continue;
				if(dist[x][k]+dist[k][y] == dist[x][y] && nu[x][y]!=0){
					ans[k] += double(nu[x][k]*nu[k][y])/nu[x][y];
				}
			}
		}
	}

	for(int i=1; i<=n; i++){
		printf("%.3lf\n", ans[i]);
	}

	return 0;
}
