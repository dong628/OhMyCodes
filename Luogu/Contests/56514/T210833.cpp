#include <cstdio>
#include <iostream>

int t;
long long n, ans;

int main(){
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		scanf("%lld", &n);
		if(n%3==0){
			ans = (n/3)*(n/3)*(n/3);
		}
		else if(n%4==0){
			ans = (n/2)*(n/4)*(n/4);
		}
		else{
			ans = -1;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
