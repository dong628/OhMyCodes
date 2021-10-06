#include <cstdio>
#include <iostream>
#define ull unsigned long long

const int Maxn=5e6+5;
const int threshold=10000000;
ull k1,k2;
ull Rand(){
	ull k3=k1,k4=k2;
	k1=k4;
	k3^=(k3<<23);
	k2=k3^k4^(k3>>17)^(k4>>26);
	return k2+k4;
}
int a[Maxn], b[Maxn], n, m;
ull dp[3*Maxn], ans, w1, w2, w3, w4, kk1, kk2;
void gen(int n,ull _k1,ull _k2){
	k1=_k1,k2=_k2;
	for(int i=1;i<=n;i++){
		a[i]=Rand()%threshold+1;
		b[i]=Rand()%threshold+1;
	}
}
ull max(ull xx, ull yy) { return xx>yy?xx:yy; }
int min(int xx, int yy) { return xx<yy?xx:yy; }

int main(){
	freopen("hand.in", "r", stdin);
	freopen("hand.out", "w", stdout);

	scanf("%d %d %llu %llu", &n, &m, &kk1, &kk2);
	gen(n, kk1, kk2);

	for(int i=1; i<=n; i++){
		for(int j=min(3*i, m); j>=1; j--){
			w1=0; w2=0; w3=0; w4=0;
			w1 = dp[j];
			w2 = dp[j-1]+a[i];
			if(j>=2)
				w3 = dp[j-2]+a[i]+b[i];
			if(j>=3)
				w4 = dp[j-3]+2*a[i]+b[i];
			dp[j] = max(max(max(w1, w2), w3), w4);
		}
	}

	for(int i=1; i<=m; i++){
//		printf("%llu ", dp[n][i]);
		ans ^= dp[i];
	}
	printf("%llu", ans);

	return 0;
}
