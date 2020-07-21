#include <cstdio>
#include <iostream>

long long n, m, nu, x;
int t;

int main(){
	scanf("%lld%lld%d", &m, &n, &t);
	nu=n/m;
	for(int i=0; i<t; i++){
		scanf("%lld", &x);
		if(x<=m) printf("%lld\n", nu);
		else printf("0\n");
	}

	return 0;
}
