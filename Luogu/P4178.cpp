#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using std::queue;
using std::make_pair;
using std::max;

typedef std::pair<int, int> pii;
//const int Maxn = 1e2+5, Maxm = 205, Maxk = 1e7+5;
const int Maxn = 4e4+5, Maxk = 1e8+5;
int n, m, u, v, w, tim, ask, cnt[Maxn], dfn[Maxn], weight[Maxn], size[Maxn], last, his, old[Maxn];
int vx, count[Maxn], dis[Maxn], tsize, ans;
bool vis[Maxn];
std::vector<pii> tr[Maxn];
int lowbit(int xx) { return xx&(-xx); }
void divide(int);
void calcvx(int, int);
int dfs(int, int);
void add(int p, int x){
	p++;
	while(p <= ask+1){
		old[p] += x;
		p = p+lowbit(p);
	}
}
int query(int p){
	p++;
	int ans = 0;
	while(p >= 1){
		ans += old[p];
		p = p-lowbit(p);
	}
	return ans;
}

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<n; i++){
		scanf("%d %d %d", &u, &v, &w);
		tr[u].push_back(make_pair(v, w)); cnt[u]++;
		tr[v].push_back(make_pair(u, w)); cnt[v]++;
	}
	count[1] = n;
	scanf("%d", &ask);
	divide(1);
	printf("%d", ans);

	return 0;
}

void divide(int root){
	memset(size, 0, sizeof(size));
	memset(weight, 0, sizeof(weight));
	tsize = count[root];
	calcvx(root, -1);
	root = vx;
	vis[root] = true;
//	memset(flags, 0, sizeof(flags));
//	flags[0] = true;
	his = 0;
	memset(old, 0, sizeof(old));
	for(int i=0; i<cnt[root]; i++){
		if(vis[tr[root][i].first]) continue;
		last = 0;
		vis[tr[root][i].first] = true;
		count[tr[root][i].first] = dfs(tr[root][i].first, tr[root][i].second);
		vis[tr[root][i].first] = false;
		for(int j=0; j<last; j++){
			if(dis[j] > ask) continue;
			ans += query(ask-dis[j])+1;
/*
			for(int k=0; k<his; k++){
				if(old[k]+dis[j] <= ask) ans++;
			}
*/
		}
		for(int j=0; j<last; j++){
			if(dis[j] <= ask) add(dis[j], 1);
		}
/*
		for(int j=0; j<last; j++){
			for(int k=0; k<m; k++){
				if(ask[k]>=dis[j] && flags[ask[k]-dis[j]]) ans[k] = true;
			}
		}
		for(int j=0; j<last; j++){
			flags[dis[j]] = true;
		}
*/
	}
	for(int i=0; i<cnt[root]; i++){
		if(vis[tr[root][i].first]) continue;
		divide(tr[root][i].first);
	}
}

void calcvx(int cur, int fa){
	size[cur] = 1;
	weight[cur] = 0;
	for(int i=0; i<cnt[cur]; i++){
		if(tr[cur][i].first != fa && (!vis[tr[cur][i].first])){
			calcvx(tr[cur][i].first, cur);
			size[cur] += size[tr[cur][i].first];
			weight[cur] = max(weight[cur], size[tr[cur][i].first]);
		}
	}
	weight[cur] = max(weight[cur], tsize-size[cur]);
	if(weight[cur] <= tsize/2) vx = cur;
}

int dfs(int cur, int cdis){
	int ret = 1;
	dis[last++] = cdis;
	for(int i=0; i<cnt[cur]; i++){
		if(!vis[tr[cur][i].first]){
			vis[tr[cur][i].first] = true;
			ret += dfs(tr[cur][i].first, cdis+tr[cur][i].second);
			vis[tr[cur][i].first] = false;
		}
	}
	return ret;
}
