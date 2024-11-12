#include <stdio.h>

double qpow(double, int);

int main(){
	int n;
	double r;
	printf("输入年增长率: ");
	scanf("%lf", &r);
	printf("输入年数: ");
	scanf("%d", &n);
	printf("倍数为：%lf", qpow(1+r, n));

	return 0;
}

double qpow(double a, int b){
	double base = a, ans = 1;
	while(b){
		if(b&1) ans *= base;
		base *= base;
		b >>= 1;
	}
	return ans;
}
