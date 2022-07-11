#include <cstdio>
#include <iostream>
using namespace std;

const int Maxn = 1e5+5;
typedef long long lol;
struct Node{
	int l, r;
	lol taga, tagm, val;
}seg[Maxn*4];
int n, m, p, a[Maxn], mode, x, y;
lol k;
void update(int), mul(int, int, int, lol), add(int, int, int, lol), build(int, int, int);
lol sum(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %d", &n, &m, &p);
	for(int csn=0; csn<n; csn++){
		scanf("%d", &a[csn]);
	}
	build(1, 0, n);
	for(int csm=0; csm<m; csm++){
		scanf("%d", &mode);
		switch(mode){
			case 1: scanf("%d %d %lld", &x, &y, &k); mul(1, x-1, y, k); break;
			case 2: scanf("%d %d %lld", &x, &y, &k); add(1, x-1, y, k); break;
			case 3: scanf("%d %d", &x, &y); printf("%lld\n", sum(1, x-1, y)%p); break;
		}
	}

	return 0;
}

void build(int cur, int l, int r){
	seg[cur].l = l; seg[cur].r = r; seg[cur].tagm = 1;
	if(l==r-1){
		seg[cur].val = a[l];
		return;
	}
	build(cur<<1, l, (l+r)>>1);
	build((cur<<1)+1, (l+r)>>1, r);
	seg[cur].val = seg[cur<<1].val + seg[(cur<<1)+1].val; seg[cur].val %= p;
	return;
}

void add(int cur, int l, int r, lol num){
	if(seg[cur].l==l && seg[cur].r==r){
		seg[cur].taga += num;
		seg[cur].val += num*(r-l);
		return;
	}
	update(cur);
	if(seg[cur<<1].r>l) add(cur<<1, l, min(r, seg[cur<<1].r), num);
	if(seg[(cur<<1)+1].l<r) add((cur<<1)+1, max(l, seg[(cur<<1)+1].l), r, num);
	seg[cur].val = seg[cur<<1].val + seg[(cur<<1)+1].val; seg[cur].val %= p;
}

void mul(int cur, int l, int r, lol num){
	if(seg[cur].l==l && seg[cur].r==r){
		seg[cur].taga *= num; seg[cur].taga %= p;
		seg[cur].tagm *= num; seg[cur].tagm %= p;
		seg[cur].val *= num; seg[cur].val %= p;
		return;
	}
	update(cur);
	if(seg[cur<<1].r>l) mul(cur<<1, l, min(r, seg[cur<<1].r), num);
	if(seg[(cur<<1)+1].l<r) mul((cur<<1)+1, max(l, seg[(cur<<1)+1].l), r, num);
	seg[cur].val = seg[cur<<1].val + seg[(cur<<1)+1].val; seg[cur].val %= p;
}

lol sum(int cur, int l, int r){
	if(seg[cur].l==l && seg[cur].r==r){
		return seg[cur].val;
	}
	lol ans = 0;
	update(cur);
	if(seg[cur<<1].r>l) ans += sum(cur<<1, l, min(r, seg[cur<<1].r));
	if(seg[(cur<<1)+1].l<r) ans += sum((cur<<1)+1, max(l, seg[(cur<<1)+1].l), r);
	ans %= p;
	return ans;
}

void update(int cur){
	seg[cur<<1].taga *= seg[cur].tagm; seg[cur<<1].taga %= p;
	seg[(cur<<1)+1].taga *= seg[cur].tagm; seg[(cur<<1)+1].taga %= p;
	seg[cur<<1].taga += seg[cur].taga; seg[cur<<1].taga %= p;
	seg[(cur<<1)+1].taga += seg[cur].taga; seg[(cur<<1)+1].taga %= p;
	seg[cur<<1].tagm *= seg[cur].tagm; seg[cur<<1].tagm %= p;
	seg[(cur<<1)+1].tagm *= seg[cur].tagm; seg[(cur<<1)+1].tagm %= p;

	seg[cur<<1].val *= seg[cur].tagm; seg[cur<<1].val %= p;
	seg[(cur<<1)+1].val *= seg[cur].tagm; seg[(cur<<1)+1].val %= p;
	seg[cur<<1].val += seg[cur].taga*(seg[cur<<1].r-seg[cur<<1].l); seg[cur<<1].val %= p;
	seg[(cur<<1)+1].val += seg[cur].taga*(seg[(cur<<1)+1].r-seg[(cur<<1)+1].l); seg[(cur<<1)+1].val %= p;
	seg[cur].tagm = 1; seg[cur].taga = 0;

	return;
}
