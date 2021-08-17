#include <cstdio>
#include <iostream>

const int Maxn=1e5+5, Mod=571373;
typedef long long lol;
struct SegNode{
	int l, r;
	lol val, tagp, tagm;
} seg[4*Maxn];
lol a[Maxn], k;
int n, m, p, x, y, tp;
lol max(lol xx, lol yy) { return xx>yy?xx:yy; }
lol min(lol xx, lol yy) { return xx<yy?xx:yy; }
lol getsum(int, int, int);
void mul(int, int, int, lol);
void add(int, int, int, lol);
void build(int, int, int);
void update(int);

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	scanf("%d %d %d", &n, &m, &p);
	for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
	build(1, 1, n);
	for(int cs=1; cs<=m; cs++){
		scanf("%d", &tp);
		if(tp==1){
			scanf("%d %d %lld", &x, &y, &k);
			mul(1, x, y, k);
		}
		if(tp==2){
			scanf("%d %d %lld", &x, &y, &k);
			add(1, x, y, k);
		}
		if(tp==3){
			scanf("%d %d", &x, &y);
			printf("%lld\n", getsum(1, x, y));
		}
	}

	return 0;
}

void build(int ind, int l, int r){
	seg[ind].r=r; seg[ind].l=l;
	seg[ind].tagm=1;
	if(l==r){
		seg[ind].val = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(ind<<1, l, mid);
	build((ind<<1)+1, mid+1, r);
	seg[ind].val = (seg[ind<<1].val + seg[(ind<<1)+1].val)%Mod;
}

void update(int ind){
	if(seg[ind].tagm!=1){
		seg[ind<<1].val *= seg[ind].tagm;
		seg[ind<<1].val %= Mod;
		seg[ind<<1].tagm *= seg[ind].tagm;
		seg[ind<<1].tagm %= Mod;
		seg[ind<<1].tagp *= seg[ind].tagm;
		seg[ind<<1].tagp %= Mod;

		seg[(ind<<1)+1].val *= seg[ind].tagm;
		seg[(ind<<1)+1].val %= Mod;
		seg[(ind<<1)+1].tagm *= seg[ind].tagm;
		seg[(ind<<1)+1].tagm %= Mod;
		seg[(ind<<1)+1].tagp *= seg[ind].tagm;
		seg[(ind<<1)+1].tagp %= Mod;

		seg[ind].tagm=1;
	}
	if(seg[ind].tagp!=0){
		seg[ind<<1].val += seg[ind].tagp*(seg[ind<<1].r-seg[ind<<1].l+1);
		seg[ind<<1].val %= Mod;
		seg[ind<<1].tagp += seg[ind].tagp;
		seg[ind<<1].tagp %= Mod;

		seg[(ind<<1)+1].val += seg[ind].tagp*(seg[(ind<<1)+1].r-seg[(ind<<1)+1].l+1);
		seg[(ind<<1)+1].val %= Mod;
		seg[(ind<<1)+1].tagp += seg[ind].tagp;
		seg[(ind<<1)+1].tagp %= Mod;

		seg[ind].tagp=0;
	}

}

void add(int ind, int l, int r, lol addv){
	if(seg[ind].l==l && seg[ind].r==r){
		seg[ind].tagp += addv%Mod;
		seg[ind].val += addv*(r-l+1)%Mod;
		seg[ind].tagp %= Mod;
		seg[ind].val %= Mod;
		return;
	}
	
	update(ind);
	
	seg[ind].val = 0;
	if(seg[ind<<1].r>=l){
		add(ind<<1, l, min(r, seg[ind<<1].r), addv);
	}
	seg[ind].val += seg[ind<<1].val%Mod;
	if(seg[(ind<<1)+1].l<=r){
		add((ind<<1)+1, max(l, seg[(ind<<1)+1].l), r, addv);
	}
	seg[ind].val += seg[(ind<<1)+1].val%Mod;
	seg[ind].val %= Mod;
}

void mul(int ind, int l, int r, lol mulv){
	if(seg[ind].l==l && seg[ind].r==r){
		seg[ind].tagp *= mulv;
		seg[ind].tagp %= Mod;
		seg[ind].tagm *= mulv;
		seg[ind].tagm %= Mod;
		seg[ind].val *= mulv;
		seg[ind].val %= Mod;
		return;
	}

	update(ind);

	seg[ind].val = 0;
	if(seg[ind<<1].r>=l){
		mul(ind<<1, l, min(r, seg[ind<<1].r), mulv);
	}
	seg[ind].val += seg[ind<<1].val%Mod;
	if(seg[(ind<<1)+1].l<=r){
		mul((ind<<1)+1, max(l, seg[(ind<<1)+1].l), r, mulv);
	}
	seg[ind].val += seg[(ind<<1)+1].val%Mod;
	seg[ind].val %= Mod;
}

lol getsum(int ind, int l, int r){
	if(seg[ind].l==l && seg[ind].r==r){
		return seg[ind].val;
	}

	update(ind);

	int ans=0;
	if(seg[ind<<1].r>=l){
		ans += getsum(ind<<1, l, min(r, seg[ind<<1].r))%Mod;
	}
	if(seg[(ind<<1)+1].l<=r){
		ans += getsum((ind<<1)+1, max(l, seg[(ind<<1)+1].l), r)%Mod;
	}
	ans%=Mod;
	return ans;
}
