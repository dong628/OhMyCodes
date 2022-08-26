#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using std::queue, std::min, std::vector;

const int Inf = 0x7fffffff, Maxn = 3e3+5;
struct Edge{
	int to, val, cur, fx;
};
vector <Edge> mapp[Maxn];
int s, t, cnt[Maxn], depth[Maxn], a[Maxn], b[Maxn];
bool vis[Maxn];
bool bfs(void);
int dfs(int, int);
void addedge(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	int n, m, ans = 0, id, k, c1, c2;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=n; i++){
		scanf("%d", &b[i]);
	}
	scanf("%d", &m);
	s = 0; t = n+2*m+1;
	for(int i=1; i<=n; i++){
		addedge(s, i, a[i]);
		addedge(i, t, b[i]);
		ans += a[i]+b[i];
	}
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &k, &c1, &c2);
		addedge(s, n+2*i-1, c1);
		addedge(n+2*i, t, c2);
		ans += c1; ans += c2;
		for(int j=1; j<=k; j++){
			scanf("%d", &id);
			addedge(n+2*i-1, id, Inf);
			addedge(id, n+2*i, Inf);
		}
	}
	while(bfs()){
		ans -= dfs(s, Inf);
	}
	printf("%d", ans);

	return 0;
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
