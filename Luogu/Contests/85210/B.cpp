#include <cstdio>
#include <iostream>
#include <vector>
#define int long long
using std::vector;

const int Maxn = 5005, Inf = 0x7fffffff;
int n, f[Maxn], cost[Maxn], cnt[Maxn];
vector <int> mapp[Maxn];
int dfs(int);

signed main(){
//	freopen("data.in", "r", stdin);

	int a, b;
	scanf("%lld", &n);
	for(int i=1; i<n; i++){
		scanf("%lld", &f[i]);
		cost[i] = -1;
	}
	for(int i=1; i<n; i++){
		scanf("%lld %lld", &a, &b);
		mapp[a].push_back(b);
		mapp[b].push_back(a);
		cnt[a]++; cnt[b]++;
	}
	if(cnt[1] == n-1){
		printf("%lld", f[n-1]);
	}
	else{
		printf("%lld", dfs(n-1));
	}

	return 0;
}

int dfs(int x){
	if(cost[x] != -1) return cost[x];
	if(x == 1){
		cost[x] = f[x];
		return f[x];
	}
	int minc = f[x], tmp;
	for(int i=1; i<=x/2; i++){
		tmp = dfs(i) + dfs(x-i);
		minc = minc<tmp?minc:tmp;
	}
	cost[x] = minc;
	return minc;
}
