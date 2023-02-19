#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

const int Maxn = 3e5+5, Maxlog = 20, Maxk = 50, Mod = 998244353;
int n, depth[Maxn], fa[Maxn][Maxlog];
long long s[Maxk+5][Maxn];
std::vector <int> tree[Maxn];

long long query(int, int, int);
void dfs(int, int), init(int);

int main(){
	freopen("data.in", "r", stdin);

	int u, v, k, m;

	scanf("%d", &n);
	init(n);
	for(int i=1; i<n; i++){
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	depth[0] = -1;
	dfs(1, 0);
	depth[0] = 0;
	scanf("%d", &m);
	while(m --> 0){
		scanf("%d %d %d", &u, &v, &k);
		printf("%lld\n", query(u, v, k));
	}

	return 0;
}

void dfs(int cur, int from){
	fa[cur][0] = from;
	depth[cur] = depth[from] + 1;
	int logg = log(depth[cur]) / log(2);
	for(int i=1; i<=logg; i++){
		fa[cur][i] = fa[fa[cur][i-1]][i-1];
	}
	for(int i=0; i<tree[cur].size(); i++){
		if(tree[cur][i] == from) continue;
		dfs(tree[cur][i], cur);
	}
}

long long query(int u, int v, int k){
	if(depth[u] > depth[v]) std::swap(u, v);
	long long ans = 0;
	int ddep = depth[v] - depth[u], base = 0;
	while(ddep > 0){
		if(ddep & (1 << base)){
			ddep -= (1 << base);
			ans += s[k][depth[v]] - s[k][depth[fa[v][base]]];
			ans %= Mod;
			v = fa[v][base];
		}
		base++;
	}
	base = 0;
	if(u == v){
		if(depth[v] != 0) ans += s[k][depth[v]] - s[k][depth[v] - 1];
		ans %= Mod; ans += Mod; ans %= Mod;
		return ans;
	}
	while(fa[u][base] != fa[v][base]) base++;
	for(int i=base-1; i>=0; i--){
		if(fa[u][i] != fa[v][i]){
			ans += 2 * (s[k][depth[v]] - s[k][depth[fa[v][i]]]);
			ans %= Mod;
			u = fa[u][i]; v = fa[v][i];
		}
	}
	for(int i=0; i<=base; i++){
		if(fa[u][i] == fa[v][i]){
			ans += 2 * (s[k][depth[v]] - s[k][depth[fa[v][i]]]);
			ans %= Mod;
			u = fa[u][i]; v = fa[v][i];
			break;
		}
	}
	if(depth[v] != 0) ans += s[k][depth[v]] - s[k][depth[v] - 1];
	ans %= Mod; ans += Mod; ans %= Mod;
	return ans;
}

void init(int maxn){
	for(int i=1; i<=maxn; i++) s[0][i] = 1;
	for(int i=1; i<=maxn; i++){
		for(int j=1; j<=Maxk; j++){
			s[j][i] = i * s[j-1][i];
			s[j][i] %= Mod;
		}
	}
	for(int j=1; j<=Maxk; j++){
		for(int i=1; i<=maxn; i++){
			s[j][i] += s[j][i-1];
			s[j][i] %= Mod;
		}
	}
}
