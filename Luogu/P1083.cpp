#include <cstdio>
#include <iostream>

const int Maxn=1e6+5;
int n, m, ll, rr, midd, cf[Maxn], tot[Maxn], r[Maxn], d[Maxn], s[Maxn], t[Maxn];
bool calc(int);

int main(){
	freopen("data.in", "r", stdin);
	
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &r[i]);
	}
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &d[i], &s[i], &t[i]);
	}
	ll=0; rr=m;
	while(ll<rr){
		midd = (ll+rr)>>1;
		if(calc(midd)){
			ll=midd+1;
		}
		else{
			rr=midd;
		}
	}
	if(ll==m) printf("0");
	else{
		printf("-1\n");
		printf("%d", ll);
	}

	return 0;
}

bool calc(int nu){
	for(int i=1; i<=n; i++){
		cf[i] = r[i]-r[i-1];
	}
	for(int i=1; i<=nu; i++){
		cf[s[i]] -= d[i];
		cf[t[i]+1] += d[i];
	}
	for(int i=1; i<=n; i++){
		tot[i] = tot[i-1]+cf[i];
		if(tot[i]<0) return false;
	}
	return true;
}
