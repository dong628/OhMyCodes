#include <cstdio>
#include <iostream>

const int Maxn = 105;
long long a[Maxn], b[Maxn], c[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	int t;
	long long n, tc, tm, ttc, ttm;
	bool flag;

	scanf("%d", &t);
	while(t --> 0){
		scanf("%lld %lld %lld", &n, &tc, &tm);
		for(int i=1; i<=n; i++){
			scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
		}
		for(int i=0; i<=tc+tm; i++){
			flag = false;
			for(int j=std::max((long long)0, i-tm); j<=std::min((long long)(i), tc); j++){
				ttc = tc - j;
				ttm = tm - (i - j);
				flag = true;
				for(int k=1; k<=n; k++){
					if(a[k]*ttc + b[k]*ttm > c[k]){
						flag = false;
						break;
					}
				}
				if(flag){
					printf("%d\n", i);
					break;
				}
			}
			if(flag) break;
		}
	}

	return 0;
}
