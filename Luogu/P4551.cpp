#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#define int long long
using std::make_pair;

const int Maxn = 1e5+5;
std::vector < std::pair <int, int> > tree[Maxn];
int trie[Maxn][2], cnt = 1, v[Maxn];
int rev(int), query(int);
void dfs(int, int, int), addc(int);

signed main(){
	freopen("data.in", "r", stdin);

	int n, u, vv, w;
	scanf("%lld", &n);
	for(int i=1; i<n; i++){
		scanf("%lld %lld %lld", &u, &vv, &w);
		tree[u].push_back(make_pair(vv, w));
		tree[vv].push_back(make_pair(u, w));
	}

	dfs(2, 0, 0);

	int maxn = 0, tmp;
	for(int i=1; i<=n; i++){
		tmp = query(v[i]);
		maxn = maxn > tmp ? maxn : tmp;
	}
	printf("%lld", maxn);

	return 0;
}

void dfs(int cur, int val, int fa){
	addc(val);
	v[cur] = val;
	for(int i=0; i<tree[cur].size(); i++){
		if(tree[cur][i].first != fa){
			dfs(tree[cur][i].first, val^tree[cur][i].second, cur);
		}
	}
}

void addc(int x){
	x = rev(x);
	int cur = 0;
	while(x){
		if(trie[cur][x&1] == 0){
			trie[cur][x&1] = cnt++;
		}
		cur = trie[cur][x&1];
		x >>= 1;
	}
}

int query(int x){
	x = rev(x);
	int cur = 0, ans = x;
	for(int i=0; x; i++){
		if(trie[cur][(int)(!(x&1))] == 0){
			if(trie[cur][x&1] == 0){
				printf("something weired happened\n");
			}
			cur = trie[cur][x&1];
		}
		else{
			cur = trie[cur][(int)(!(x&1))];
			ans ^= (1<<i);
		}
		x >>= 1;
	}
	return rev(ans);
}

int rev(int x){
	int logg = 30, ans = 0;
	for(int i=logg; i>=0 && x; i--){
		ans += (1 << i) * (x & 1);
		x >>= 1;
	}
	return ans;
}
