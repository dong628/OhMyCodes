#include <cstdio>
#include <iostream>
#include <vector>
#define int long long
using std::min, std::max;

const int Maxn = 1e5+5;
//const int Maxn = 105;

struct Node{
	int l, r, val, tag;
} seg[4*Maxn];

std::vector <int> tree[Maxn];

int n, ts = 1, a[Maxn];
int rank[Maxn], dfn[Maxn], depth[Maxn], fa[Maxn], hson[Maxn], size[Maxn], top[Maxn];

void dfs1(int, int), dfs2(int, int);
void build(int, int, int), add(int, int, int, int), update(int);
int sum(int, int, int), query(int);

signed main(){
	freopen("data.in", "r", stdin);

	int m, u, v, opt, x, b;

	scanf("%lld %lld", &n, &m);

	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i=1; i<n; i++){
		scanf("%lld %lld", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	for(int i=1; i<=n; i++) top[i] = i;
	dfs1(1, 0); dfs2(1, 1);
	build(1, 1, n);

	while(m --> 0){
		scanf("%lld", &opt);
		if(opt == 1){
			scanf("%lld %lld", &x, &b);
			add(1, rank[x], rank[x], b);
		}
		else if(opt == 2){
			scanf("%lld %lld", &x, &b);
			add(1, rank[x], rank[x]+size[x]-1, b);
		}
		else{
			scanf("%lld", &x);
			printf("%lld\n", query(x));
		}
	}

	return 0;
}

void dfs1(int cur, int fat){
	fa[cur] = fat;
	depth[cur] = depth[fat] + 1;
	size[cur] = 1;
	int smax = 0;
	for(int i=0; i<tree[cur].size(); i++){
		if(tree[cur][i] == fat) continue;
		dfs1(tree[cur][i], cur);
		size[cur] += size[tree[cur][i]];
		if(smax < size[tree[cur][i]]){
			smax = size[tree[cur][i]];
			hson[cur] = tree[cur][i];
		}
	}
}

void dfs2(int cur, int t){
	dfn[cur] = ts++;
	rank[ts-1] = cur;
	top[cur] = t;
	if(hson[cur] != 0) dfs2(hson[cur], t);
	for(int i=0; i<tree[cur].size(); i++){
		if(tree[cur][i] == fa[cur] || tree[cur][i] == hson[cur]) continue;
		dfs2(tree[cur][i], tree[cur][i]);
	}
}

void build(int rt, int l, int r){
	seg[rt].l = l; seg[rt].r = r;
	if(l == r){
		seg[rt].val = a[rank[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt*2, l, mid);
	build(rt*2+1, mid+1, r);
	seg[rt].val = seg[rt*2].val + seg[rt*2+1].val;
}

void add(int rt, int l, int r, int val){
	seg[rt].val += (r-l+1) * val;
	if(seg[rt].l == l && seg[rt].r == r){
		seg[rt].tag += val;
		return;
	}
	if(seg[rt*2].r >= l){
		add(rt*2, l, min(r, seg[rt*2].r), val);
	}
	if(seg[rt*2+1].l <= r){
		add(rt*2+1, max(l, seg[rt*2+1].l), r, val);
	}
	return;
}

int query(int x){
	int cur = x, ans = 0;
	while(cur != 0){
		ans += sum(1, dfn[top[cur]], dfn[cur]);
		cur = fa[top[cur]];
	}
	return ans;
}

int sum(int rt, int l, int r){
	if(seg[rt].l == l && seg[rt].r == r){
		return seg[rt].val;
	}
	int ans = 0;
	update(rt);
	if(seg[rt*2].r >= l){
		ans += sum(rt*2, l, min(r, seg[rt*2].r));
	}
	if(seg[rt*2+1].l <= r){
		ans += sum(rt*2+1, max(l, seg[rt*2+1].l), r);
	}
	return ans;
}

void update(int rt){
	seg[rt*2].val += seg[rt].tag * (seg[rt*2].r - seg[rt*2].l + 1);
	seg[rt*2+1].val += seg[rt].tag * (seg[rt*2+1].r - seg[rt*2+1].l + 1);
	seg[rt*2].tag += seg[rt].tag;
	seg[rt*2+1].tag += seg[rt].tag;
	seg[rt].tag = 0;
}
