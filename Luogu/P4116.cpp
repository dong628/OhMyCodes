#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using std::max, std::min;

const int Maxn = 1e5+5;
struct Node{
	int l, r, first;
} seg[4*Maxn];
int size[Maxn], top[Maxn], hson[Maxn], depth[Maxn], fa[Maxn];
int n, dfn[Maxn], rank[Maxn], ts = 1;
std::vector <int> tree[Maxn];

void dfs1(int, int), dfs2(int, int);
void build(int, int, int), mod(int, int);
int pfq(int), query(int, int);

int main(){
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);

	int q, u, v;
	scanf("%d %d\n", &n, &q);
	for(int i=1; i<n; i++){
		scanf("%d %d\n", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs1(1, 0); dfs2(1, 1);
	build(1, 1, n);

	while(q --> 0){
		scanf("%d %d", &u, &v);
		if(u == 0){
			mod(1, dfn[v]);
		}
		else{
			printf("%d\n", pfq(v));
		}
	}

	return 0;
}

void dfs1(int cur, int pre){
	fa[cur] = pre;
	depth[cur] = depth[pre] + 1;
	hson[cur] = -1;
	size[cur] = 1;
	int msize = 0;
	for(int i=0; i<tree[cur].size(); i++){
		if(tree[cur][i] == pre) continue;
		dfs1(tree[cur][i], cur);
		size[cur] += size[tree[cur][i]];
		if(size[cur] > msize){
			msize = size[cur];
			hson[cur] = tree[cur][i];
		}
	}
}

void dfs2(int cur, int t){
	top[cur] = t;
	dfn[cur] = ts; rank[ts] = cur;
	ts++;
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
	seg[rt].first = -1;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(rt*2, l, mid);
	build(rt*2+1, mid+1, r);
}

void mod(int rt, int poi){
	if(seg[rt].l == poi && seg[rt].r == poi){
		if(seg[rt].first == -1) seg[rt].first = poi;
		else seg[rt].first = -1;
		return;
	}
	if(seg[rt*2].r >= poi){
		mod(rt*2, poi);
	}
	else{
		mod(rt*2+1, poi);
	}
	if(seg[rt*2].first == -1){
		seg[rt].first = seg[rt*2+1].first;
	}
	else seg[rt].first = seg[rt*2].first;
}

int query(int rt, int l, int r){
	if(seg[rt].l == l && seg[rt].r == r){
		return seg[rt].first;
	}
	int ans = -1;
	if(seg[rt*2].r >= l){
		ans = query(rt*2, l, min(r, seg[rt*2].r));
	}
	if(seg[rt*2+1].l <= r && ans == -1){
		ans = query(rt*2+1, max(l, seg[rt*2+1].l), r);
	}
	return ans;
}

int pfq(int v){
	int ans = -1, tmp;
	while(top[v] != 1){
		tmp = query(1, dfn[top[v]], dfn[v]);
		if(tmp != -1) ans = tmp;
		v = fa[top[v]];
	}
	tmp = query(1, dfn[1], dfn[v]);
	if(tmp != -1) ans = tmp;
	if(ans == -1) return -1;
	else return rank[ans];
}
