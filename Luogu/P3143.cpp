#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn=5e4+5;
int n, k, a[Maxn], ll, rr, rl, lr, r, l, maxs, maxr, maxl, maxsl, maxsr;
int max(int a, int b) { return a>b?a:b; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	l=1; r=1;
	std::sort(a+1, a+1+n);
	for(r=1; r<=n; r++){
		while(a[r]-a[l]>k) l++;
		if(r-l+1>=maxs){
			maxs = r-l+1;
			maxr = r;
			maxl = l;
		}
	}
	ll=0; lr=maxr+1;
	for(rl=1; rl<maxl; rl++){
		while(a[rl]-a[ll]>k) ll++;
		if(rl-ll+1>maxsl){
			maxsl = rl-ll+1;
		}
	}
	for(rr=maxr; rr<=n; rr++){
		while(a[rr]-a[lr]>k) lr++;
		if(rr-lr+1>maxsr){
			maxsr = rr-lr+1;
		}
	}
	printf("%d", maxs+max(maxsl, maxsr));


	return 0;
}
