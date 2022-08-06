#include <cstdio>
#include <iostream>
#include <algorithm>
#define lind (ind<<1)
#define rind ((ind<<1)+1)
#define mid ((l+r)>>1)
using std::pair, std::make_pair, std::sort;

//const int Maxl = 1e1+5, Maxm = 5e2+5, Mod = 998244353;
const int Maxl = 1e5+5, Maxm = 5e5+5, Mod = 998244353;
typedef long long lol;
typedef pair<int, int> pii;
struct Node{
	int l, r, val;
} seg[Maxl*4];
struct Island{
	int l, r, h, lt, rt;
	lol mem;
} il[Maxm];
void build(int ind, int l, int r);
pii set(int ind, int l, int r, int val);
int query(int ind, int x);
lol dfs(int x);
bool cmp(Island a, Island b) { return a.h<b.h; }

int main(){
	freopen("data.in", "r", stdin);
	
	int n, m, x;
	lol ans = 0;
	pii tmp;
	scanf("%d %d", &n, &m);
	build(1, 1, Maxl);
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &il[i].l, &il[i].r, &il[i].h);
	}
	sort(il+1, il+m+1, cmp);
	for(int i=1; i<=m; i++){
		tmp = set(1, il[i].l, il[i].r, i);
		il[i].lt = tmp.first;
		il[i].rt = tmp.second;
	}

	for(int i=1; i<=n; i++){
		scanf("%d", &x);
		ans += dfs(query(1, x));
		ans %= Mod;
	}
	printf("%lld", ans);

	return 0;
}

void build(int ind, int l, int r){
	seg[ind].l = l; seg[ind].r = r;
	if(l==r) return;
	build(lind, l, mid);
	build(rind, mid+1, r);
}

pii set(int ind, int l, int r, int val){
	pii tmpl, tmpr;
	if(seg[ind].l==l && seg[ind].r==r && seg[ind].val!=0 || seg[ind].l==seg[ind].r){
		int tmp = seg[ind].val;
		seg[ind].val = val;
		return make_pair(tmp, tmp);
	}
	if(seg[ind].val != 0){
		seg[lind].val = seg[ind].val;
		seg[rind].val = seg[ind].val;
		seg[ind].val = 0;
	}
	if(r >= seg[rind].l){
		if(l >= seg[rind].l){
			return set(rind, l, r, val);
		}
		else{
			tmpl = set(lind, l, seg[lind].r, val);
			tmpr = set(rind, seg[rind].l, r, val);
			if(seg[rind].val == seg[lind].val && seg[lind].val != 0) seg[ind].val = seg[lind].val;
			return make_pair(tmpl.first, tmpr.second);
		}
	}
	else{
		return set(lind, l, r, val);
	}
}

int query(int ind, int x){
	if(seg[ind].val!=0 || seg[ind].l==seg[ind].r) return seg[ind].val;
	if(x >= seg[rind].l){
		return query(rind, x);
	}
	else{
		return query(lind, x);
	}
}

lol dfs(int x){
	if(x==0) return 1;
	if(il[x].mem != 0) return il[x].mem;
	if(il[x].lt != 0){
		il[x].mem += dfs(il[x].lt);
		il[x].mem %= Mod;
	}
	else il[x].mem++;
	if(il[x].rt != 0){
		il[x].mem += dfs(il[x].rt);
		il[x].mem %= Mod;
	}
	else il[x].mem++;
	il[x].mem %= Mod;
	return il[x].mem;
}
