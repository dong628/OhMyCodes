#include <cstdio>
#include <iostream>

long long gcd(long long a, long long b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
long long abs(long long a){ return a<0?-a:a; }

int main(){
	long long ansa = 0, ansb = 1, a, b, opt, gcdd, n;

	scanf("%lld", &n);

	for(int i=0; i<n; i++){
		scanf("%lld %lld %lld", &a, &b, &opt);
		if(opt == 1){
			ansa *= b;
			ansa += ansb*a;
			ansb *= b;
			gcdd = gcd(abs(ansa), ansb);
			ansa /= gcdd; ansb /=gcdd;
		}
		else{
			ansa *= b;
			ansa -= ansb*a;
			ansb *= b;
			gcdd = gcd(abs(ansa), ansb);
			ansa /= gcdd; ansb /=gcdd;
		}
	}
	if(ansb == 1){
		printf("%lld", ansa);
	}
	else{
		printf("%lld/%lld", ansa, ansb);
	}

	return 0;
}
