#include <cstdio>
#include <iostream>

const int Maxn=1e5+5, Mod=10007;
int n, m;
long long pt1[Maxn][2], pt2[Maxn][2], pt3[Maxn][2], pt4[Maxn][2];
long long summ, color, tp, nu[Maxn], col[Maxn];

int main(){
	freopen("data.in", "r", stdin);
	
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%lld", &nu[i]);
	}
	for(int i=1; i<=n; i++){
		scanf("%lld", &col[i]);
	}
	for(int i=1; i<=n; i++){
		color=col[i]; tp=i%2;
		summ += pt1[color][tp]%Mod;
		summ %= Mod;
		summ += (pt2[color][tp]*nu[i])%Mod;
		summ %= Mod;
		summ += (pt3[color][tp]*i)%Mod;
		summ %= Mod;
		summ += (pt4[color][tp]*((i*nu[i])%Mod))%Mod;
		summ %= Mod;

		pt1[color][tp] += (i*nu[i])%Mod;
		pt1[color][tp] %= Mod;
		pt2[color][tp] += i%Mod;
		pt2[color][tp] %= Mod;
		pt3[color][tp] += nu[i]%Mod;
		pt3[color][tp] %= Mod;
		pt4[color][tp] ++;
		pt4[color][tp] %= Mod;

	}
	printf("%lld", summ%Mod);
	
	return 0;
}
