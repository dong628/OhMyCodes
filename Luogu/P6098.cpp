#include <cstdio>
#include <iostream>
#include <vector>
using std::max, std::min;

const int Maxn = 2e5+5;

struct Node{
	int l, r, val;
} seg[4*Maxn];

int e[Maxn], fa[Maxn], hson[Maxn], depth[Maxn], size[Maxn], top[Maxn], n;
int ts = 1, dfn[Maxn], rank[Maxn];
std::vector <int> tree[Maxn];
void dfs1(int, int), dfs2(int, int);
void mod(int, int, int), build(int, int, int);
int query(int, int, int), pfq(int, int);

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	int q, u, v, opt, x, y;
	scanf("%d %d", &n, &q);
	for(int i=1; i<=n; i++){
		scanf("%d", &e[i]);
	}
	for(int i=1; i<n; i++){
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs1(1, 0); dfs2(1, 1);
	build(1, 1, n);

	while(q --> 0){
		scanf("%d %d %d", &opt, &x, &y);
		if(opt == 1){
			mod(1, dfn[x], y);
		}
		else{
			printf("%d\n", pfq(x, y));
		}
	}

	return 0;
}

void dfs1(int cur, int pre){
	fa[cur] = pre;
	depth[cur] = depth[pre] + 1;
	size[cur] = 1;
	hson[cur] = -1;
	int maxs = 0;
	for(int i=0; i<tree[cur].size(); i++){
		if(tree[cur][i] != pre){
			dfs1(tree[cur][i], cur);
			size[cur] += size[tree[cur][i]];
			if(maxs < size[tree[cur][i]]){
				maxs = size[tree[cur][i]];
				hson[cur] = tree[cur][i];
			}
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
	if(l == r){
		seg[rt].val = e[rank[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt*2, l, mid);
	build(rt*2+1, mid+1, r);
	seg[rt].val = seg[rt*2].val ^ seg[rt*2+1].val;
}

void mod(int rt, int ind, int val){
	if(seg[rt].l == seg[rt].r && seg[rt].l == ind){
		seg[rt].val = val;
		return;
	}
	if(ind <= seg[rt*2].r){
		mod(rt*2, ind, val);
	}
	else{
		mod(rt*2+1, ind, val);
	}
	seg[rt].val = seg[rt*2].val ^ seg[rt*2+1].val;
}

int pfq(int l, int r){
	if(depth[l] > depth[r]) std::swap(l, r);
	int ans = 0;
	while(top[l] != top[r]){
		if(depth[top[l]] > depth[top[r]]){
			ans ^= query(1, dfn[top[l]], dfn[l]);
			l = fa[top[l]];
		}
		else{
			ans ^= query(1, dfn[top[r]], dfn[r]);
			r = fa[top[r]];
		}
	}

	ans ^= query(1, min(dfn[r], dfn[l]), max(dfn[r], dfn[l]));
	return ans;
}

int query(int rt, int l, int r){
	if(seg[rt].l == l && seg[rt].r == r){
		return seg[rt].val;
	}
	int ans = 0;
	if(seg[rt*2].r >= l){
		ans ^= query(rt*2, l, min(r, seg[rt*2].r));
	}
	if(seg[rt*2+1].l <= r){
		ans ^= query(rt*2+1, max(l, seg[rt*2+1].l), r);
	}
	return ans;
}
