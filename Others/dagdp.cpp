#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 105;

struct edge {
	int v, w;
};
int n, m;
vector <edge> e[MAXN];
vector <int> L;
int dis[MAXN], in[MAXN];
bool vis[MAXN];

void toposort() {
	queue <int> S;
	memset(in, 0, sizeof(in));
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < e[i].size(); j++){
			in[e[i][j].v]++;
		}
	}
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) S.push(i);
	while (!S.empty()) {
		int u = S.front();
		S.pop();
		L.push_back(u);
		for (int i = 0; i < e[u].size(); i++) {
			if (--in[e[u][i].v] == 0) {
				S.push(e[u][i].v);
			}
		}
	}
}

void dp(int s){
	toposort();
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	for (int i = 0; i < L.size(); i++) {
		int u = L[i];
		for (int j = 0; j < e[u].size(); j++) {
			dis[e[u][j].v] = min(dis[e[u][j].v], dis[u] + e[u][j].w);
		}
	}
}

int main(){
	freopen("data.in", "r", stdin);

	int s, u, v, w;
	edge tmp;
	scanf("%d %d %d", &n, &m, &s);
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &u, &v, &w);
		tmp.v = v; tmp.w = w;
		e[u].push_back(tmp);
	}

	dp(s);
	
	for(int i=1; i<=n; i++){
		printf("%d ", dis[i]);
	}

	return 0;
}
