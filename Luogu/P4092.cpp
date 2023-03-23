#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
using std::max, std::min;

const int Maxn = 1e5+5;
//const int Maxn = 1e2+5;

struct Node{
	int l, r, tag, ttag;
} seg[4*Maxn];

std::vector <int> tree[Maxn];

int ts = 1;
int dfn[Maxn], rank[Maxn], size[Maxn], hson[Maxn], top[Maxn], fa[Maxn], depth[Maxn];

void dfs1(int, int), dfs2(int, int), tag(int, int), build(int, int, int), pushdown(int);
int query(int, int), spq(int);

int main(){
	freopen("data.in", "r", stdin);

	int n, q, u, v;
	scanf("%d %d\n", &n, &q);
	for(int i=1; i<n; i++){
		scanf("%d %d\n", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs1(1, 0); dfs2(1, 1);

	build(1, 1, n);
	tag(1, 1);

	char op;
	int num;
	while(q --> 0){
		scanf("%c %d\n", &op, &num);
		if(op == 'C'){
			tag(1, dfn[num]);
		}
		else{
			printf("%d\n", spq(num));
		}
	}

	return 0;
}

void dfs1(int cur, int f){
	fa[cur] = f;
	depth[cur] = depth[f] + 1;
	hson[cur] = -1;
	size[cur] = 1;
	int hmax = 0;
	for(int i=0; i<tree[cur].size(); i++){
		if(tree[cur][i] == f) continue;
		dfs1(tree[cur][i], cur);
		size[cur] += size[tree[cur][i]];
		if(hmax < size[tree[cur][i]]){
			hmax = size[tree[cur][i]];
			hson[cur] = tree[cur][i];
		}
	}
}

void dfs2(int cur, int t){
	top[cur] = t;
	dfn[cur] = ts;
	rank[ts] = cur;
	ts++;
	if(hson[cur] != -1) dfs2(hson[cur], t);
	for(int i=0; i<tree[cur].size(); i++){
		if(tree[cur][i] == fa[cur] || tree[cur][i] == hson[cur]) continue;
		dfs2(tree[cur][i], tree[cur][i]);
	}
}

void build(int rt, int l, int r){
	seg[rt].l = l; seg[rt].r = r;
	seg[rt].tag = 0;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(rt*2, l, mid);
	build(rt*2+1, mid+1, r);
}

void tag(int rt, int ind){
	if(seg[rt].l == seg[rt].r && seg[rt].l == ind){
		seg[rt].tag = ind;
		return;
	}
	pushdown(rt);
	if(seg[rt*2].r >= ind){
		tag(rt*2, ind);
		seg[rt*2+1].ttag = seg[rt*2+1].ttag > ind ? seg[rt*2+1].ttag : ind;
	}
	else{
		tag(rt*2+1, ind);
	}
}

int query(int rt, int ind){
	if(seg[rt].l == seg[rt].r && seg[rt].l == ind){
		return max(seg[rt].tag, seg[rt].ttag);
	}
	pushdown(rt);
	if(seg[rt*2].r >= ind){
		return query(rt*2, ind);
	}
	else{
		return query(rt*2+1, ind);
	}
}

void pushdown(int rt){
	int tmp = seg[rt].ttag;
	seg[rt*2].ttag = max(tmp, seg[rt*2].ttag);
	seg[rt*2+1].ttag = max(tmp, seg[rt*2+1].ttag);
	seg[rt].ttag = 0;
}

int spq(int cur){
	int tmp;
	while(top[cur] != 1 || cur != 1){
		tmp = query(1, dfn[cur]);
		if(tmp >= dfn[top[cur]] && tmp <= dfn[cur]){
			return rank[tmp];
		}
		else cur = fa[top[cur]];
	}
	return 1;
} 
