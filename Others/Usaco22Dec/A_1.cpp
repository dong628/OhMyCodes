#include <cstdio>
#include <iostream>
#include <algorithm>

const int Maxn = 1e5+5;
bool cmp(int x, int y) { return x > y; }
int c[Maxn];

int main(){
//	freopen("data.in", "r", stdin);

	int n, ansc;
	long long ans = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &c[i]);
	}
	std::sort(c+1, c+1+n, cmp);
	for(long long i=1; i<=n; i++){
		if(ans <= i*c[i]){
			ans = i * c[i];
			ansc = c[i];
		}
	}
	
	printf("%lld %d", ans, ansc);

	return 0;
}
