#include <cstdio>
#include <iostream>

const int Max=500005;
int a[Max], s[Max], f, n;
int calc(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &f, &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	s[0]=a[0];
	for(int i=1; i<n; i++){
		s[i]=s[i-1]+a[i];
	}
	if(s[n-1]<f){
		printf("0");
		return 0;
	}
	int l=1, r=n, mid;
	while(l<r){
		mid=(l+r)>>1;
		if(calc(mid)>=f) r=mid;
		else l=mid+1;
	}
	printf("%d", l);

	return 0;
}

int calc(int x){
	int maxx=s[x-1];
	for(int i=0; i<n-x; i++){
		maxx=maxx>(s[i+x]-s[i])?maxx:(s[i+x]-s[i]);
	}
	return maxx;
}
