#include <cstdio>
#include <iostream>

const int Maxn=2e5+5, Maxm=2e5+5;
int ll, rr, mid, n, m, w[Maxn], v[Maxn], l[Maxm], r[Maxm], max1, max2;
long long abs(long long a) { return a<0?-a:a; }
long long minn(long long a, long long b, long long c) { return c<(a<b?a:b)?c:(a<b?a:b); }
long long calc(int);
long long ans, s, summ[Maxn], cnt[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d %lld", &n, &m, &s);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &w[i], &v[i]);
		rr = rr>w[i]?rr:w[i];
	}
	for(int i=1; i<=m; i++){
		scanf("%d %d", &l[i], &r[i]);
	}
	while(ll<rr){
		mid = (ll+rr)>>1;
		if(calc(mid)>s){
			ll = mid+1;
			max1 = mid;
		}
		else if(calc(mid)<s){
			rr = mid;
			max2 = mid;
		}
		else{
			ll = mid;
			break;
		}
	}
	printf("%lld", minn(abs(calc(max1)-s), abs(calc(max2)-s), abs(calc(ll)-s)));

	return 0;
}

long long calc(int ww){
	ans = 0;
	for(int i=1; i<=n; i++){
		if(w[i]>=ww){
			cnt[i] = cnt[i-1]+1;
			summ[i] = summ[i-1]+v[i];
		}
		else{
			cnt[i] = cnt[i-1];
			summ[i] = summ[i-1];
		}
	}
	for(int i=1; i<=m; i++){
		ans += (cnt[r[i]]-cnt[l[i]-1])*(summ[r[i]]-summ[l[i]-1]);
	}
	return ans;
}
