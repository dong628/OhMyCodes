#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using std::sort, std::unique, std::lower_bound, std::swap;

const int Maxn = 5e5+5, Maxsq = 750;
std::vector<int> mapp[Maxn];
int a[Maxn], cp[Maxn], cnt[Maxn], unm[Maxn], cntm[Maxn], zs[Maxsq][Maxsq];
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
		mapp[a[i]].push_back(i);
		unm[i] = cntm[a[i]]; cntm[a[i]]++;
	}
	block = sqrt(n);
	num = n/block;
	for(int i=0; i<num; i++){
		start[i] = i*block;
		end[i] = (i+1)*block;
	}
	if(n%block){
		start[num] = (num)*block;
		end[num] = n;
		num++;
	}

	for(int i=0; i<num; i++){
		memset(cnt, 0, sizeof(cnt));
		for(int j=i; j<num; j++){
			for(int k=start[j]; k<end[j]; k++){
				cnt[a[k]]++;
				zs[i][j] = std::max(zs[i][j], cnt[a[k]]);
			}
		}
	}


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
	int lb = l/block, rb = r/block, ans = 0;
	if(lb+1 <= rb-1) ans = zs[lb+1][rb-1];
	for(int i=l; i==l||i%block!=0; i++){
		while(cnt[i]>unm[i]+ans && mapp[i][unm[i]+ans]<=r){
			ans++;
		}
	}
	return ans+1;
}
