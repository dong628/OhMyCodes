#include <cstdio>
#include <iostream>
#include <vector>
using std::min, std::max;

const int Maxn = 1e5+5;
struct Node{
	int l, r, val, tag;
} seg[4*Maxn];
int ts = 1;
int dfn[Maxn], rank[Maxn], depth[Maxn], hson[Maxn], size[Maxn], fa[Maxn], top[Maxn];
std::vector <int> tree[Maxn];
void dfs1(int, int), dfs2(int, int);
void build(int, int, int), add(int, int, int), addpf(int, int), update(int);
int query(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	int n, m, u, v;

	scanf("%d %d\n", &n, &m);

	for(int i=1; i<n; i++){
		scanf("%d %d\n", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs1(1, 0); dfs2(1, 1);
	build(1, 1, n);

	char op;
	while(m --> 0){
		scanf("%c %d %d\n", &op, &u, &v);
		if(op == 'P'){
			addpf(u, v);
		}
		else{
			if(fa[u] == v){
				printf("%d\n", query(1, dfn[u], dfn[u]));
			}
			else{
				printf("%d\n", query(1, dfn[v], dfn[v]));
			}
		}
	}

	return 0;
}

void dfs1(int cur, int from){
	fa[cur] = from;
	size[cur] = 1;
	depth[cur] = depth[from] + 1;
	hson[cur] = -1;
	int smax = 0;
	for(int i=0; i<tree[cur].size(); i++){
		if(tree[cur][i] == from) continue;
		dfs1(tree[cur][i], cur);
		size[cur] += size[tree[cur][i]];
		if(smax < size[tree[cur][i]]){
			smax = size[tree[cur][i]];
			hson[cur] = tree[cur][i];
		}
	}
}

void dfs2(int cur, int t){
	dfn[cur] = ts; rank[ts] = cur;
	ts++;
	top[cur] = t;
	if(hson[cur] != -1){
		dfs2(hson[cur], t);
	}
	for(int i=0; i<tree[cur].size(); i++){
		if(tree[cur][i] == fa[cur] || tree[cur][i] == hson[cur]) continue;
		dfs2(tree[cur][i], tree[cur][i]);
	}
}

void build(int rt, int l, int r){
	seg[rt].l = l; seg[rt].r = r;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(rt*2, l, mid);
	build(rt*2+1, mid+1, r);
}

void add(int rt, int l, int r){
	seg[rt].val += r - l + 1;
	if(seg[rt].l == l && seg[rt].r == r){
		seg[rt].tag++;
		return;
	}
	if(seg[rt*2].r >= l){
		add(rt*2, l, min(seg[rt*2].r, r));
	}
	if(seg[rt*2+1].l <= r){
		add(rt*2+1, max(seg[rt*2+1].l, l), r);
	}
}

int query(int rt, int l, int r){
	if(seg[rt].l == l && seg[rt].r == r){
		return seg[rt].val;
	}
	update(rt);
	int ans = 0;
	if(seg[rt*2].r >= l){
		ans += query(rt*2, l, min(seg[rt*2].r, r));
	}
	if(seg[rt*2+1].l <= r){
		ans += query(rt*2+1, max(seg[rt*2+1].l, l), r);
	}
	return ans;
}

void addpf(int u, int v){
	while(top[u] != top[v]){
		if(depth[top[u]] > depth[top[v]]){
			add(1, dfn[top[u]], dfn[u]);
			u = fa[top[u]];
		}
		else{
			add(1, dfn[top[v]], dfn[v]);
			v = fa[top[v]];
		}
	}
	if(depth[u] > depth[v]){
		add(1, dfn[hson[v]], dfn[u]);
	}
	else if(depth[v] > depth[u]){
		add(1, dfn[hson[u]], dfn[v]);
	}
}

void update(int rt){
	seg[rt*2].val += (seg[rt*2].r - seg[rt*2].l + 1) * seg[rt].tag;
	seg[rt*2+1].val += (seg[rt*2+1].r - seg[rt*2+1].l + 1) * seg[rt].tag;
	seg[rt*2].tag += seg[rt].tag;
	seg[rt*2+1].tag += seg[rt].tag;
	seg[rt].tag = 0;
}
