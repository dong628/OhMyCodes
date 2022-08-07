#include <cstdio>
#include <iostream>

int main(){
	freopen("data.in", "r", stdin);

	int t;
	long long s, m;
	scanf("%d", &t);
	while(t--){
		scanf("%lld %lld", &s, &m);
		if(m==1 || (s&1)){
			printf("-1\n");
			continue;
		}
		printf("2 %lld %lld\n", s/2, s/2);
	}

	return 0;
}
