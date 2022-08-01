#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using std::sort;

typedef long long lol;
const int Maxn = 1e6+5, Maxnsq = 1e3+5;
lol h[Maxn], copy[Maxn], tag[Maxnsq];
int n, q, tot, start[Maxn], end[Maxn], block;
int query(int, int, lol);
int lob(int, int, int);
void add(int, int, lol), update(int);

int main(){
	freopen("data.in", "r", stdin);
	freopen("djl.out", "w", stdout);

	scanf("%d %d", &n, &q);
	block = sqrt(n); tot = n/block;
	for(int i=0; i<tot; i++){
		start[i] = i*block;
		end[i] = (i+1)*block;
		for(int j=start[i]; j<end[i]; j++){
			scanf("%lld", &h[j]);
		}
	}
	start[tot] = tot*block; end[tot] = n;
	for(int i=tot*block; i<n; i++){
		scanf("%lld", &h[i]);
	}
	for(int i=0; i<n; i++) copy[i] = h[i];
	for(int i=0; i<tot; i++){
		sort(copy+start[i], copy+end[i]);
	}
	int l, r; lol w, c;
	char ty;
	getchar();
	while(q--){
		scanf("%c", &ty);
		if(ty == 'M'){
			scanf("%d %d %lld\n", &l, &r, &w);
			add(l-1, r-1, w);
		}
		else{
			scanf("%d %d %lld\n", &l, &r, &c);
			printf("%d\n", query(l-1, r-1, c));
		}
	}

	return 0;
}

void add(int l, int r, lol w){
	int lb = l/block, rb = r/block;
	if(lb!=rb){
		for(int i=l; i==l||i%block!=0; i++){
			h[i] += w;
		}
		update(lb);
		for(int i=r; i==r||i%block!=block-1; i--){
			h[i] += w;
		}
		update(rb);
	}
	else{
		for(int i=l; i<=r; i++){
			h[i] += w;
		}
		update(lb);
	}
	for(int i=lb+1; i<rb; i++){
		tag[i] += w;
	}
}

int query(int l, int r, lol c){
	int lb = l/block, rb = r/block, ans = 0;
	lol ct;
	if(lb!=rb){
		for(int i=l; i==l||i%block!=0; i++){
			if(h[i]+tag[lb] >= c) ans++;
		}
		for(int i=r; i==r||i%block!=block-1; i--){
			if(h[i]+tag[rb] >= c) ans++;
		}
	}
	else{
		for(int i=l; i<=r; i++){
			if(h[i]+tag[lb] >= c) ans++;
		}
	}
	for(int i=lb+1; i<rb; i++){
		ct = c-tag[i];
		ans += lob(start[i], end[i], ct);
//		ans += copy+(i+1)*block-lower_bound(copy+i*block, copy+(i+1)*block, ct);
	}
	return ans;
}

void update(int id){
	for(int i=start[id]; i<end[id]; i++){
		copy[i] = h[i]+tag[id];
		h[i] += tag[id];
	}
	tag[id] = 0;
	sort(copy+start[id], copy+end[id]);
}

int lob(int l, int r, int x){
	if(copy[r-1] < x) return 0;
	int rc = r, mid; r--;
	while(l<r){
		mid = (l+r+1)>>1;
		if(copy[mid]>=x) r = mid-1;
		else l = mid;
	}
	if(copy[r]>=x) return rc - r;
	else return rc - r - 1;
}
