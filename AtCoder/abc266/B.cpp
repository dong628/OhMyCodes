#include <cstdio>
#include <iostream>

const int Mod = 998244353;

int main(){
	long long a;
	scanf("%lld", &a);
	a %= Mod;
	a += Mod;
	a %= Mod;
	printf("%lld", a);

	return 0;
}
