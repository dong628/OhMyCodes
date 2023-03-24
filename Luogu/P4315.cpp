#include <cstdio>
#include <iostream>
#include <vector>
using std::max, std::min, std::make_pair;

const int Maxn = 1e2+5, Inf = 0x7f7f7f7f;
//const int Maxn = 1e5+5;

struct Node{
	int l, r, max, tagp, tagc;
} seg[4*Maxn];
int fa[Maxn], depth[Maxn], size[Maxn], hson[Maxn], dfn[Maxn], rank[Maxn], top[Maxn], ts = 1;
int id[Maxn], val[Maxn];
std::vector <int> ids[Maxn];
std::vector < std::pair <int, int> > edges[Maxn];

void dfs1(int, int), dfs2(int, int);
void add(int, int, int, int), cover(int, int, int, int), change(int, int, int, int);
void build(int, int, int), pushdown(int);
void spch(int, int), spco(int, int, int), spadd(int, int, int);
int query(int, int, int), spq(int, int);

int main(){
	freopen("data.in", "r", stdin);

	int n, u, v, w, k;
	scanf("%d\n", &n);
	for(int i=1; i<n; i++){
		scanf("%d %d %d\n", &u, &v, &w);
		edges[u].push_back(make_pair(v, w));
		edges[v].push_back(make_pair(u, w));
		ids[u].push_back(i);
		ids[v].push_back(i);
	}
	dfs1(1, 0); dfs2(1, 1);

	for(int i=1; i<=n; i++){
		for(int j=0; j<edges[i].size(); j++){
			if(fa[i] == edges[i][j].first){
				val[i] = edges[i][j].second;
				id[i] = ids[i][j];
			}
		}
	}

	build(1, 1, n);

	char op[10];
	while(true){
		scanf("%s", op);
		if(op[1] == 'a'){
			scanf("%d %d\n", &u, &v);
			printf("%d\n", spq(u, v));
		}
		else if(op[1] == 'h'){
			scanf("%d %d\n", &k, &w);
			spch(k, w);
		}
		else if(op[1] == 'o'){
			scanf("%d %d %d\n", &u, &v, &w);
			spco(u, v, w);
		}
		else if(op[1] == 'd'){
			scanf("%d %d %d\n", &u, &v, &w);
			spadd(u, v, w);
		}
		else break;
	}

	return 0;
}

void dfs1(int cur, int f){
	fa[cur] = f;
	depth[cur] = depth[f] + 1;
	hson[cur] = -1;
	size[cur] = 1;
	int tar, hmax = 0;
	for(int i=0; i<edges[cur].size(); i++){
		tar = edges[cur][i].first;
		if(tar == f) continue;
		dfs1(tar, cur);
		size[cur] += size[tar];
		if(hmax < size[tar]){
			hson[cur] = tar;
			hmax = size[tar];
		}
	}
}

void dfs2(int cur, int t){
	dfn[cur] = ts;
	rank[ts] = cur;
	ts++;
	top[cur] = t;
	if(hson[cur] != -1) dfs2(hson[cur], t); 
	int tar;
	for(int i=0; i<edges[cur].size(); i++){
		tar = edges[cur][i].first;
		if(tar == fa[cur] || tar == hson[cur]) continue;
		dfs2(tar, tar);
	}
}

void build(int rt, int l, int r){
	seg[rt].l = l; seg[rt].r = r;
	if(l == r){
		seg[rt].max = val[rank[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt*2, l, mid);
	build(rt*2+1, mid+1, r);
}

void cover(int rt, int l, int r, int v){
	if(seg[rt].l == l && seg[rt].r == r){
		seg[rt].tagc = v;
		seg[rt].tagp = 0;
		seg[rt].max = v;
		return;
	}
	pushdown(rt);
	if(seg[rt*2].r >= l){
		cover(rt*2, l, min(r, seg[rt*2].r), v);
	}
	if(seg[rt*2+1].l <= r){
		cover(rt*2+1, max(l, seg[rt*2+1].l), r, v);
	}
	seg[rt].max = max(seg[rt*2].max, seg[rt*2+1].max);
}

void add(int rt, int l, int r, int v){
	if(seg[rt].l == l && seg[rt].r == r){
		seg[rt].tagp += v;
		seg[rt].max += v;
		return;
	}
	pushdown(rt);
	if(seg[rt*2].r >= l){
		add(rt*2, l, min(r, seg[rt*2].r), v);
	}
	if(seg[rt*2+1].l <= r){
		add(rt*2+1, max(l, seg[rt*2+1].l), r, v);
	}
	seg[rt].max = max(seg[rt*2].max, seg[rt*2+1].max);
}

void change(int rt, int ind, int v){
	if(seg[rt].l == ind && seg[rt].r == ind){
		seg[rt].max = v;
		seg[rt].tagc = 0;
		seg[rt].tagp = 0;
		return;
	}
	pushdown(rt);
	if(seg[rt*2].r >= ind){
		change(rt*2, ind, v);
	}
	else{
		change(rt*2+1, ind, v);
	}
}

int query(int rt, int l, int r){
	if(seg[rt].l == l && seg[rt].r == r){
		return seg[rt].max;
	}
	pushdown(rt);
	int ans = -Inf;
	if(seg[rt*2].r >= l){
		ans = max(ans, query(rt*2, l, min(r, seg[rt*2].r)));
	}
	if(seg[rt*2+1].l <= r){
		ans = max(ans, query(rt*2+1, max(l, seg[rt*2+1].l), r));
	}
	return ans;
}

void pushdown(int rt){
	if(seg[rt].tagc != 0){
		seg[rt*2].tagc = seg[rt].tagc + seg[rt].tagp;
		seg[rt*2].max = seg[rt].tagc + seg[rt].tagp;
		seg[rt*2+1].tagc = seg[rt].tagc + seg[rt].tagp;
		seg[rt*2+1].max = seg[rt].tagc + seg[rt].tagp;
		seg[rt].tagc = 1;
	}
	seg[rt*2].tagp += seg[rt].tagp;
	seg[rt*2+1].tagp += seg[rt].tagp;
	seg[rt].tagp = 0;
}

int spq(int u, int v){
	if(depth[u] > depth[v]) std::swap(u, v);
	int ans = -Inf;
	while(top[u] != top[v]){
		if(depth[top[u]] < depth[top[v]]){
			ans = max(ans, query(1, dfn[top[v]], dfn[v]));
			v = fa[top[v]];
		}
		else{
			ans = max(ans, query(1, dfn[top[u]], dfn[u]));
			u = fa[top[u]];
		}
	}
	if(depth[u] > depth[v]){
		ans = max(ans, query(1, dfn[v]+1, dfn[u]));
	}
	else if(depth[u] < depth[v]){
		ans = max(ans, query(1, dfn[u]+1, dfn[v]));
	}
	return ans;
}

void spch(int k, int w){
	change(1, dfn[id[k]], w);
}

void spco(int u, int v, int w){
	if(depth[u] > depth[v]) std::swap(u, v);
	while(top[u] != top[v]){
		if(depth[top[u]] < depth[top[v]]){
			cover(1, dfn[top[v]], dfn[v], w);
			v = fa[top[v]];
		}
		else{
			cover(1, dfn[top[u]], dfn[u], w);
			u = fa[top[u]];
		}
	}
	if(depth[u] > depth[v]){
		cover(1, dfn[v]+1, dfn[u], w);
	}
	else if(depth[u] < depth[v]){
		cover(1, dfn[u]+1, dfn[v], w);
	}
}

void spadd(int u, int v, int w){
	if(depth[u] > depth[v]) std::swap(u, v);
	while(top[u] != top[v]){
		if(depth[top[u]] < depth[top[v]]){
			add(1, dfn[top[v]], dfn[v], w);
			v = fa[top[v]];
		}
		else{
			add(1, dfn[top[u]], dfn[u], w);
			u = fa[top[u]];
		}
	}
	if(depth[u] > depth[v]){
		add(1, dfn[v]+1, dfn[u], w);
	}
	else if(depth[u] < depth[v]){
		add(1, dfn[u]+1, dfn[v], w);
	}
}
