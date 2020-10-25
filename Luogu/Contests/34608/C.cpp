#include <cstdio>
#include <iostream>

int n;
long long k, modd, a, ans;

int main(){
	scanf("%d %lld %lld", &n, &k, &modd);
	if(k==0){
		for(int i=0; i<n; i++){
			scanf("%lld", &a);
			ans+=a*a;
			ans%=modd;
		}
	}
	else{
		for(int i=1; i<=k; i++){
			ans+=i*(n-i+1);
			ans%=modd;
		}
	}
	printf("%d", ans);

	return 0;
}
