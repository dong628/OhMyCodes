#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using std::queue, std::min, std::vector;

const int Inf = 0x7fffffff, Maxn = 5e2+5;
struct Edge{
	int to, val, cur, fx;
};
vector <Edge> mapp[3*Maxn];
int n, k, s, t, cnt[3*Maxn], depth[3*Maxn];
bool vis[3*Maxn];
bool bfs(void);
int dfs(int, int);
void addedge(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	int a, b, ans = 0;
	scanf("%d %d", &n, &k);
	s = 0; t = 2*n+1;
	for(int i=1; i<=k; i++){
		scanf("%d %d", &a, &b);
		addedge(a, n+b, 1);
	}
	for(int i=1; i<=n; i++){
		addedge(s, i, 1);
	}
	for(int i=n+1; i<=2*n; i++){
		addedge(i, t, 1);
	}
	while(bfs()){
		ans += dfs(0, Inf);
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
