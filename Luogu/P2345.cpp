#include <cstdio>
#include <iostream>

const int Maxn=2e4+5;
int v[Maxn], x[Maxn], n;
long long ans;
int max(int a, int b) { return a>b?a:b; }
int abs(int a) { return a>0?a:-a; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &v[i], &x[i]);
	}
	for(int i=1; i<n; i++){
		for(int j=i; j<=n; j++){
			ans += max(v[i], v[j])*abs(x[i]-x[j]);
		}
	}
	printf("%lld", ans);
	
	return 0;
}
