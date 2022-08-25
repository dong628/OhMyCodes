#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using std::queue, std::min, std::vector;

const int Inf = 0x7fffffff, Maxn = 105, Maxm = 605;
struct Edge{
	int to, val, cur, fx;
};
vector <Edge> mapp[2*Maxn+Maxm];
int s, t, cnt[2*Maxn+Maxm], depth[2*Maxn+Maxm];
bool vis[2*Maxn+Maxm];
bool bfs(void);
int dfs(int, int);
void addedge(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	int n, m, c1, c2, a, b, tmp, ans = 0;
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	s = c1*2+1; t = c2*2;
	for(int i=1; i<=n; i++){
		addedge(i*2, i*2+1, 1);
	}
	for(int i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		addedge(a*2+1, b*2, Inf);
		addedge(b*2+1, 2*n+i+2, Inf);
		addedge(2*n+i+2, a*2, Inf);
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
