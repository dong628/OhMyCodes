#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using std::min;

typedef long long lol;
const int Maxn = 205;
const lol Inf = 1e18;

struct Edge{
	int to;
	lol val, cur;
	Edge* fx;
};

int cnt[Maxn], s, t, depth[Maxn];
bool vis[Maxn];
//std::vector<Edge> mapp[Maxn];
Edge mapp[Maxn][Maxn];
std::queue<int> q;
bool bfs();
lol dfs(int, lol);

int main(){
	freopen("data.in", "r", stdin);	

	int n, m, u, v; lol w;
	Edge tmpu, tmpv;
	scanf("%d %d %d %d", &n, &m, &s, &t);

	tmpu.cur = 0; tmpv.cur = 0;
	for(int i=0; i<m; i++){
		scanf("%d %d %lld", &u, &v, &w);
		tmpu.to = v; tmpu.val = w;
		tmpv.to = u; tmpv.val = w;
		tmpv.cur = w;
		mapp[u][cnt[u]] = tmpu;
		mapp[v][cnt[v]] = tmpv;
		mapp[u][cnt[u]].fx = &mapp[v][cnt[v]];
		mapp[v][cnt[v]].fx = &mapp[u][cnt[u]];
		cnt[u]++; cnt[v]++;
	}

	lol ans = 0;
	while(bfs()){
		ans += dfs(s, Inf);
	}
	printf("%lld", ans);

	return 0;
}

bool bfs(){
	int cur;
	Edge nxt;
	memset(vis, 0, sizeof(vis));
	memset(depth, 0, sizeof(depth));
	q.push(s);
	vis[s] = true;
	while(!q.empty()){
		cur = q.front(); q.pop();
		for(int i=0; i<cnt[cur]; i++){
			nxt = mapp[cur][i];
			if((!vis[nxt.to]) && nxt.cur < nxt.val){
				q.push(nxt.to);
				depth[nxt.to] = depth[cur]+1;
				vis[nxt.to] = true;
			}
		}
	}
	return vis[t];
}

lol dfs(int cur, lol flow){
	lol out = 0, res;
	Edge nxt;
	if(cur == t || flow == 0) return flow;
	for(int i=0; i<cnt[cur]; i++){
		if(flow <= 0) break;
		nxt = mapp[cur][i];
		if(depth[nxt.to] == depth[cur]+1 && nxt.val-nxt.cur>0){
			res = dfs(nxt.to, min(flow, nxt.val-nxt.cur));
			mapp[cur][i].cur += res;
			nxt.fx -> cur -= res;
			out += res;
			flow -= res;
		}
	}
	if(out == 0) depth[cur] = 0;
	return out;
}
