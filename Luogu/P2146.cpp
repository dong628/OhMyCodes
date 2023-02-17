#include <cstdio>
#include <iostream>
#include <vector>
using std::max, std::min;

//const int Maxn = 105;
const int Maxn = 1e5+5;

struct Node{
	int l, r, val, tag;
} seg[4*Maxn];

std::vector <int> tree[Maxn];

void dfs1(int), dfs2(int, int);
void add(int, int, int), del(int, int, int), addsp(int), build(int, int, int);
void update(int);
int qsp(int), query(int, int, int);

int ts = 1, n;
int fa[Maxn], depth[Maxn], hson[Maxn], dfn[Maxn], rank[Maxn], top[Maxn], size[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);

	for(int i=1; i<n; i++){
		scanf("%d", &fa[i]);
		tree[fa[i]].push_back(i);
	}
	fa[0] = -1;
	depth[0] = 1;
	dfs1(0); dfs2(0, 0);
	build(1, 0, n);

	int q;
	scanf("%d\n", &q);
	char opt;
	int x;
	while(q --> 0){
		opt = getchar();
		if(opt == 'i'){
			for(int i=0; i<7; i++) getchar();
			scanf("%d\n", &x);
			printf("%d\n", depth[x] - qsp(x));
			addsp(x);
		}
		else{
			for(int i=0; i<9; i++) getchar();
			scanf("%d\n", &x);
			printf("%d\n", query(1, dfn[x], dfn[x] + size[x] - 1));
			del(1, dfn[x], dfn[x] + size[x] - 1);
		}
	}

	return 0;
}

void dfs1(int cur){
	int maxs = 0;
	hson[cur] = -1;
	size[cur] = 1;
	for(int i=0; i<tree[cur].size(); i++){
		depth[tree[cur][i]] = depth[cur] + 1;
		dfs1(tree[cur][i]);
		size[cur] += size[tree[cur][i]];
		if(maxs < size[tree[cur][i]]){
			maxs = size[tree[cur][i]];
			hson[cur] = tree[cur][i];
		}
	}
}

void dfs2(int cur, int t){
	dfn[cur] = ts;
	rank[ts] = cur;
	ts++;
	top[cur] = t;
	if(hson[cur] != -1){
		dfs2(hson[cur], t);
	}
	for(int i=0; i<tree[cur].size(); i++){
		if(tree[cur][i] != hson[cur]){
			dfs2(tree[cur][i], tree[cur][i]);
		}
	}
}

void addsp(int x){
	while(x != -1){
		add(1, dfn[top[x]], dfn[x]);
		x = fa[top[x]];
	}
}

void build(int rt, int l, int r){
	seg[rt].l = l; seg[rt].r = r;
	if(l == r) return;
	int mid = (l+r) >> 1;
	build(rt*2, l, mid);
	build(rt*2+1, mid+1, r);
}

void add(int rt, int l, int r){
	if(seg[rt].l == l && seg[rt].r == r){
		seg[rt].val = (r - l + 1);
		seg[rt].tag = 1;
		return;
	}
	if(seg[rt*2].r >= l){
		add(rt*2, l, min(seg[rt*2].r, r));
	}
	if(seg[rt*2+1].l <= r){
		add(rt*2+1, max(seg[rt*2+1].l, l), r);
	}
	seg[rt].val = seg[rt*2].val + seg[rt*2+1].val;
}

void del(int rt, int l, int r){
	if(seg[rt].l == l && seg[rt].r == r){
		seg[rt].val = 0;
		seg[rt].tag = -1;
		return;
	}
	if(seg[rt*2].r >= l){
		del(rt*2, l, min(seg[rt*2].r, r));
	}
	if(seg[rt*2+1].l <= r){
		del(rt*2+1, max(seg[rt*2+1].l, l), r);
	}
	seg[rt].val = seg[rt*2].val + seg[rt*2+1].val;
}

int query(int rt, int l, int r){
	if(seg[rt].l == l && seg[rt].r == r){
		return seg[rt].val;
	}
	int ans = 0;
	update(rt);
	if(seg[rt*2].r >= l){
		ans += query(rt*2, l, min(seg[rt*2].r, r));
	}
	if(seg[rt*2+1].l <= r){
		ans += query(rt*2+1, max(seg[rt*2+1].l, l), r);
	}
	return ans;
}

void update(int rt){
	if(seg[rt].tag == 0) return;
	if(seg[rt].tag == 1){
		seg[rt*2].val = seg[rt*2].r - seg[rt*2].l + 1;
		seg[rt*2+1].val = seg[rt*2+1].r - seg[rt*2+1].l + 1;
		seg[rt*2].tag = 1;
		seg[rt*2+1].tag = 1;
		seg[rt].tag = 0;
	}
	else{
		seg[rt*2].val = 0;
		seg[rt*2+1].val = 0;
		seg[rt*2].tag = -1;
		seg[rt*2+1].tag = -1;
		seg[rt].tag = 0;
	}
}

int qsp(int x){
	int ans = 0;
	while(x != -1){
		ans += query(1, dfn[top[x]], dfn[x]);
		x = fa[top[x]];
	}
	return ans;
}
