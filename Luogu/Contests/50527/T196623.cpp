#include <cstdio>
#include <iostream>

const int Maxn=1e5+5;
unsigned long long ans, n, a[Maxn], first;

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%llu", &n);
	for(int i=1; i<=n; i++){
		scanf("%llu", &a[i]);
		ans += a[i]-1;
	}
	if(a[1]==1){
		printf("1");
		return 0;
	}
	ans--;
	first = n+1;
	for(int i=2; i<=n; i++){
		if(a[i]>1){
			first = i;
			break;
		}
	}
	printf("%llu", ans*n+first);

	return 0;
}
