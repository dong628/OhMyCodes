#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using std::min, std::queue;

const int Maxn = 1e2+5, Inf = 0x7fffffff;
struct Edge{
	int to, val, cur;
	Edge* fx;
} mapp[Maxn][Maxn];
int n, m, depth[Maxn], cnt[Maxn];
bool vis[Maxn];
queue<int> q;
void init(void);
bool bfs(void);
int dfs(int, int);

int main(){
	freopen("data.in", "r", stdin);

	init();
	int ans = 0;
	while(bfs()){
		ans += dfs(0, Inf);
	}
	printf("%d\n", ans);
	for(int i=1; i<=m; i++){
		for(int j=0; j<cnt[i]; j++){
			if(mapp[i][j].cur>0 && mapp[i][j].to!=0) printf("%d %d\n", i, mapp[i][j].to);
		}
	}

	return 0;
}

void init(void){
	int u, v;
	scanf("%d %d", &m, &n);
	for( ; ; ){
		scanf("%d %d", &u, &v);
		if(u == -1) break;
		mapp[u][cnt[u]].to = v;
		mapp[v][cnt[v]].to = u;
		mapp[u][cnt[u]].val = 1;
		mapp[v][cnt[v]].val = 1;
		mapp[v][cnt[v]].cur = 1;
		mapp[u][cnt[u]].fx = &mapp[v][cnt[v]];
		mapp[v][cnt[v]].fx = &mapp[u][cnt[u]];
		cnt[u]++; cnt[v]++;
	}
	for(int i=1; i<=m; i++){
		mapp[0][cnt[0]].to = i;
		mapp[i][cnt[i]].to = 0;
		mapp[0][cnt[0]].val = 1;
		mapp[i][cnt[i]].val = 1;
		mapp[i][cnt[i]].cur = 1;
		mapp[0][cnt[0]].fx = &mapp[i][cnt[i]];
		mapp[i][cnt[i]].fx = &mapp[0][cnt[0]];
		cnt[0]++; cnt[i]++;
	}
	for(int i=m+1; i<=n; i++){
		mapp[n+1][cnt[n+1]].to = i;
		mapp[i][cnt[i]].to = n+1;
		mapp[n+1][cnt[n+1]].val = 1;
		mapp[i][cnt[i]].val = 1;
		mapp[n+1][cnt[n+1]].cur = 1;
		mapp[n+1][cnt[n+1]].fx = &mapp[i][cnt[i]];
		mapp[i][cnt[i]].fx = &mapp[n+1][cnt[n+1]];
		cnt[n+1]++; cnt[i]++;
	}
}

bool bfs(void){
	int cur;
	memset(vis, 0, sizeof(vis));
	memset(depth, 0, sizeof(depth));
	q.push(0);
	vis[0] = true;
	while(!q.empty()){
		cur = q.front(); q.pop();
		vis[cur] = true;
		for(int i=0; i<cnt[cur]; i++){
			if((!vis[mapp[cur][i].to]) && mapp[cur][i].cur<mapp[cur][i].val){
				q.push(mapp[cur][i].to);
				depth[mapp[cur][i].to] = depth[cur]+1;
			}
		}
	}
	return vis[n+1];
}

int dfs(int cur, int flow){
	int out = 0, tmp;
	Edge tar;
	if(cur==n+1 || flow==0){
		return flow;
	}
	for(int i=0; i<cnt[cur]; i++){
		tar = mapp[cur][i];
		if(depth[tar.to]==depth[cur]+1 && tar.val>tar.cur){
			tmp = dfs(tar.to, min(flow, tar.val-tar.cur));
			flow -= tmp;
			out += tmp;
			mapp[cur][i].cur += tmp;
			mapp[cur][i].fx -> cur -= tmp;
		}
	}
	if(out == 0) depth[cur] = 0;
	return out;
}
