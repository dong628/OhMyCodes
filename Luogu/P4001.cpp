#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using std::queue, std::min, std::vector;

const int Inf = 0x7fffffff, Maxn = 1e6+5;
struct Edge{
	int to, val, cur;
	short fx;
};
vector <Edge> mapp[Maxn];
//Edge mapp[Maxn][8];
queue <int> q;
int s, t, cntop;
short depth[Maxn], cnt[Maxn];
bool vis[Maxn];
bool bfs(void);
int dfs(int, int);
void addedge(int, int, int);

signed main(){
	freopen("data.in", "r", stdin);

	int n, m, v, ans = 0;
	scanf("%d %d", &n, &m);
	s = 1; t = n*m;
	for(int i=0; i<n; i++){
		for(int j=1; j<m; j++){
			scanf("%d", &v);
			addedge(i*m+j, i*m+j+1, v);
			addedge(i*m+j+1, i*m+j, v);
//			addedge(i*m+j+1, 3*(i*m+j)+t, v);
//			addedge(3*(i*m+j)+t, i*m+j, v);
		}
	}
	for(int i=0; i<n-1; i++){
		for(int j=1; j<=m; j++){
			scanf("%d", &v);
			addedge(i*m+j, i*m+j+m, v);
			addedge(i*m+j+m, i*m+j, v);
//			addedge(i*m+j+m, 3*(i*m+j)+1+t, v);
//			addedge(3*(i*m+j)+1+t, i*m+j, v);
		}
	}
	for(int i=0; i<n-1; i++){
		for(int j=1; j<m; j++){
			scanf("%d", &v);
			addedge(i*m+j, i*m+j+m+1, v);
			addedge(i*m+j+m+1, i*m+j, v);
//			addedge(i*m+j+m+1, 3*(i*m+j)+2+t, v);
//			addedge(3*(i*m+j)+2+t, i*m+j, v);
		}
	}
	while(bfs()){
		ans += dfs(s, Inf);
	}
	printf("%d", ans);

	return 0;
}

bool bfs(void){
	int cur;
	Edge tar;
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
//	mapp[st][cnt[st]] = tst;
//	mapp[to][cnt[to]] = tst;
	cnt[st]++; cnt[to]++;
}
