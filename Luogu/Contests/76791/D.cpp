#include <cstdio>
#include <iostream>

const int Maxn = 1e5+5, Mod = 1e9+7;
int n;
long long a[Maxn], mina=0x7fffffff, ans=1;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		mina = mina<a[i]?mina:a[i];
	}
	for(int i=0; i<n; i++){
		ans *= (a[i]/mina);
		ans %= Mod;
	}

	printf("%lld %lld", mina, ans);

	return 0;
}
