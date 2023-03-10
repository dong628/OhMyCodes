#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

const int Maxn = 1e4+5, Inf = 0x3f3f3f3f;

struct Edge{
	int from, to, cur, val, fx;
};

int depth[Maxn], hash[Maxn], s, t;
std::vector <Edge> mapp[Maxn];
std::vector <int> opt[Maxn];
bool bfs(void);
void addedge(int, int, int);
int dfs(int, int);

int main(){
	freopen("data.in", "r", stdin);

	int m, n, r, c, cnt, rsum = 0, cur;

	scanf("%d %d", &m, &n);
	s = 0; t = 1;
	cnt = n + 2;
	for(int i=1; i<=m; i++){
		scanf("%d", &r);
		rsum += r;
		for(int j=2; j<=n+1; j++){
			addedge(j, cnt, 1);
		}
		hash[cnt] = i;
		cur = cnt++;
		for(int j=1; j<=r; j++){
			addedge(cur, cnt, 1);
			addedge(cnt, t, 1);
			cnt++;
		}
	}
	for(int i=1; i<=n; i++){
		scanf("%d", &c);
		addedge(s, i+1, c);
	}

	int ans = 0;
	while(bfs()){
		ans += dfs(s, Inf);
	}
	if(ans != rsum){
		printf("0");
		return 0;
	}

	printf("1\n");
	for(int i=2; i<=n+1; i++){
		for(int j=0; j<mapp[i].size(); j++){
			if(mapp[i][j].to == s) continue;
			if(mapp[i][j].cur == 1) opt[hash[mapp[i][j].to]].push_back(i-1);
		}
	}
	for(int i=1; i<=m; i++){
		for(int j=0; j<opt[i].size(); j++){
			printf("%d ", opt[i][j]);
		}
		printf("\n");
	}

	return 0;
}

bool bfs(void){
	memset(depth, 0, sizeof(depth));
	depth[s] = 1;
	std::queue <int> q;
	q.push(s);
	int cur;
	while(!q.empty()){
		cur = q.front(); q.pop();
		for(int i=0; i<mapp[cur].size(); i++){
			if(mapp[cur][i].val <= mapp[cur][i].cur || depth[mapp[cur][i].to] != 0) continue;
			depth[mapp[cur][i].to] = depth[cur] + 1;
			q.push(mapp[cur][i].to);
		}
	}
	return depth[t] != 0;
}

int dfs(int cur, int flow){
	if(cur == t || flow == 0) return flow;
	int tmp, out = 0;
	for(int i=0; i<mapp[cur].size(); i++){
		if(depth[mapp[cur][i].to] == depth[cur] + 1){
			tmp = dfs(mapp[cur][i].to, std::min(flow, mapp[cur][i].val - mapp[cur][i].cur));
			mapp[cur][i].cur += tmp;
			mapp[mapp[cur][i].to][mapp[cur][i].fx].cur -= tmp;
			out += tmp;
			flow -= tmp;
			if(flow == 0) break;
		}
	}
	if(out == 0) depth[cur] = -1;
	return out;
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
}
