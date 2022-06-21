#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using std::vector, std::max, std::min, std::swap;

typedef long long lol;
const int Maxn = 1e5+5;
struct Node{
	int l, r;
	lol val, taga;
}seg[4*Maxn];
vector<int> tr[Maxn];
int n, m, r, p, x, y, timetag, mode;
int dfn[Maxn], hson[Maxn], cnt[Maxn], rank[Maxn], fa[Maxn], top[Maxn], bottom[Maxn], size[Maxn], depth[Maxn];
bool vis[Maxn];
lol a[Maxn], z, hsons[Maxn];

void dfs1(int), dfs2(int);
void tadd(int, int, lol), sonadd(int, lol), add(int, int, int, lol), build(int, int, int), update(int);
lol tquery(int, int), sonquery(int), query(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d %d", &n,  &m, &r, &p);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i=1; i<n; i++){
		scanf("%d %d", &x, &y);
		tr[x].push_back(y); cnt[x]++;
		tr[y].push_back(x); cnt[y]++;
	}
	dfs1(1);
	memset(vis, 0, sizeof(vis));
	dfs2(1);
	build(1, 0, n);
	for(int i=1; i<m; i++){
		scanf("%d", &mode);
		switch(mode){
			case 1: scanf("%d %d %lld", &x, &y, &z); tadd(x, y, z); break;
			case 2: scanf("%d %d", &x, &y); printf("%lld\n", tquery(x, y)); break;
			case 3: scanf("%d %lld", &x, &z); sonadd(x, z); break;
			case 4: scanf("%d", &x); printf("%lld\n", sonquery(x)); break;
		}
	}

	return 0;
}

void dfs1(int root){
	vis[root] = true;
	for(int i=0; i<cnt[root]; i++){
		if(!vis[tr[root][i]]){
			fa[tr[root][i]] = root;
			depth[tr[root][i]] = depth[root]+1;
			dfs1(tr[root][i]);
			if(hsons[root]<size[tr[root][i]]){
				hson[root] = tr[root][i];
				hsons[root] = size[tr[root][i]];
			}
			size[root] = size[tr[root][i]];
		}
	}
}

void dfs2(int root){
	dfn[root] = timetag;
	rank[timetag] = root;
	timetag++;
	vis[root] = true;
	for(int i=0; i<cnt[root]; i++){
		if(!vis[tr[root][i]]){
			if(tr[root][i] == hson[root]){
				top[tr[root][i]] = top[root];
			}
			else{
				top[tr[root][i]] = tr[root][i];
			}
			dfs2(tr[root][i]);
		}
	}
	if(cnt[root] == 1) bottom[root] = root;
	else bottom[root] = bottom[tr[root][cnt[root]-1]];
}

void tadd(int x, int y, lol val){
	while(top[x]!=top[y]){
		if(depth[top[x]]>depth[top[y]]) swap(x, y);
		add(1, top[y], y, val);
		y = fa[top[y]];
	}
	add(1, top[x], x, val); add(1, top[y], y, val);
}

lol tquery(int x, int y){
	lol ans = 0;
	while(top[x]!=top[y]){
		if(depth[top[x]]>depth[top[y]]) swap(x, y);
		ans += query(1, top[y], y);
		y = fa[top[y]];
	}
	ans += query(1, hson[top[x]], x); ans += query(1, top[y], y);
	ans %= p;
	return ans;
}

void sonadd(int x, lol val){
	add(1, x, bottom[x], val);
}

lol sonquery(int x){
	return query(1, x, bottom[x]);
}

void build(int ind, int l, int r){
	seg[ind].l = l; seg[ind].r = r;
	if(l == r-1){
		seg[ind].val = a[rank[l]];
		return;
	}
	build(ind<<1, l, (l+r)>>1);
	build((ind<<1)+1, (l+r)>>1, r);
}

void add(int ind, int l, int r, lol val){
	seg[ind].val += val*(r-l+1);
	if(seg[ind].l==l && seg[ind].r==r){
		seg[ind].taga += val;
		return;
	}
	update(ind);
	if(seg[ind<<1].r > l){
		add(ind<<1, l, min((l+r)>>1, r), val);
	}
	if(seg[(ind<<1)+1].l < r){
		add((ind<<1)+1, max((l+r)>>1, l), r, val);
	}
}

lol query(int ind, int l, int r){
	if(seg[ind].l==l && seg[ind].r==r){
		return seg[ind].val;
	}
	lol ans = 0;
	update(ind);
	if(seg[ind<<1].r > l){
		ans += query(ind<<1, l, min((l+r)>>1, r));
	}
	if(seg[(ind<<1)+1].l < r){
		ans += query((ind<<1)+1, max((l+r)>>1, l), r);
	}
	ans %= p;
	return ans;
}

void update(int ind){
	seg[ind<<1].taga += seg[ind].taga; seg[ind<<1].taga %= p;
	seg[(ind<<1)+1].taga += seg[ind].taga; seg[(ind<<1)+1].taga %= p;
	seg[ind<<1].val += seg[ind].taga*(seg[ind<<1].r-seg[ind<<1].l+1); seg[ind<<1].val %= p;
	seg[(ind<<1)+1].val += seg[ind].taga*(seg[(ind<<1)+1].r-seg[(ind<<1)+1].l+1); seg[ind<<1].val %= p;
	seg[ind].taga = 0;
}
