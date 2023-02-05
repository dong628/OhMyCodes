#include <cstdio>
#include <iostream>

const int Mod = 1e9+7;

int main(){
	int t;
	long long n, k;

	scanf("%d", &t);
	while(t --> 0){
		scanf("%lld %lld", &n, &k);
		if(k == 1){
			printf("1\n");
		}
		else if(k == 2){
			printf("2\n");
		}
		else if(k == 3){
			printf("%lld\n", n+2);
		}
		else if(k == 4){
			printf("%lld\n", n+n+2);
		}
		else if(k == 5){
			printf("%lld\n", (1+n+n+((n-1)*n)/2+n+1)%Mod);
		}
	}

	return 0;
}
