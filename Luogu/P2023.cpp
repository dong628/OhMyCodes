#include <cstdio>
#include <iostream>

typedef long long lol;
const int Maxn=1e5+5;
struct Node{
	int l, r;
	lol val, tagm, taga;
} seg[4*Maxn];
lol max(lol xx, lol yy) { return xx>yy?xx:yy; }
lol min(lol xx, lol yy) { return xx<yy?xx:yy; }
void build(int, int, int), update(int), mul(int, int, int, lol), add(int, int, int, lol);
lol sig(int, int, int);
int n, t, g, tp, m;
lol Mod, c, a[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %lld", &n, &Mod);
	for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
	build(1, 1, n);
	scanf("%d", &m);
	for(int csm=0; csm<m; csm++){
		scanf("%d", &tp);
		if(tp==1){
			scanf("%d %d %lld", &t, &g, &c);
			mul(1, t, g, c);
		}
		else if(tp==2){
			scanf("%d %d %lld", &t, &g, &c);
			add(1, t, g, c);
		}
		else{
			scanf("%d %d", &t, &g);
			printf("%lld\n", sig(1, t, g));
		}
	}

	return 0;
}

void build(int root, int l, int r){
	seg[root].l=l; seg[root].r=r;
	seg[root].tagm=1;
	if(l==r){
		seg[root].val=a[l]%Mod;
		return;
	}
	build(root<<1, l, (l+r)>>1);
	build((root<<1)+1, ((l+r)>>1)+1, r);
	seg[root].val = (seg[root<<1].val+seg[(root<<1)+1].val)%Mod;
}

void add(int root, int l, int r, lol addv){
	if(seg[root].l==l && seg[root].r==r){
		seg[root].val += (r-l+1)*addv%Mod;
		seg[root].val %= Mod;
		seg[root].taga += addv%Mod;
		seg[root].taga %= Mod;
		return;
	}
	update(root);
	seg[root].val = 0;
	if(seg[root<<1].r>=l){
		add(root<<1, l, min(seg[root<<1].r, r), addv);
	}
	seg[root].val += seg[root<<1].val;
	if(seg[(root<<1)+1].l<=r){
		add((root<<1)+1, max(seg[(root<<1)+1].l, l), r, addv);
	}
	seg[root].val += seg[(root<<1)+1].val;
	seg[root].val %= Mod;
}

void mul(int root, int l, int r, lol mulv){
	if(seg[root].l==l && seg[root].r==r){
		seg[root].val *= mulv%Mod;
		seg[root].val %= Mod;
		seg[root].taga *= mulv%Mod;
		seg[root].taga %= Mod;
		seg[root].tagm *= mulv%Mod;
		seg[root].tagm %= Mod;
		return;
	}
	update(root);
	seg[root].val = 0;
	if(seg[root<<1].r>=l){
		mul(root<<1, l, min(seg[root<<1].r, r), mulv);
	}
	seg[root].val += seg[root<<1].val;
	if(seg[(root<<1)+1].l<=r){
		mul((root<<1)+1, max(seg[(root<<1)+1].l, l), r, mulv);
	}
	seg[root].val += seg[(root<<1)+1].val;
	seg[root].val %= Mod;
}

lol sig(int root, int l, int r){
	if(seg[root].l==l && seg[root].r==r){
		return seg[root].val;
	}
	update(root);
	lol ans=0;
	if(seg[root<<1].r>=l){
		ans += sig(root<<1, l, min(seg[root<<1].r, r))%Mod;
	}
	if(seg[(root<<1)+1].l<=r){
		ans += sig((root<<1)+1, max(seg[(root<<1)+1].l, l), r)%Mod;
	}
	ans%=Mod;
	return ans;
}

void update(int root){
	seg[root<<1].val *= seg[root].tagm; seg[root<<1].val %= Mod;
	seg[root<<1].val += seg[root].taga*(seg[root<<1].r-seg[root<<1].l+1); seg[root<<1].val %= Mod;
	seg[(root<<1)+1].val *= seg[root].tagm; seg[(root<<1)+1].val %= Mod;
	seg[(root<<1)+1].val += seg[root].taga*(seg[(root<<1)+1].r-seg[(root<<1)+1].l+1); seg[(root<<1)+1].val %= Mod;
	seg[root<<1].taga *= seg[root].tagm; seg[root<<1].taga%=Mod;
	seg[root<<1].taga += seg[root].taga; seg[root<<1].taga%=Mod;
	seg[root<<1].tagm *= seg[root].tagm; seg[root<<1].tagm%=Mod;
	seg[(root<<1)+1].taga *= seg[root].tagm; seg[(root<<1)+1].taga%=Mod;
	seg[(root<<1)+1].taga += seg[root].taga; seg[(root<<1)+1].taga%=Mod;
	seg[(root<<1)+1].tagm *= seg[root].tagm; seg[(root<<1)+1].tagm%=Mod;
	seg[root].taga = 0; seg[root].tagm = 1;
}
