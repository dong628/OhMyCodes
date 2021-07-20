#include <cstdio>
#include <iostream>

const int Maxn=5e5+5;
int n, a[Maxn], c[Maxn];
long long ans;
long long MergeSort(int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	ans = MergeSort(1, n);
	printf("%lld", ans);

	return 0;
}

long long MergeSort(int l, int r){
	if(l==r) return 0;
	long long left = MergeSort(l, (l+r)>>1);
	long long right = MergeSort(((l+r)>>1)+1, r);
	int lp=l, rp=((l+r)>>1)+1, cp=1;
	long long cnt=0;
	while(lp<=((l+r)>>1) && rp<=r){
		while(a[lp] > a[rp] && rp<=r && lp<=((l+r)>>1)){
			c[cp++]=a[rp++];
		}
		while(a[lp] <= a[rp] && lp<=((l+r)>>1) && rp<=r){
			cnt += rp-((l+r)>>1)-1;
			c[cp++]=a[lp++];
		}
	}
	while(lp<=((l+r)>>1)){
		cnt += rp-((l+r)>>1)-1;
		c[cp++]=a[lp++];
	}
	while(rp<=r){
		c[cp++]=a[rp++];
	}
	for(int i=l, j=1; i<=r; i++, j++){
		a[i]=c[j];
	}
	return cnt+left+right;
}
