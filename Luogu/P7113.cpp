#include <cstdio>
#include <iostream>
#include <vector>
using std::vector;

const int Maxn = 1e5+5;
int gcd(int xx, int yy){
	if(xx%yy==0) return yy;
	return gcd(xx, xx%yy);
}
struct Ans{
	int p, q;
} ans[Maxn];
void typ(int, int, int);
int n, m, cnt[Maxn], sp[Maxn], gcdd, c, csp, x;
bool lsp[Maxn];
vector<int> mapp[Maxn];

int main(){
	freopen("data.in", "r", stdin);

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
		typ(sp[csp], 1, 1);
	}

	return 0;
}

void typ(int poi, int p, int q){
	if(cnt[poi]==0){
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
