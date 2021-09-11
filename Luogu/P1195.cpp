#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn=1e4+5;
int n, m, k, x[Maxn], y[Maxn], l[Maxn], ans;

int main(){
	scanf("%d %d %d", &n, &m, &k);
	if(n-m>k){
		printf("No Answer");
	}
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &x[i], &y[i], &l[i]);
	}
	std::sort(l+1, l+m+1);
	for(int i=1; i<=(n-k); i++){
		ans+=l[i];
	}
	printf("%d", ans);

	return 0;
}
