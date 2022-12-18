#include <cstdio>
#include <iostream>

const int Maxn = 1e5+5;
int n;
long long c[Maxn];
long long calc(int);

int main(){
//	freopen("data.in", "r", stdin);

	int maxx = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%lld", &c[i]);
		maxx = maxx > c[i] ? maxx : c[i];
	}

	int l = 1, r = maxx, lmid, rmid;
	while(r - l > 2){
		rmid = (l + 2 * r) / 3;
		lmid = (r + 2 * l) / 3;
		if(calc(lmid) < calc(rmid)){
			l = lmid;
		}
		else{
			r = rmid;
		}
	}

	int ans = 0, per = 0;
	for(int i=std::max(l-5, 0); i<=r+5; i++){
		if(calc(i) > ans){
			ans = calc(i);
			per = i;
		}
	}

	printf("%lld %d", ans, per);

	return 0;
}

long long calc(int cos){
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(c[i] >= cos) ans += cos;
	}
	return ans;
}
