#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int Maxn = 1e6+5;
int n, q, a[Maxn], sa[Maxn], st[Maxn], end[Maxn], tag[Maxn], block, cb;

void add(int, int, int);
int query(int, int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &q);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		sa[i] = a[i];
	}
	scanf("\n");

	block = sqrt(n); cb = n/block;
	for(int i=0; i<cb; i++){
		st[i] = i*block; end[i] = (i+1)*block-1;
		std::sort(sa+st[i], sa+end[i]+1);
	}
	if(n % block){
		st[cb] = cb*block; end[cb] = n-1;
		std::sort(sa+st[cb], sa+end[cb]+1);
		cb++;
	}

	int l, r, w;
	char opt;
	while(q --> 0){
		opt = getchar();
		if(opt == 'M'){
			scanf("%d %d %d\n", &l, &r, &w);
			add(l-1, r-1, w);
		}
		else{
			scanf("%d %d %d\n", &l, &r, &w);
			printf("%d\n", query(l-1, r-1, w));
		}
	}

	return 0;
}

void add(int l, int r, int w){
	int lb = l/block, rb = r/block;
	if(lb == rb){
		for(int i=l; i<=r; i++){
			a[i] += w;
		}
		for(int i=st[lb]; i<=end[lb]; i++){
			sa[i] = a[i];
		}
		std::sort(sa+st[lb], sa+end[lb]+1);
	}
	else{
		for(int i=l; i<=end[lb]; i++){
			a[i] += w;
		}
		for(int i=st[lb]; i<=end[lb]; i++){
			sa[i] = a[i];
		}
		std::sort(sa+st[lb], sa+end[lb]+1);

		for(int i=st[rb]; i<=r; i++){
			a[i] += w;
		}
		for(int i=st[rb]; i<=end[rb]; i++){
			sa[i] = a[i];
		}
		std::sort(sa+st[rb], sa+end[rb]+1);

		for(int i=lb+1; i<rb; i++){
			tag[i] += w;
		}
	}
}

int query(int l, int r, int c){
	int lb = l/block, rb = r/block, ans = 0;
	if(lb == rb){
		for(int i=l; i<=r; i++){
			if(a[i] + tag[lb] >= c) ans++;
		}
	}
	else{
		for(int i=l; i<=end[lb]; i++){
			if(a[i] + tag[lb] >= c) ans++;
		}
		for(int i=st[rb]; i<=r; i++){
			if(a[i] + tag[rb] >= c) ans++;
		}

		for(int i=lb+1; i<rb; i++){
			ans += (sa+end[i]+1) - std::lower_bound(sa+st[i], sa+end[i]+1, c-tag[i]);
		}
	}
	return ans;
}
