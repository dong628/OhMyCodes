#include <cstdio>
#include <iostream>
#include <vector>
using std::vector;

const int Maxn=2e4+5;
vector<int> mapp[Maxn], tree[Maxn];
int cnt[Maxn], t, points[Maxn], cntree[Maxn], ans, dfn[Maxn], low[Maxn], x, y, n, m, tmp;
int fa[Maxn];
bool vis[Maxn];
int min(int xx, int yy) { return xx<yy?xx:yy; }
void dfs(int);
void tarjan(void);

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d", &x, &y);
		mapp[x].push_back(y);
		mapp[y].push_back(x);
		cnt[x]++; cnt[y]++;
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			fa[i] = -1;
			vis[i] = true;
			dfs(i);
		}
	}
	tarjan();
	printf("%d\n", ans);
	for(int i=0; i<ans; i++){
		printf("%d ", points[i]);
	}

	return 0;
}

void dfs(int node){
	t++;
	dfn[node] = t; low[node] = t;
	for(int i=0; i<cnt[node]; i++){
		if(!vis[mapp[node][i]]){
			tree[node].push_back(mapp[node][i]);
			cntree[node]++;
			fa[mapp[node][i]] = node;
			vis[mapp[node][i]] = true;
			dfs(mapp[node][i]);
//			vis[mapp[node][i]] = false;
			low[node] = min(low[node], low[mapp[node][i]]);
		}
		else if(fa[node]!=mapp[node][i]){
			low[node] = min(low[node], dfn[mapp[node][i]]);
		}
	}
}

void tarjan(void){
	ans = 0; tmp = 0;
/*	for(int i=0; i<cntree[1]; i++){
		if(low[tree[1][i]]>=dfn[1]){
			tmp++;
			if(tmp==2){
				points[ans++] = 1;
				break;
			}
		}
	}*/
	for(int i=1; i<=n; i++){
		if(fa[i]!=-1){
			for(int j=0; j<cntree[i]; j++){
				if(low[tree[i][j]]>=dfn[i]){
					points[ans++] = i;
					break;
				}
			}
		}
		else{
			tmp=0;
			for(int j=0; j<cntree[i]; j++){
				if(low[tree[i][j]]>=dfn[i]){
					tmp++;
					if(tmp==2){
						points[ans++] = i;
						break;
					}
				}
		}
		}
	}
}
