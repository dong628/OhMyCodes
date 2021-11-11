#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn = 1e5+5;
struct SegNode{
	int l, r, val;
}seg[4*Maxn];
int n, xrk, cnt;
int opt[Maxn], x[Maxn], mapp[Maxn];
void insert(int, int), del(int, int), build(int, int, int);
int low(int, int), qrk(int, int), last(int, int), next(int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &opt[i], &x[i]);
		mapp[i] = x[i];
	}
	std::sort(mapp+1, mapp+n+1);
	cnt = std::unique(mapp+1, mapp+n+1)-(mapp+1);
	build(1, 1, cnt);
	for(int i=1; i<=n; i++){
		xrk = std::lower_bound(mapp+1, mapp+n+1, x)-mapp;
		switch(opt[i]){
			case 1 : insert(1, xrk); break;
			case 2 : del(1, xrk); break;
			case 3 : printf("%d", low(1, xrk)); break;
			case 4 : printf("%d", qrk(1, xrk)); break;
			case 5 : printf("%d", last(1, xrk)); break;
			case 6 : printf("%d", next(1, xrk)); break;
		}
	}

	return 0;
}



int qrk(int root, int val){
	if(seg[root].l==seg[root].r && seg[root].val>=val) return seg[root].l;
	if(seg[root<<1].val>=val) return qrk(root<<1, val);
	else return qrk(root<<1+1, val-seg[root<<1].val);
}

int low(int root, int val){
	if(seg[root].r == val) return seg[root].val;
	if((seg[root].l+seg[root].r)>>1 >= val) return low(root<<1, val);
	else return seg[root<<1].val+low(root<<1+1, val);
}

void del(int root, int val){
	seg[root].val--;
	if(seg[root].l==val && seg[root].r==val) return;
	if((seg[root].l+seg[root].r)>>1 >= val) del(root<<1, val);
	else del(root<<1+1, val);
}

void insert(int root, int val){
	seg[root].val++;
	if(seg[root].l==val && seg[root].r==val) return;
	if((seg[root].l+seg[root].r)>>1 >= val) insert(root<<1, val);
	else insert(root<<1+1, val);
}

void build(int root, int l, int r){
	seg[root].l = l; seg[root].r = r;
	if(l==r) return;
	build(root<<1, l, (l+r)>>1);
	build(root<<1+1, (l+r)>>1+1, r);
}
