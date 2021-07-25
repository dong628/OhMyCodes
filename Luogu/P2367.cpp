#include <cstdio>
#include <iostream>

const int Maxn=5e6+5;
int n, p, a[Maxn], cf[Maxn], summ[Maxn], minn=0x7fffffff, x, y, z;

int main(){
	scanf("%d %d", &n, &p);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=n; i++){
		cf[i]=a[i]-a[i-1];
	}
	for(int i=1; i<=p; i++){
		scanf("%d %d %d", &x, &y, &z);
		cf[x]+=z; cf[y+1]-=z;
	}
	for(int i=1; i<=n; i++){
		summ[i]=summ[i-1]+cf[i];
		minn=minn<summ[i]?minn:summ[i];
	}
	printf("%d", minn);

	return 0;
}
