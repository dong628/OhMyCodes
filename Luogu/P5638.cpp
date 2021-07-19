#include <cstdio>
#include <iostream>

const int Maxn=1e6+5;
int n, k;
long long a[Maxn], s[Maxn], maxm;

int main(){
	scanf("%d %d", &n, &k);
	for(int i=1; i<n; i++){
		scanf("%lld", &a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(int i=0; i<n-k; i++){
		maxm=maxm>s[i+k]-s[i]?maxm:s[i+k]-s[i];
	}
	printf("%lld", s[n-1]-maxm);

	return 0;
}
