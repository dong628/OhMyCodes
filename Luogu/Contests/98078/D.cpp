#include <cstdio>
#include <iostream>
#include <vector>

const int Maxn = 1e5+5;
std::vector <int> mapp[Maxn], depth[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	int t, n, m, k, u, v;

	scanf("%d", &t);
	while(t --> 0){
		scanf("%d %d %d", &n, &m, &k);
		for(int i=1; i<=m; i++){
			scanf("%d %d", &u, &v);
			mapp[u].push_back(v); 
			mapp[v].push_back(u);
		}
		if(k == 0){
			if(m == 0) printf("1\n");
			else printf("0\n");
			continue;
		}
		depth[1] = 1;
		dfs(1);
		printf("%lld\n", dp(1, n-k, 0)%Mod);
	}

	return 0;
}

void dfs(int cur){
	maxdep = max(maxdep, dep[cur]);
	for(int i=0; i<mapp[cur].size(); i++){
		if(depth[mapp[cur][i]] == 0){
			depth[mapp[cur][i]] = depth[cur] + 1;
			dfs(mapp[cur][i]);
		}
	}
}
