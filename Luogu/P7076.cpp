#include <cstdio>
#include <iostream>

const int Maxn = 1e6+5;
bool vis[Maxn];
unsigned long long n, m, c, k, a, orsum;
int p, q;

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	scanf("%llu %llu %llu %llu", &n, &m, &c, &k);
	for(int i=1; i<=n; i++){
		scanf("%llu", &a);
		orsum |= a;
	}
	for(int i=1; i<=m; i++){
		scanf("%d %d", &p, &q);
		if(!((1ull<<p)&orsum) && (!vis[p])){
			vis[p] = true;
			k--;
		}
	}
	if(k==64 && n==0){
		printf("18446744073709551616");
	}
	else{
//		printf("%llu %llu\n", k, n);
		printf("%llu", ((1ull<<k)-n));
	}


	return 0;
}
