#include <cstdio>
#include <iostream>

typedef long long lol;
int n;
lol a, b, m, x, y, t, gcd;
lol exgcd(lol, lol, lol&, lol&);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	scanf("%lld %lld", &a, &b);
	m = a;
	x = a+b;
	for(int i=1; i<n; i++){
		scanf("%lld %lld", &a, &b);
		gcd = exgcd(m, b, t, y);
		t *= (b-x) / gcd;
		x += t*m;
		m *= a;
	}
	x %= m; x += m;
	printf("%lld", x%m);

	return 0;
}

lol exgcd(lol a, lol b, lol&x, lol&y){
	if(b == 0) { x = 1; y = 0; return a; }
	lol gcd = exgcd(b, a%b, y, x);
	y -= (a/b)*x;
	return gcd;
}
