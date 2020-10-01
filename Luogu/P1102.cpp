#include <cstdio>
#include <iostream>
#include <algorithm>

const int Max=2e5+5;
int n, len;
long long c, hash[Max], cnt[Max], a[Max], maxx, summ;
long long count(long long);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %lld", &n, &c);
	for(int i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	std::sort(a, a+n);
	maxx=a[n-1];
	for(int i=0; i<n; i++){
		if(hash[len]!=a[i]){
			hash[++len]=a[i];
		}
		cnt[len]++;
	}
	for(int i=0; i<n; i++){
		summ+=count(a[i]+c);
		if(a[i]+c>maxx) break;
	}
	printf("%lld", summ);

	return 0;
}

long long count(long long x){
	int l=0, r=len, mid;
	while(l<r){
		mid=(l+r)>>1;
		if(hash[mid]>=x) r=mid;
		else l=mid+1;
	}
	if(hash[l]==x) return cnt[l];
	else return 0;
}
