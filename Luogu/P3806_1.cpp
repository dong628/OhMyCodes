#include <cstdio>
#include <iostream>
#include <queue>
using std::queue;
using std::max;

const int Maxn = 1e4+5;
int n, m, u, v, w, tim, ask[Maxm], cnt[Maxn], dfn[Maxn];
void calcvx(int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d %d %d", &u, &v, &w);
		tr[u].push_back(make_pair(v, w)); cnt[u]++;
		tr[v].push_back(make_pair(u, w)); cnt[v]++;
	}
	for(int i=0; i<m; i++){
		scanf("%d", &ask[i]);
	}

	divide(1, 1);

	return 0;
}

void calcvx(int cur, int from){
	size[cur] = 1;
	for(int i=0; i<cnt[cur]; i++){
		if(tr[cur][i].first != from){
			calcvx(tr[cur][i].first, cur);
			size[cur] += size[tr[cur][i].first];
			maxs[cur] = max(maxs[cur], size[tr[cur][i].first])
		}
	}
	maxs[cur] = max(maxs[cur], n-size[cur]);
	if(maxs[cur] < minmax){
		minmax = maxs[cur];
		vx = cur;
	}
}

void divide(int root){
	vis[root] = true;
	calcvx(root);
	root = vx;
	calcdis(root);
	for(int i=0; i<cnt[root]; i++){
		if(!vis[tr[root][i].first]){
			divide(tr[root][i].second);
		}
	}
}
