#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;
LL n, id, maxx, cnt;
int t;
LL calc(LL);

int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d", &t);
//	printf("%lld\n", calc(6));
	for(int x=0; x<t; x++){
		scanf("%lld", &n);
		if(n==1){
			printf("1 1\n");
			continue;
		}
		for(LL i=n/2; i<=n; i++){
			cnt=calc(i);
			if(cnt>maxx){
				maxx=cnt;
				id=i;
			}
		}
		printf("%lld %lld\n", id, maxx);
	}

	return 0;
}

LL calc(LL x){
	LL ans=1, a;
	for(LL i=2; i<=sqrt(double(x)); i++){
		a=0;
		while(x%i==0){
			x/=i; a++;
		}
		ans*=(a+1);
	}
	if(x!=1) ans*=2;
	return ans;
}
