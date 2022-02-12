#include <iostream>
#include <cstring>
#include <cstdio>

const int Maxn = 1e6+5, Mod = 1e9+7;
int n, pi[Maxn], l, minn[Maxn], lena;
long long ans=1;
char a[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int cst=0; cst<n; cst++){
		ans = 1;
		scanf("%s", a);
		lena = strlen(a);

		for(int i=1; i<lena; i++){
			l = pi[i-1];
			while(l>0 && a[i]!=a[l]) l = pi[l-1];
			if(a[i] == a[l]) l++;
			pi[i] = l;
		}
	
		for(int i=1; i<lena; i++){
			l = pi[i];
			while(l*2 > i+1 && l != 0){
				l = pi[l-1];
			}
			ans *= (l+1);
			ans %= Mod;
		}

		printf("%lld\n", ans);
	}

	return 0;
}
