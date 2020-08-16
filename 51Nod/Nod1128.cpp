#include <cstdio>
#include <iostream>

const int Max=505;
long long sum;
int a[Max], n, k;
int zs(long long);

int main(){
	freopen("data.in", "r", stdin);
	
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		sum+=a[i];
	}
	long long l=1, r=sum, mid;
	while(l<r){
		mid=(l+r)>>1;
		if(zs(mid)<=k) r=mid;
		else l=mid+1;
	}
	printf("%lld", l);

	return 0;
}

int zs(long long l){
	long long now=0; 
	int cnt=0;
	for(int i=0; i<n-1; i++){
		if(now+a[i]>l){
			cnt++;
			now=a[i];
		}
		else{
			now+=a[i];
		}
	}
	if(now+a[n-1]<=l) return cnt+1;
	else return cnt+2;
}
