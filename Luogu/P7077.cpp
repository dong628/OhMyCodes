#include <cstdio>
#include <iostream>
#include <vector>
#define int long long
using std::vector;

const int Maxn = 1e5+5, Mod = 998244353;
struct Func{
	int t, p, v, c, cntarr;
	bool fin;
	vector<int> arr, g;
} func[Maxn];
void dfs(int);
int a[Maxn], type3[Maxn], cnt3, n, m, q, tmpg, mul, add[Maxn];
int f, finp[Maxn], finv[Maxn], cfin;

signed main(){
	freopen("data.in", "r", stdin);

	scanf("%lld", &n);
	for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
	scanf("%lld", &m);
	for(int i=1; i<=m; i++){
		scanf("%lld", &func[i].t);
		func[i].fin = true;
		if(func[i].t == 1) scanf("%lld %lld", &func[i].p, &func[i].v);
		if(func[i].t == 2) scanf("%lld", &func[i].v);
		if(func[i].t == 3){
			scanf("%lld", &func[i].c);
			func[i].fin = false;
			for(int j=1; j<=func[i].c; j++){
				scanf("%lld", &tmpg);
				func[i].g.push_back(tmpg);
			}
			type3[cnt3++] = i;
		}
	}
	for(int i=0; i<cnt3; i++){
		dfs(type3[i]);
	}
	scanf("%lld", &q);
	while(q--){
		scanf("%lld", &f);
		if(func[f].t < 3){
			finp[cfin] = func[f].p;
			finv[cfin] = func[f].v;
			cfin++;
		}
		else{
			for(int i=0; i<func[f].cntarr; i++){
				finp[cfin] = func[func[f].arr[i]].p;
				finv[cfin] = func[func[f].arr[i]].v;
				cfin++;
			}
		}
	}
	mul = 1;
	for(int i=cfin-1; i>=0; i--){
		if(finp[i]!=0){
			add[finp[i]] += finv[i]*mul;
			add[finp[i]] %= Mod;
		}
		else{
			mul *= finv[i];
			mul %= Mod;
		}
	}
	for(int i=1; i<=n; i++){
		a[i] *= mul; a[i] %= Mod;
		a[i] += add[i]; a[i] %= Mod;
		printf("%lld ", a[i]);
	}

	return 0;
}

void dfs(int root){
	if(func[root].fin == true) return;
	func[root].fin = true;
	for(int i=0; i<func[root].c; i++){
		if(func[func[root].g[i]].t < 3){
			func[root].arr.push_back(func[root].g[i]);
			func[root].cntarr++;
		}
		else{
			dfs(func[root].g[i]);
			for(int j=0; j<func[func[root].g[i]].cntarr; j++){
				func[root].arr.push_back(func[func[root].g[i]].arr[j]);
				func[root].cntarr++;
			}
		}
	}
}
