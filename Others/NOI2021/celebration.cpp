#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
using std::vector;

const int Maxn=1e3+5;
struct Edge{
	int u, v;
}temp;
vector<Edge> edge[Maxn];
void dfs(int, int, bool);
void init(void);
void merge(int, int);
int find(int);
int tot[Maxn], ans, n, m, q, k, s, t, a[Maxn], b;
int vis[Maxn], bcj[Maxn], fa[Maxn], ha[Maxn];

int main(){
	freopen("celebration.in", "r", stdin);
	freopen("celebration.out", "w", stdout);

	scanf("%d %d %d %d", &n, &m, &q, &k);
	for(int i=1; i<=m; i++){
		scanf("%d %d", &temp.u, &temp.v);
		edge[temp.u].push_back(temp);
	}
	for(int i=1; i<=q; i++){
		init();
		ans=0;
		memset(vis, 0, sizeof(vis));
		memset(ha, 0, sizeof(ha));
		memset(fa, 0, sizeof(fa));
		memset(tot, 0, sizeof(tot));
		scanf("%d %d", &s, &t);
		for(int j=1; j<=k; j++){
			scanf("%d %d", &a[j], &b);
			temp.u=a[j]; temp.v=b;
			edge[a[j]].push_back(temp);
		}
		dfs(s, t, true);
		for(int j=1; j<=n; j++) ans+=tot[j];
		if(ans!=0)
			dfs(t, t, false);
		ans=0;
		for(int j=1; j<=n; j++) ans+=tot[j];
		for(int j=1; j<=n; j++){
			fa[j]=find(j);
			if(tot[j]) ha[fa[j]]=true;
		}
		for(int j=1; j<=n; j++){
			if(ha[fa[j]] && tot[j]==0) ans++;
		}
		printf("%d\n", ans);
		for(int j=1; j<=k; j++){
			edge[a[j]].pop_back();
		}
	}

	return 0;
}

void dfs(int point, int tar, bool flag){
	if(flag){
		vis[point]=1;
	}
	if(flag && point==tar){
		for(int i=1; i<=n; i++) if(vis[i]) tot[i]=1;
	}
	else{
		for(int i=0; i<edge[point].size(); i++){
			if(vis[edge[point][i].v] == 0){
//				vis[edge[point][i].v]=true;
				dfs(edge[point][i].v, tar, true);
//				vis[edge[point][i].v]=false;
			}
			else{
				if(find(point)!=find(edge[point][i].v))
					merge(point, edge[point][i].v);
			}
		}
	}
	vis[point]=0;
}

void init(void){
	for(int i=1; i<=n; i++) bcj[i]=i;
}

void merge(int x, int y){
	bcj[find(x)]=find(y);
}

int find(int x){
	return x==bcj[x]?x:bcj[x]=find(bcj[x]);
}
