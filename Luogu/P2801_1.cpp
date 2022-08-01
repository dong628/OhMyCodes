#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using std::sort;

//const int Maxn = 1e2+5, Maxsq = 1e2+5;
const int Maxn = 1e6+5, Maxsq = 1e3+5;
int a[Maxn], cp[Maxn], start[Maxsq], end[Maxsq], tag[Maxsq];
int block, num;
void add(int, int, int), update(int);
int query(int, int, int), calc(int, int);

int main(){
	freopen("data.in", "r", stdin);

	int n, q;
	scanf("%d %d\n", &n, &q);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		cp[i] = a[i];
	}
	block = sqrt(n); num = n/block;
	for(int i=0; i<num; i++){
		start[i] = i*block;
		end[i] = (i+1)*block;
		sort(cp+start[i], cp+end[i]);
	}
	if(n%block != 0){
		start[num] = num*block;
		end[num] = n;
		sort(cp+start[num], cp+end[num]);
		num++;
	}

	char opt; int l, r, w;
	scanf("\n");
	while(q--){
		scanf("%c %d %d %d\n", &opt, &l, &r, &w);
		if(opt == 'M'){
			add(l-1, r-1, w);
		}
		else{
			printf("%d\n", query(l-1, r-1, w));
		}
	}

	return 0;
}

void add(int l, int r, int w){
	int lb = l/block, rb = r/block;
	if(lb != rb){
		for(int i=l; i==l||i%block!=0; i++){
			a[i] += w;
		}
		update(lb);
		for(int i=r; i==r||i%block!=block-1; i--){
			a[i] += w;
		}
		update(rb);
		for(int i=lb+1; i<rb; i++){
			tag[i] += w;
		}
	}
	else{
		for(int i=l; i<=r; i++){
			a[i] += w;
		}
		update(lb);
	}
}

int query(int l, int r, int w){
	int lb = l/block, rb = r/block, cnt = 0;
	if(lb != rb){
		for(int i=l; i==l||i%block!=0; i++){
			if(a[i] >= w-tag[lb]) cnt++;
		}
		for(int i=r; i==r||i%block!=block-1; i--){
			if(a[i] >= w-tag[rb]) cnt++;
		}
		for(int i=lb+1; i<rb; i++){
			cnt += calc(i, w-tag[i]);
		}
	}
	else{
		for(int i=l; i<=r; i++){
			if(a[i] >= w-tag[lb]) cnt++;
		}
	}
	return cnt;
}

void update(int id){
	for(int i=start[id]; i<end[id]; i++){
		a[i] += tag[id];
		cp[i] = a[i];
	}
	tag[id] = 0;
	sort(cp+start[id], cp+end[id]);
}

int calc(int id, int w){
	int l = start[id], r = end[id]-1, mid;
	if(cp[l] >= w) return r-l+1;
	else if(cp[r] < w) return 0;
	while(l < r){
		mid = (l+r)>>1;
		if(cp[mid] < w) l = mid+1;
		else r = mid;
	}
	return end[id] - l;
}
