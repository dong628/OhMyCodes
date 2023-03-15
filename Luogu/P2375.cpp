#include <iostream>
#include <cstring>
#include <cstdio>

//const int Maxn = 1e2+5, Mod = 1e9+7;
const int Maxn = 1e6+5, Mod = 1e9+7;
int n, pi[Maxn], l, minn[Maxn], lena, cnt[Maxn];
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
		memset(cnt, 0, sizeof(cnt));
		for(int i=1; i<lena; i++){
			l = pi[i];
			if(l != 0) cnt[i]++;
			while(l*2 > i+1 && l != 0){
				l = pi[l-1];
				cnt[i]++;
			}
			cnt[i] += cnt[l-1];
			if(l != 0){
				ans *= (cnt[l-1]+2);
			}
			ans %= Mod;
		}

		printf("%lld\n", ans);
	}

	return 0;
}
