#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using std::min, std::max, std::make_pair, std::queue;

//const int Maxn = 1e2+5, Inf = 0x7fffffff;
const int Maxn = 3e3+5, Inf = 0x7fffffff;
typedef std::pair <int, int> pii;
struct Edge{
	int to, val, cur, fx;
};
std::vector <Edge> mapp[Maxn];
std::vector <pii> mp[Maxn];
int n, m, q, dd[Maxn], b[Maxn], cnt[Maxn], trans[Maxn], s, t;
int depth[Maxn], dis[Maxn][Maxn];
bool vis[Maxn];
int dfst(int, int, int);
bool bfs(void);
int dfs(int, int);
void addedge(int, int, int);

int main(){
	freopen("data.in", "r", stdin);
	
	int u, v, w, pub = 0;
	scanf("%d %d %d", &n, &m, &q);
	for(int i=0; i<n; i++){
		scanf("%d", &dd[i]);
	}
	for(int i=1; i<=n; i++){
		scanf("%d", &b[i]);
	}
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &u, &v, &w);
		mp[u].push_back(make_pair(v, w));
		mp[v].push_back(make_pair(u, w));
		cnt[u]++; cnt[v]++;
	}
	for(int i=0; i<q; i++){
		scanf("%d", &u);
		mp[u].push_back(make_pair(pub, Inf));
		mp[pub].push_back(make_pair(u, Inf));
		cnt[u]++; cnt[pub]++;
	}
	for(int i=0; i<n-1; i++){
		trans[i] = dfst(dd[i], dd[i+1], Inf);
	}
/*
	for(int i=0; i<n-1; i++){
		printf("%d ", trans[i]);
	}
*/
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	int ans = 0;
	s = 0; t = n+1;
	for(int i=0; i<n-1; i++){
		addedge(dd[i], dd[i+1], trans[i]);
	}
	for(int i=1; i<=n; i++){
		if(b[i] > 0){
			addedge(s, i, b[i]);
		}
		else{
			addedge(i, t, -b[i]);
		}
	}
	while(bfs()){
		ans += dfs(s, Inf);
	}
	for(int i=0; i<n; i++){
		if(b[dd[i]] < 0){
			printf("%d\n", mapp[dd[i]][cnt[dd[i]]-1].cur);
		}
	}
//	printf("%d", ans);

	return 0;
}

int dfst(int cur, int tar, int minn){
	if(cur == tar) return minn;
//	if(dist[cur][tar] != 0) return dist[cur][tar];
	vis[cur] = true;
	int maxx = 0, tmp;
	for(int i=0; i<cnt[cur]; i++){
		if(!vis[mp[cur][i].first]){
			tmp = dfst(mp[cur][i].first, tar, min(mp[cur][i].second, minn));
			maxx = maxx<tmp?tmp:maxx;
		}
	}
	vis[cur] = false;
	return maxx;
}

bool bfs(void){
	int cur;
	Edge tar;
	queue <int> q;
	memset(vis, 0, sizeof(vis));
	memset(depth, 0, sizeof(depth));
	q.push(s);
	vis[s] = true;
	while(!q.empty()){
		cur = q.front(); q.pop();
		for(int i=0; i<cnt[cur]; i++){
			tar = mapp[cur][i];
			if((!vis[tar.to]) && tar.cur<tar.val){
				vis[tar.to] = true;
				depth[tar.to] = depth[cur]+1;
				q.push(tar.to);
			}
		}
	}
	return vis[t];
}

int dfs(int cur, int flow){
	if(cur==t || flow==0) return flow;
	Edge tar;
	int out = 0, tmp;
	for(int i=0; i<cnt[cur]; i++){
		tar = mapp[cur][i];
		if(depth[tar.to] == depth[cur]+1 && tar.cur < tar.val){
			tmp = dfs(tar.to, min(flow, tar.val-tar.cur));
			mapp[tar.to][tar.fx].cur -= tmp;
			mapp[cur][i].cur += tmp;
			out += tmp;
			flow -= tmp;
			if(flow == 0) break;
		}
	}
	if(out == 0) depth[cur] = 0;
	return out;
}

void addedge(int st, int to, int val){
	Edge tst, tto;
	tst.val = val; tto.val = val;
	tst.cur = 0; tto.cur = val;
	tst.to = to; tto.to = st;
	tst.fx = cnt[to]; tto.fx = cnt[st];
	mapp[st].push_back(tst);
	mapp[to].push_back(tto);
	cnt[st]++; cnt[to]++;
}
