#include <cstdio>
#include <iostream>

const int Max=100005;
int n, m, maxx, a[Max];
long long summ;
int calc(int);
inline int uf(double x){
	return x==int(x)?int(x):int(x)+1;
}

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		summ+=a[i];
		maxx=a[i]>maxx?a[i]:maxx;
	}
	if(summ<(long long)(m)){
		printf("0");
		return 0;
	}
	int l=1, r=maxx, mid;
	while(l<r){
		mid=uf(double(l+r)/2);
		if(calc(mid)<m) r=mid-1;
		else l=mid;
	}
	printf("%d", l);

	return 0;
}

int calc(int l){
	int ans=0;
	for(int i=0; i<n; i++) ans+=a[i]/l;
	return ans;
}
