#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using std::sort, std::unique, std::lower_bound, std::swap;

const int Maxn = 5e5+5, Maxsq = 750;
int a[Maxn], cp[Maxn], cnt[Maxsq][Maxn];
int start[Maxsq], end[Maxsq], block, num, ret[Maxn], cntu;

int calc(int l, int r);

int main(){
	freopen("data.in", "r", stdin);
	
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		cp[i] = a[i];
	}
	sort(cp, cp+n);
	cntu = unique(cp, cp+n)-cp;
	for(int i=0; i<n; i++){
		a[i] = lower_bound(cp, cp+cntu, a[i])-cp;
	}
	block = sqrt(n); num = n/block+1;
	for(int i=0; i<num-1; i++){
		start[i] = i*block;
		end[i] = (i+1)*block;
		for(int j=0; j<cntu; j++){
			cnt[i][j] = cnt[i-1][j];
		}
		for(int j=start[i]; j<end[i]; j++){
			cnt[i][a[j]]++;
		}
	}
	if((num-1)*block != n){
		start[num-1] = (num-1)*block;
		end[num-1] = n;
		for(int j=0; j<cntu; j++){
			cnt[num-1][j] = cnt[num-2][j];
		}
		for(int j=start[num-1]; j<end[num-1]; j++){
			cnt[num-1][a[j]]++;
		}
	}
	else num--;

	int l, r, ans = 0;

	while(m--){
		scanf("%d %d", &l, &r);
		l = l^ans;
		r = r^ans;
		if(l>r) swap(l, r);
		ans = calc(l-1, r-1);
		printf("%d\n", ans);
	}

	return 0;
}

int calc(int l, int r){
	int lb = l/block, rb = r/block;
	memset(ret, 0, sizeof(ret));
	if(lb!=rb){
		for(int i=l; i==l||i%block!=0; i++)
			ret[a[i]]++;
		for(int i=r; i==r||i%block!=block-1; i--)
			ret[a[i]]++;
		for(int j=0; j<cntu; j++){
			ret[j] += cnt[rb-1][j]-cnt[lb][j];
		}
	}
	else{
		for(int i=l; i<=r; i++)
			ret[a[i]]++;
	}
	int maxc = 0, maxans = 0;
	for(int i=0; i<cntu; i++){
		if(maxc < ret[i]){
			maxc = ret[i];
			maxans = i;
		}
	}
	return maxc;
}
