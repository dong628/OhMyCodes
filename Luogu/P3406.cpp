#include <iostream>
#include <cstdio>

const int Maxn=1e5+5, Maxm=1e5+5;
int n, m;
long long cnt[Maxn], p[Maxm], cf[Maxn], a[Maxn], b[Maxn], c[Maxn], maxp, minp;
long long summ;

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%lld", &p[i]);
	}
	for(int i=2; i<=m; i++){
		minp = p[i]<p[i-1]?p[i]:p[i-1];
		maxp = p[i]>p[i-1]?p[i]:p[i-1];
		cf[minp]+=1;
		cf[maxp]-=1;
	}
	for(int i=1; i<=n; i++){
		scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
	}
	for(int i=1; i<=n; i++){
		cnt[i]=cnt[i-1]+cf[i];
		summ += cnt[i]*a[i] < cnt[i]*b[i]+c[i] ? cnt[i]*a[i] : cnt[i]*b[i]+c[i];
	}
	printf("%lld", summ);

	return 0;
}
