#include <cstdio>
#include <iostream>
#include <algorithm>

const int Max=100005;
long long sum;
int a[Max], n, k;
int zs(int);
inline int uf(double x){
	return x==int(x)?int(x):int(x)+1;
}

int main(){
	freopen("data.in", "r", stdin);
	
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	std::sort(a, a+n);
	int l=1, r=a[n-1]-a[0], mid;
	while(l<r){
		mid=uf(double(l+r)/2);
		if(zs(mid)<k) r=mid-1;
		else l=mid;
	}
	printf("%d", l);

	return 0;
}

int zs(int l){
	int cnt=0;
	int now=a[0];
	for(int i=1; i<n-1; i++){
		if(a[i]-now>=l){
			cnt++;
			now=a[i];
		}
	}
	if(a[n-1]-now>=l) return cnt+2;
	else return cnt+1;
}
