#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using std::queue;
using std::make_pair;
using std::max;

typedef std::pair<int, int> pii;
const int Maxn = 1e4+5, Maxm = 205, Maxk = 1e7+5;
int n, m, u, v, w, tim, ask[Maxm], cnt[Maxn], dfn[Maxn], weight[Maxn], size[Maxn], last;
int vx, count[Maxn], dis[Maxn], tsize;
bool vis[Maxn], ans[Maxn], flags[Maxk];
std::vector<pii> tr[Maxn];
void divide(int);
void calcvx(int, int);
int dfs(int, int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<n; i++){
		scanf("%d %d %d", &u, &v, &w);
		tr[u].push_back(make_pair(v, w)); cnt[u]++;
		tr[v].push_back(make_pair(u, w)); cnt[v]++;
	}
	for(int i=0; i<m; i++){
		scanf("%d", &ask[i]);
	}
	divide(1);
	for(int i=0; i<m; i++){
		if(ans[i]) printf("AYE\n");
		else printf("NAY\n");
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]) printf("%d ", i);
	}

	return 0;
}

void divide(int root){
	memset(size, 0, sizeof(size));
	memset(weight, 0, sizeof(weight));
	tsize = count[root];
	calcvx(root, -1);
	root = vx;
	vis[root] = true;
	memset(flags, 0, sizeof(flags));
	flags[0] = true;
	for(int i=0; i<cnt[root]; i++){
		if(vis[tr[root][i].first]) continue;
		last = 0;
		vis[tr[root][i].first] = true;
		count[tr[root][i].first] = dfs(tr[root][i].first, tr[root][i].second);
		vis[tr[root][i].first] = false;
		for(int j=0; j<last; j++){
			for(int k=0; k<m; k++){
				if(ask[k]>dis[j] && flags[ask[k]-dis[j]]) ans[k] = true;
			}
		}
		for(int j=0; j<last; j++){
			flags[dis[j]] = true;
		}
	}
	for(int i=0; i<cnt[root]; i++){
		if(vis[tr[root][i].first]) continue;
		tsize = count[tr[root][i].first];
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
	if(weight[cur] <= n/2) vx = cur;
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
