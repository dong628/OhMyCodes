#include <cstdio>
#include <iostream>

const int Max=1e6+5;
int a[Max];
long long n, k;

long long f(long long);
inline long long min(long long x, long long y) { return x<y?x:y; }

int main(){
	scanf("%lld %d", &n, &k);
/*	if(n<=2*k+1){
		printf("1");
		return 0;
	}*/
	for(int i=0; i<=min(2*k+1, 1e6); i++) a[i]=1;
	for(int i=2*k+2; i<=1e6; i++)
		a[i]=a[(i-2)/2+1]+a[(i-1)/2+1];
	
	printf("%lld", f(n));

	return 0;
}

long long f(long long x){
	if(x<=1e6) return a[x];
	else if(x<=2*k+1) return 1;
	else return f((x-2)/2+1)+f((x-1)/2+1);
}
