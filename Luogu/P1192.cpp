#include <cstdio>
#include <iostream>

const int Maxn=1e5+5, Mod=100003;
int n, k, a[Maxn];

int main(){
	scanf("%d %d", &n, &k);
	a[0]=1;
	for(int i=1; i<=n; i++){
		for(int j=std::max(0, i-k); j<=i-1; j++){
			a[i]+=a[j];
			a[i]%=Mod;
		}
	}
	printf("%d", a[n]);

	return 0;
}
