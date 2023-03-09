#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using std::vector, std::min;

//const int Maxn = 1e5+5, Inf = 0x3f3f3f3f;
const int Maxn = 1e2+5, Inf = 0x3f3f3f3f;
struct Edge{
	int from, to, val, cur, fx;
};
vector <Edge> mapp[Maxn];
vector <int> fa[25];
int s, t, depth[Maxn];

void addedge(int, int, int);
bool bfs(void);
int dfs(int, int);

int main(){
	freopen("data.in", "r", stdin);

	int k, n, tar, p, tt, cnt, star = 0;

	scanf("%d %d", &k, &n);
	cnt = n + k + 2;
	s = 0; t = 1;
	for(int i=1; i<=n; i++){
		addedge(s, i + 1, 1);
	}
	for(int i=1; i<=k; i++){
		scanf("%d", &tar);
		addedge(i + n + 1, t, tar);
		star += tar;
	}
	for(int i=1; i<=n; i++){
		scanf("%d", &p);
		for(int j=1; j<=p; j++){
			scanf("%d", &tt);
			addedge(i+1, cnt, 1);
			addedge(cnt, tt + n + 1, 1);
			cnt++;
		}
	}

	int ans = 0;
	while(bfs()){
		ans += dfs(s, Inf);
	}
	if(ans < star){
		printf("No Solution!");
		return 0;
	}

	for(int i=0; i<mapp[s].size(); i++){
		tar = mapp[s][i].to;
		for(int j=0; j<mapp[tar].size(); j++){
			if(mapp[tar][i].cur == 0) continue;
			fa[mapp[mapp[tar][j].to][0].to - n - 1].push_back(tar - 1);
		}
	}

	for(int i=1; i<=k; i++){
		printf("%d: ", i);
		for(int j=0; j<fa[i].size(); j++){
			printf("%d ", fa[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void addedge(int u, int v, int w){
	Edge l, r;
	l.from = u; l.to = v;
	l.val = w; l.cur = 0;
	l.fx = mapp[v].size();
	r.from = v; r.to = u;
	r.val = w; r.cur = w;
	r.fx = mapp[u].size();
	mapp[u].push_back(l);
	mapp[v].push_back(r);
	printf("%d -> %d, %d\n", u, v, w);
}

bool bfs(void){
	memset(depth, 0, sizeof(depth));
	std::queue <int> q;
	q.push(s);
	depth[s] = 1;
	int tar;
	while(!q.empty()){
		tar = q.front(); q.pop();
		for(int i=0; i<mapp[tar].size(); i++){
			if(depth[mapp[tar][i].to] != 0 || mapp[tar][i].cur >= mapp[tar][i].val) continue;
			depth[mapp[tar][i].to] = depth[tar] + 1;
			q.push(mapp[tar][i].to);
		}
	}
	return depth[t] != 0;
}

int dfs(int cur, int flow){
	if(cur == t || flow == 0) return flow;
	int out = 0, tmp;
	for(int i=0; i<mapp[cur].size(); i++){
		if(depth[mapp[cur][i].to] != depth[cur] + 1) continue;
		tmp = dfs(mapp[cur][i].to, min(flow, mapp[cur][i].val - mapp[cur][i].cur));
		out += tmp;
		flow -= tmp;
		mapp[cur][i].cur += tmp;
		mapp[mapp[cur][i].to][mapp[cur][i].fx].cur -= tmp;
		if(flow == 0) break;
	}
	if(out = 0) depth[cur] = -1;
	return out;
}
