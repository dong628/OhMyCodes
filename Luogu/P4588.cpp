#include <cstdio>
#include <iostream>

typedef long long lol;
const int Maxn = 1e5+5;
int t, q, op;
lol Mod, m;
struct Node{
	int l, r;
	lol val;
} seg[4*Maxn];
lol get(int);
void mul(int, int, lol), di(int, int), build(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &t);
	for(int cst=0; cst<t; cst++){
		scanf("%d %lld", &q, &Mod);
		build(1, 1, q);
		for(int i=1; i<=q; i++){
			scanf("%d %lld", &op, &m);
			if(op==1){
				mul(1, i, m);
				printf("%lld\n", seg[1].val);
			}
			else{
				di(1, m);
				printf("%lld\n", seg[1].val);
			}
		}
	}

	return 0;
}

void build(int ind, int l, int r){
	seg[ind].val = 1;
	seg[ind].l = l; seg[ind].r = r;
	if(l==r) return;
	build(ind<<1, l, (l+r)>>1);
	build((ind<<1)+1, ((l+r)>>1)+1, r);
}

void mul(int root, int ind, lol mulv){
	seg[root].val *= mulv%Mod;
	seg[root].val %= Mod;
	if(seg[root].l==ind && seg[root].r==ind){
		return;
	}
	if(ind<=seg[root<<1].r){
		mul(root<<1, ind, mulv);
	}
	else{
		mul((root<<1)+1, ind, mulv);
	}
}

void di(int root, int tar){
	seg[root].val = 1;
	if(seg[root].l==tar && seg[root].r==tar){
		return;
	}
	if(tar<=seg[root<<1].r){
		di(root<<1, tar);
	}
	else{
		di((root<<1)+1, tar);
	}
	seg[root].val = seg[root<<1].val*seg[(root<<1)+1].val%Mod;
	seg[root].val %= Mod;
}
