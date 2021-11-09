#include <cstdio>
#include <iostream>

const int Maxn = 1e6+5;
bool buy[Maxn];
long long n, m, c, k, a[Maxn], orsum, p, q;

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	scanf("%lld %lld %lld %lld", &n, &m, &c, &k);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
		orsum |= a[i];
	}
	for(int i=1; i<=m; i++){
		scanf("%lld %lld", &p, &q);
		if(!((1<<p)&orsum)){
			buy[q] = true;
			k--;
		}
	}
	printf("%lld", (1<<k)-n);


	return 0;
}
