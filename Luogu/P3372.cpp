#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

const int Maxn=1e5+5;
typedef long long lol;
struct SegNode{
	int l, r;
	lol val, tag;
} seg[4*Maxn];
int n, m, tp, x, y;
lol a[Maxn], k;
int max(int xx, int yy) { return xx>yy?xx:yy; }
int min(int xx, int yy) { return xx<yy?xx:yy; }
void build(int, int, int);
lol getsum(int, int, int);
void add(int, int, int, lol);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	for(int cs=1; cs<=m; cs++){
		scanf("%d", &tp);
		if(tp==1){
			scanf("%d %d %lld", &x, &y, &k);
			add(1, x, y, k);
		}
		else{
			scanf("%d %d", &x, &y);
			printf("%lld\n", getsum(1, x, y));
		}
	}
return 0;
}

void build(int ind, int l, int r){
	seg[ind].l=l; seg[ind].r=r;
	if(l==r){
		seg[ind].val=a[l];
		return;
	}
	int midd = (l+r)>>1;
	build(ind<<1, l, midd);
	build((ind<<1)+1, midd+1, r);
	seg[ind].val = seg[ind<<1].val + seg[(ind<<1)+1].val;
}

lol getsum(int ind, int l, int r){
	if(seg[ind].l==l && seg[ind].r==r){
		return seg[ind].val;
	}
	lol ans=0;
	if(seg[ind].tag != 0){
		seg[ind<<1].tag += (seg[ind].tag/(seg[ind].r-seg[ind].l+1))*(seg[ind<<1].r-seg[ind<<1].l+1);
		seg[ind<<1].val += (seg[ind].tag/(seg[ind].r-seg[ind].l+1))*(seg[ind<<1].r-seg[ind<<1].l+1);
		seg[(ind<<1)+1].tag += (seg[ind].tag/(seg[ind].r-seg[ind].l+1))*(seg[(ind<<1)+1].r-seg[(ind<<1)+1].l+1);
		seg[(ind<<1)+1].val += (seg[ind].tag/(seg[ind].r-seg[ind].l+1))*(seg[(ind<<1)+1].r-seg[(ind<<1)+1].l+1);
		seg[ind].tag = 0;
	}
//	ind <<= 1;
	if(seg[ind<<1].r>=l) {
		ans+=getsum(ind<<1, l, min(seg[ind<<1].r, r));
	}
	if(seg[(ind<<1)+1].l<=r) {
		ans+=getsum((ind<<1)+1, max(seg[(ind<<1)+1].l, l), r);
	}
	return ans;
}

void add(int ind, int l, int r, lol addv){
	if(seg[ind].l==l && seg[ind].r==r){
		seg[ind].val += addv*(r-l+1);
		seg[ind].tag += addv*(r-l+1);
		return;
	}
	if(seg[ind].tag != 0){
		seg[ind<<1].tag += (seg[ind].tag/(seg[ind].r-seg[ind].l+1))*(seg[ind<<1].r-seg[ind<<1].l+1);
		seg[ind<<1].val += (seg[ind].tag/(seg[ind].r-seg[ind].l+1))*(seg[ind<<1].r-seg[ind<<1].l+1);
		seg[(ind<<1)+1].tag += (seg[ind].tag/(seg[ind].r-seg[ind].l+1))*(seg[(ind<<1)+1].r-seg[(ind<<1)+1].l+1);
		seg[(ind<<1)+1].val += (seg[ind].tag/(seg[ind].r-seg[ind].l+1))*(seg[(ind<<1)+1].r-seg[(ind<<1)+1].l+1);
		seg[ind].tag = 0;
	}
	seg[ind].val=0;
	if(seg[ind<<1].r>=l) {
		add(ind<<1, l, min(seg[ind<<1].r, r), addv);
	}
	seg[ind].val += getsum(ind<<1, seg[ind<<1].l, seg[ind<<1].r);
	if(seg[(ind<<1)+1].l<=r) {
		add((ind<<1)+1, max(seg[(ind<<1)+1].l, l), r, addv);
	}
	seg[ind].val += getsum((ind<<1)+1, seg[(ind<<1)+1].l, seg[(ind<<1)+1].r);
}
