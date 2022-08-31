#include <cstdio>
#include <iostream>

const int Maxn = 5e7+5, Maxm = 1e6+5;
struct Node{
	int l, r, lson, rson, val;
} seg[Maxn];
int top, ver, head[Maxm], a[Maxn];
int build(int l, int r);
int set(int cur, int loc, int val);
int query(int cur, int loc);

int main(){
	freopen("data.in", "r", stdin);
	
	int n, m, v, opt, loc, val;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	head[ver++] = build(0, n);
	while(m--){
		scanf("%d %d", &v, &opt);
		if(opt == 1){
			scanf("%d %d", &loc, &val);
			head[ver++] = set(head[v], loc-1, val);
		}
		else{
			scanf("%d", &loc);
			head[ver++] = head[v];
			printf("%d\n", query(head[v], loc-1));
		}
	}

	return 0;
}

int build(int l, int r){
	int cur = top; top++;
	seg[cur].l = l; seg[cur].r = r;
	if(l+1 == r){
		seg[cur].val = a[l];
		return cur;
	}
	int mid = (l+r)>>1;
	seg[cur].lson = build(l, mid);
	seg[cur].rson = build(mid, r);
	return cur;
}

int set(int cur, int loc, int val){
	int tmp = top; top++;
	if(seg[cur].l == loc && seg[cur].l+1 == seg[cur].r){
		seg[tmp].l = loc; seg[tmp].r = loc+1;
		seg[tmp].val = val;
		return tmp;
	}
	int mid = (seg[cur].l+seg[cur].r)>>1;
	seg[tmp].l = seg[cur].l; seg[tmp].r = seg[cur].r;
	if(loc < mid){
		seg[tmp].rson = seg[cur].rson;
		seg[tmp].lson = set(seg[cur].lson, loc, val);
	}
	else{
		seg[tmp].lson = seg[cur].lson;
		seg[tmp].rson = set(seg[cur].rson, loc, val);
	}
	return tmp;
}

int query(int cur, int loc){
	if(seg[cur].l == loc && seg[cur].l+1 == seg[cur].r){
		return seg[cur].val;
	}
	int mid = (seg[cur].l+seg[cur].r)>>1;
	if(loc < mid){
		return query(seg[cur].lson, loc);
	}
	else{
		return query(seg[cur].rson, loc);
	}
}
