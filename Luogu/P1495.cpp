#include <cstdio>
#include <iostream>
using namespace std;

const int Maxn = 15;
int n;
long long a[Maxn], b[Maxn], m, ans, pi=1;
long long qpow(long long, long long);
long long mmi(long long a, long long mod);
long long exgcd(long long a, long long b, long long& x, long long& y);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%lld %lld", &a[i], &b[i]);
		pi *= a[i];
	}
	for(int i=0; i<n; i++){
		m = pi/a[i];
		ans += b[i]*mmi(m, a[i])*m;
	}
	printf("%lld", ans%pi);
	
	return 0;
}

long long mmi(long long a, long long mod){
	long long x=1, y=0, gcd;
	gcd = exgcd(a, mod, x, y);
	x /= gcd;
	return x;
}

long long exgcd(long long a, long long b, long long& x, long long& y){
	if(b==0) { x = 1; y = 0; return a; }
	long long d = exgcd(b, a%b, x, y);
	long long tmp = x; x = y; y = tmp-y*(a/b);
	return d;
}

long long qpow(long long x, long long y){
	long long base = x, anss = 1;
	while(y){
		if(y&1) anss *= base;
		y >>= 1; base *= base;
	}
	return anss;
}
