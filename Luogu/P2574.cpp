#include <cstdio>
#include <iostream>

const int Maxn=2e5+5;
struct SegNode{
	int l, r, val;
	bool tag;
}seg[4*Maxn];
int n, m, op, l, r, a[Maxn];
char ch;
int max(int xx, int yy) { return xx>yy?xx:yy; }
int min(int xx, int yy) { return xx<yy?xx:yy; }
void build(int, int, int);
void upd(int, int, int);
int getsum(int, int, int);

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	scanf("%d %d\n", &n, &m);
	for(int i=1; i<=n; i++){
		ch = getchar();
		a[i] = ch-'0';
	}
	build(1, 1, n);
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &op, &l, &r);
		if(op==0) upd(1, l, r);
		else printf("%d\n", getsum(1, l, r));
	}

	return 0;
}

void build(int ind, int l, int r){
	seg[ind].l=l; seg[ind].r=r;
	if(l==r){
		seg[ind].val = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(ind<<1, l, mid);
	build((ind<<1)+1, mid+1, r);
	seg[ind].val = seg[ind<<1].val + seg[(ind<<1)+1].val;
}

void upd(int ind, int l, int r){
	if(seg[ind].l==l && seg[ind].r==r){
		seg[ind].val = (seg[ind].r-seg[ind].l+1)-seg[ind].val;
		seg[ind].tag ^= true;
		return;
	}

	if(seg[ind].tag){
		seg[ind<<1].val = (seg[ind<<1].r-seg[ind<<1].l+1)-seg[ind<<1].val;
		seg[ind<<1].tag ^= true;
		seg[(ind<<1)+1].val = (seg[(ind<<1)+1].r-seg[(ind<<1)+1].l+1)-seg[(ind<<1)+1].val;
		seg[(ind<<1)+1].tag ^= true;
		seg[ind].tag=false;
	}

	seg[ind].val=0;
	if(seg[ind<<1].r>=l){
		upd(ind<<1, l, min(seg[ind<<1].r, r));
	}
	seg[ind].val += seg[ind<<1].val;
	if(seg[(ind<<1)+1].l<=r){
		upd((ind<<1)+1, max(seg[(ind<<1)+1].l, l), r);
	}
	seg[ind].val += seg[(ind<<1)+1].val;
}

int getsum(int ind, int l, int r){
	if(seg[ind].l==l && seg[ind].r==r){
		return seg[ind].val;
	}

	if(seg[ind].tag){
		seg[ind<<1].val = (seg[ind<<1].r-seg[ind<<1].l+1)-seg[ind<<1].val;
		seg[ind<<1].tag ^= true;
		seg[(ind<<1)+1].val = (seg[(ind<<1)+1].r-seg[(ind<<1)+1].l+1)-seg[(ind<<1)+1].val;
		seg[(ind<<1)+1].tag ^= true;
		seg[ind].tag=false;
	}

	int ans=0;

	if(seg[ind<<1].r>=l){
		ans += getsum(ind<<1, l, min(seg[ind<<1].r, r));
	}
	if(seg[(ind<<1)+1].l<=r){
		ans += getsum((ind<<1)+1, max(seg[(ind<<1)+1].l, l), r);
	}

	return ans;
}
