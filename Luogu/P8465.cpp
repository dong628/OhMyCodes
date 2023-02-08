#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
using std::make_pair, std::next, std::min, std::vector, std::queue;

const int Maxq = 1e4+5, Maxn = 1e5+5, Maxp = 1e5+5, Maxlog = 30, Ctrl = 1e6;
//const int Maxq = 1e2+5, Maxn = 1e2+5, Maxp = 1e2+5, Maxlog = 30;
const int Inf = 0x3f3f3f3f;
struct Edge{
	int from, to, val, cur, fx;
};
vector <Edge> edges[Maxp];
void stinit(void);
int query(int, int);
std::set < std::pair <int, int> > seg[Maxq];
int n, k, q, a[Maxn], c[Maxq], d[Maxq], x[Maxq], y[Maxq], cnt, depth[Maxp];
int s, t, st[Maxn][Maxlog];
bool vis[Maxp];
bool bfs(void);
int dfs(int, int);
void addedge(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &n, &k, &q);

	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		a[i] += Ctrl;
	}
	stinit();
	cnt = 1;
	for(int i=1; i<=q; i++){
		scanf("%d %d %d %d", &c[i], &d[i], &x[i], &y[i]);
		seg[c[i]].insert(make_pair(x[i], cnt++));
		seg[d[i]].insert(make_pair(n-y[i]+1, cnt++));
		addedge(cnt-2, cnt-1, Inf);
	}
	for(int i=1; i<=k; i++){
		if(seg[i].empty()) seg[i].insert(make_pair(1, cnt++));
	}
	t = cnt++; s = 0;
	for(int i=1; i<=k; i++){
		addedge(s, seg[i].begin() -> second, query(1, seg[i].begin() -> first));
		for(auto itr=seg[i].begin(); itr!=std::prev(seg[i].end()); itr++){
			addedge(itr -> second, std::next(itr) -> second, query(itr -> first, std::next(itr) -> first));
		}
		addedge(seg[i].rbegin() -> second, t, query(seg[i].rbegin() -> first, n));
	}

	long long maxflow = 0;
	while(bfs()){
		maxflow += dfs(s, Inf);
	}
	printf("%d", maxflow - k*Ctrl);

	return 0;
}

void stinit(void){
	int logg = log(n) / log(2);
	for(int i=1; i<=n; i++) st[i][0] = a[i];
	for(int i=1; i<=logg; i++){
		for(int j=1; j<=n-(1<<i)+1; j++){
			st[j][i] = min(st[j][i-1], st[j+(1<<(i-1))][i-1]);
		}
	}
}

int query(int l, int r){
	int logg = log(r-l+1) / log(2);
	return min(st[l][logg], st[r-(1<<logg)+1][logg]);
}

void addedge(int from, int to, int val){
	Edge tmp1, tmp2;

	tmp1.to = to; tmp1.from = from;
	tmp1.val = val; tmp1.cur = 0;
	tmp1.fx = edges[to].size();

	tmp2.to = from; tmp2.from = to;
	tmp2.val = val; tmp2.cur = val;
	tmp2.fx = edges[from].size();

	edges[from].push_back(tmp1);
	edges[to].push_back(tmp2);
}

bool bfs(void){
	queue <int> q;
	q.push(s);
	int tar;
	memset(depth, 0, sizeof(depth));
	memset(vis, 0, sizeof(vis));
	vis[s] = true;
	while(!q.empty()){
		tar = q.front(); q.pop();
		for(int i=0; i<edges[tar].size(); i++){
			if(edges[tar][i].cur < edges[tar][i].val && !vis[edges[tar][i].to]){
				vis[edges[tar][i].to] = true;
				depth[edges[tar][i].to] = depth[tar]+1;
				q.push(edges[tar][i].to);
			}
		}
	}

	return vis[t];
}

int dfs(int cur, int flow){
	if(cur == t || flow == 0) return flow;

	int in = flow, out = 0, tmp;
	for(int i=0; i<edges[cur].size(); i++){
		if(depth[edges[cur][i].to] == depth[cur]+1){
			tmp = dfs(edges[cur][i].to, min(in, edges[cur][i].val-edges[cur][i].cur));
			out += tmp;
			in -= tmp;
			edges[cur][i].cur += tmp;
			edges[edges[cur][i].to][edges[cur][i].fx].cur -= tmp;
		}
		if(in == 0) break;
	}

	if(out == 0) depth[cur] = -1;
	return out;
}
