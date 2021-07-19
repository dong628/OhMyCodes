#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn=5e4+5;
int n, k, a[Maxn], q[Maxn], fr, ans, r;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	std::sort(a+1, a+1+n);
	a[n+1]=0x7fffffff;
	for(int i=1; i<=n; i++){
		while(a[r]-a[i]<=k) r++;
		q[r] = q[r]>r-i?q[r]:r-i;
		fr = fr>q[i]?fr:q[i];
		ans = ans>fr+r-i?ans:fr+r-i;
	}
	printf("%d", ans);

	return 0;
}
