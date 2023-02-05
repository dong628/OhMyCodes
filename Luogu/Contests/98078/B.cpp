#include <iostream>
#include <cstdio>

int main(){
	freopen("data.in", "r", stdin);

	int t;
	long long n, k, ans;
	scanf("%d", &t);
	while(t --> 0){
		ans = 0;
		scanf("%lld %lld", &n, &k);
		if(k == 2){
			printf("1\n");
			continue;
		}
		if(k < 4){
			printf("0\n");
			continue;
		}
		if(k > 4){
			if(n >= 2) ans++;
			if(n >= 3) ans++;
		}
		if(n == 1){
			printf("%lld\n", ans + 1);
			continue;
		}
		if(n == 2){
			printf("%lld\n", ans + 2);
			continue;
		}
		ans += n - 1 + n - 2;
		printf("%lld\n", ans);
	}

	return 0;
}
