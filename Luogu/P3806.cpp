#include <cstdio>
#include <iostream>
#include <vector>
using std::make_pair;

typedef std::pair<int, int> pii;
const int Maxm = 1e7+5, Maxn = 1e4+5;
int n, m, k[Maxm], arr[Maxn], top, cnt[Maxn], centroid;
bool disa[Maxn], vis[Maxn], ans[Maxm];
std::vector<pii> tr[Maxn];
int cent(int, int);
void dfz(int), dfs(int, int);

int main(){
	freopen("data.in", "r", stdin);
	
	int u, v, w;
	scanf("%d %d", &n, &m);
	for(int i=1; i<n; i++){
		scanf("%d %d %d", &u, &v, &w);
		tr[u].push_back(make_pair(v, w));
		tr[v].push_back(make_pair(u, w));
		cnt[u]++; cnt[v]++;
	}
	for(int i=0; i<m; i++){
		scanf("%d", &k[i]);
	}

	dfz(1);

	for(int i=0; i<m; i++){
		if(ans[i]) printf("AYE\n");
		else printf("NAY\n");
	}

	return 0;
}



void dfz(int rt){
	cent(rt, rt);
	rt = centroid;
	for(int i=0; i<cnt[rt]; i++){
		if(!vis[tr[rt][i].first]){
			dfs(tr[rt][i].first, tr[rt][i].second);
		}
	}
	vis[rt] = true;
	for(int i=0; i<m; i++){
		if(disa[k[i]]) ans[i] = true;
	}
	for(int i=0; i<top; i++){
		disa[arr[i]] = false;
	}
	top = 0;
	for(int i=0; i<cnt[rt]; i++){
		if(!vis[tr[rt][i].first]){
			dfz(tr[rt][i].first);
		}
	}
}

void dfs(int rt, int curdis){
	vis[rt] = true;
	for(int i=0; i<m; i++){
		if(disa[k[i]-curdis]) ans[i] = true;
	}
	for(int i=0; i<cnt[rt]; i++){
		if(!vis[tr[rt][i].first]){
			dfs(tr[rt][i].first, curdis+tr[rt][i].second);
		}
	}
	disa[curdis] = true;
	arr[top++] = curdis;
	vis[rt] = false;
}

int cent(int rt, int from){
	int ssize = 1, size, maxsize = 0;
	for(int i=0; i<cnt[rt]; i++){
		if(tr[rt][i].first != from && (!vis[tr[rt][i].first])){
			size = cent(tr[rt][i].first, rt);
			maxsize = maxsize > size ? maxsize : size;
			ssize += size;
		}
	}
	maxsize = maxsize > n-ssize ? maxsize : n-ssize;
	if(maxsize <= n/2) centroid = rt;
	return ssize;
}
