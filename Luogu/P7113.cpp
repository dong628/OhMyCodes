#include <cstdio>
#include <iostream>
#include <vector>
using std::vector;

typedef unsigned long long lol;
const int Maxn = 1e5+5;
lol gcd(lol xx, lol yy){
	if(xx%yy==0) return yy;
	return gcd(yy, xx%yy);
}
struct Ans{
	lol p, q;
} ans[Maxn];
lol cnt[Maxn], gcdd;
void typ(int, lol, lol);
int n, m, sp[Maxn], c, csp, x;
bool lsp[Maxn], sj[Maxn];
vector<int> mapp[Maxn];

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		ans[i].p=0; ans[i].q=1;
		scanf("%d", &c);
		for(int j=1; j<=c; j++){
			scanf("%d", &x);
			mapp[i].push_back(x);
			lsp[x] = true;
			cnt[i]++;
		}
	}
	for(int i=1; i<=n; i++){
		if(lsp[i]==false) sp[csp++]=i;
	}
	for(int i=0; i<csp; i++){
		typ(sp[i], 1, 1);
	}
	for(int i=1; i<=n; i++){
		if(sj[i]){
			printf("%llu %llu\n", ans[i].p, ans[i].q);
		}
	}

	return 0;
}

void typ(int poi, lol p, lol q){
	if(cnt[poi]==0){
		sj[poi]=true;
		ans[poi].p *= q;
		ans[poi].p += ans[poi].q*p;
		ans[poi].q *= q;
		gcdd = gcd(ans[poi].p, ans[poi].q);
		ans[poi].p /= gcdd; ans[poi].q /= gcdd;
		return;
	}
	else{
		for(int i=0; i<cnt[poi]; i++){
			typ(mapp[poi][i], p, q*cnt[poi]);
		}
	}
}
