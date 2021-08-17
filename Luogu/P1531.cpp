#include <cstdio>
#include <iostream>

const int Maxn=2e5+5;
int max(int xx, int yy) { return xx>yy?xx:yy; }
int min(int xx, int yy) { return xx<yy?xx:yy; }
struct SegNode{
	int l, r, val;
}seg[4*Maxn];
char ch;
int x, y, l, r, n, m, a[Maxn], c[Maxn];
void build(int, int, int);
int getmax(int, int, int);
void update(int, int, int);

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d ", &a[i]);
	}
	scanf("\n");
	build(1, 1, n);
	for(int i=1; i<=m; i++){
		ch = getchar();
		if(ch=='Q'){
			scanf("%d %d\n", &l, &r);
			printf("%d\n", getmax(1, l, r));
		}
		else{
			scanf("%d %d\n", &x, &y);
			if(getmax(1, x, x)<y){
				update(1, x, y);
			}
		}
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
	seg[ind].val = max(seg[ind<<1].val, seg[(ind<<1)+1].val);
}

void update(int ind, int tar, int updv){
	if(seg[ind].l==tar && seg[ind].r==tar){
		seg[ind].val = updv;
		return;
	}

	if(tar<=seg[ind<<1].r){
		update(ind<<1, tar, updv);
	}
	if(tar>=seg[(ind<<1)+1].l){
		update((ind<<1)+1, tar, updv);
	}
	
	seg[ind].val = max(seg[ind<<1].val, seg[(ind<<1)+1].val);
}

int getmax(int ind, int l, int r){
	if(seg[ind].l==l && seg[ind].r==r){
		return seg[ind].val;
	}
	int ans=0;
	if(l<=seg[ind<<1].r){
		ans=max(ans, getmax(ind<<1, l, min(r, seg[ind<<1].r)));
	}
	if(r>=seg[(ind<<1)+1].l){
		ans=max(ans, getmax((ind<<1)+1, max(l, seg[(ind<<1)+1].l), r));
	}
	return ans;
} 
