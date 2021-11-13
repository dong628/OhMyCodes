#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn = 1e5+5;
struct SegNode{
	int l, r, val;
}seg[4*Maxn];
bool flag;
int n, xrk, cnt, vval, ans;
int opt[Maxn], x[Maxn], mapp[Maxn];
void insert(int, int), del(int, int), build(int, int, int);
int low(int, int), qrk(int, int), last(int), next(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &opt[i], &x[i]);
		if(opt[i]!=4) mapp[cnt++] = x[i];
	}
	std::sort(mapp, mapp+cnt);
	cnt = std::unique(mapp, mapp+cnt)-mapp;
//	for(int i=0; i<cnt; i++){
//		printf("%d ", mapp[i]);
//	}
//	printf("\n");
	build(1, 1, cnt);
	for(int i=1; i<=n; i++){
		xrk = std::lower_bound(mapp, mapp+cnt, x[i])-mapp;
//		printf("xrk:%d\n", xrk);
		flag = false;
		switch(opt[i]){
			case 1 : insert(1, xrk+1); break;
			case 2 : del(1, xrk+1); break;
			case 3 : printf("%d\n", low(1, xrk+1)+1); break;
			case 4 : ans = qrk(1, x[i]); flag=true; break;
			case 5 : ans = last(xrk+1); flag=true; break;
			case 6 : ans = next(xrk+1); flag=true; break;
		}
		if(flag) printf("%d\n", mapp[ans-1]);
	}

	return 0;
}

int next(int val){
	return qrk(1, low(1, val+1)+1);
}

int last(int val){
//	printf("low:%d\n", low(1, val));
	return qrk(1, low(1, val));
}

/*
int next(int root, int val){
	if(seg[root].l+1==seg[root].r){
		return seg[(root<<1)+1].l;
	}
	if(seg[root].l==seg[root].r){
		return seg[root].l;
	}

	if(seg[(root<<1)+1].l>val){
		vval = next(root<<1, val);
		if(vval==val){
			return next((root<<1)+1, seg[(root<<1)+1].l);
		}
		else{
			return vval;
		}
	}
	else{
		return next((root<<1)+1, val);
	}
}

int last(int root, int val){
	if(seg[root].l+1==seg[root].r){
		if(seg[root<<1].val==0) return seg[root<<1].r;
		return seg[root<<1].l;
	}
	if(seg[root].l==seg[root].r){
		return seg[root].l;
	}

	if(seg[root<<1].r<val){
		vval = last((root<<1)+1, val);
		if(vval==val){
			return last(root<<1, seg[root<<1].r+1);
		}
		else{
			return vval;
		}
	}
	else{
		return last(root<<1, val);
	}
}
*/

int qrk(int root, int val){
	if(seg[root].l==seg[root].r && seg[root].val>=val) return seg[root].l;
	if(seg[root<<1].val>=val) return qrk(root<<1, val);
	else return qrk((root<<1)+1, val-seg[root<<1].val);
}

int low(int root, int val){
	if(seg[root].r < val) return seg[root].val;
	if(seg[root].l == seg[root].r) return 0;
	if((seg[root].l+seg[root].r)>>1 >= val) return low(root<<1, val);
	else return (seg[root<<1].val+low((root<<1)+1, val));
}

void del(int root, int val){
	seg[root].val--;
	if(seg[root].l==val && seg[root].r==val) return;
	if((seg[root].l+seg[root].r)>>1 >= val) del(root<<1, val);
	else del((root<<1)+1, val);
}

void insert(int root, int val){
	seg[root].val++;
	if(seg[root].l==val && seg[root].r==val) return;
	if((seg[root].l+seg[root].r)>>1 >= val) insert(root<<1, val);
	else insert((root<<1)+1, val);
}

void build(int root, int l, int r){
	seg[root].l = l; seg[root].r = r;
	if(l==r) return;
	build(root<<1, l, (l+r)>>1);
	build((root<<1)+1, ((l+r)>>1)+1, r);
}
