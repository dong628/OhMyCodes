#include <cstdio>
#include <iostream>

typedef long long lol;
lol exgcd(lol, lol, lol&, lol&);

int main(){
	lol a, b;
	scanf("%lld %lld", &a, &b);
	lol x, y, gcd;
	gcd = exgcd(a, b, x, y);
	x %= b; x += b; x %= b;
	printf("%lld", x);

	return 0;
}

lol exgcd(lol a, lol b, lol&x, lol&y){
	if(b==0){
		x = 1; y = 0;
		return a;
	}
	lol gcd = exgcd(b, a%b, y, x);
	y -= a/b*x;
	return gcd;
}
