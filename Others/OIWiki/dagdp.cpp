#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int Maxn = 105;
int min_dis[Maxn], max_dis[Maxn];
bool vis[Maxn];
vector < pair<int, int> > edges[Maxn];
void dp(int);

int main(){
	freopen("data.in", "r", stdin);

	int n, m, u, v, w, s;
	scanf("%d %d %d", &n, &m, &s);
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &u, &v, &w);
		edges[v].push_back(make_pair(u, w));
	}

	memset(min_dis, 0x3f, sizeof(min_dis));
	memset(max_dis, 0, sizeof(max_dis));

	min_dis[s] = 0;
	vis[s] = 0;

	for(int i=1; i<=n; i++){
		dp(i);
		printf("%d %d\n", min_dis[i], max_dis[i]);
	}

	return 0;
}

void dp(int cur){
	if(vis[cur]) return;
	vis[cur] = true;
	
	for(int i=0; i<edges[cur].size(); i++){
		dp(edges[cur][i].first);
		max_dis[cur] = max(max_dis[cur], max_dis[edges[cur][i].first] + edges[cur][i].second);
		min_dis[cur] = min(min_dis[cur], min_dis[edges[cur][i].first] + edges[cur][i].second);
	}
}
