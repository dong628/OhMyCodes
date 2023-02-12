#include <cstdio>
#include <iostream>
#include <vector>
#define int long long

const int Maxn = 1e5+5, Mod = 998244353;
//const int Maxn = 1e2+5, Mod = 998244353;
int a[Maxn], p[Maxn], v[Maxn], in[Maxn], c[Maxn], call[Maxn], mul[Maxn], t[Maxn];
int n, m, q;
std::vector <int> g[Maxn];
std::vector <int> tp1();

signed main(){
	freopen("data.in", "r", stdin);
	
	int tmp;
	scanf("%lld", &n);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	scanf("%lld", &m);
	for(int i=1; i<=m; i++){
		scanf("%lld", &t[i]);
		if(t[i] == 1){
			scanf("%lld %lld", &p[i], &v[i]);
		}
		else if(t[i] == 2){
			scanf("%lld", &v[i]);
		}
		else{
			scanf("%lld", &c[i]);
			for(int j=1; j<=c[i]; j++){
				scanf("%lld", &tmp);
				g[i].push_back(tmp);
				in[tmp]++;
			}
		}
	}
	scanf("%lld", &q);
	c[0] = q; t[0] = 3;
	for(int i=1; i<=q; i++){
		scanf("%lld", &tmp);
		g[0].push_back(tmp);
		in[tmp]++;
	}

	std::vector <int> upxv = tp1();
	mul[0] = 1;
	for(int i=1; i<=m; i++) mul[i] = (t[i] == 2 ? v[i] : 1);
	for(int i=upxv.size()-1; i>=0; i--){
		for(int j=0; j<c[upxv[i]]; j++){
			mul[upxv[i]] *= mul[g[upxv[i]][j]];
			mul[upxv[i]] %= Mod;
		}
	}
	for(int i=1; i<=n; i++){
		a[i] *= mul[0];
		a[i] %= Mod;
	}
	
	call[0] = 1;
	int hbvv = 1;
	for(auto i=upxv.begin(); i!=upxv.end(); i++){
		if(t[*i] == 1){
			a[p[*i]] += (v[*i] * call[*i]) % Mod;
			a[p[*i]] %= Mod;
		}
		if(t[*i] == 2) continue;
		hbvv = 1;
		for(int j=c[*i]-1; j>=0; j--){
			call[g[*i][j]] += (hbvv * call[*i]) % Mod;
			call[g[*i][j]] %= Mod;
			hbvv *= mul[g[*i][j]];
			hbvv %= Mod;
		}
	}

	for(int i=1; i<=n; i++){
		printf("%lld ", a[i]);
	}

	return 0;
}

std::vector <int> tp1(){
	std::vector <int> nxt;
	int cur = 0, tar;
	for(int i=0; i<=m; i++){
		if(in[i] == 0) nxt.push_back(i);
	}
	for( ; ; ){
		tar = nxt[cur];
		for(int i=0; i<c[tar]; i++){
			in[g[tar][i]]--;
			if(in[g[tar][i]] == 0){
				nxt.push_back(g[tar][i]);
			}
		}
		cur++;
		if(cur >= nxt.size()) break;
	}
	return nxt;
}
