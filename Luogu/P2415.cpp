#include <cstdio>
#include <iostream>
#include <cmath>
using std::cin;

int a;
long long summ, cnt;

int main(){
	freopen("data.in", "r", stdin);

	while(cin >> a) { summ+=a; cnt++; }
	printf("%lld", (long long)(summ*pow(2, cnt-1)));

	return 0;
}
