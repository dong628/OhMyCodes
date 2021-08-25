#include <cstdio>
#include <iostream>
#include <vector>

const int Maxn=1e2+5, Maxm=1e5+5;
struct Edge{
	int u, v;
} edge[Maxm];
int n, m, u, v, tim, scnt, top;
int a[Maxn], cnt[Maxn], cnts[Maxn], scc[Maxn][Maxn], stack[Maxn], dfn[Maxn], low[Maxn];
int newcnt[Maxn], mst[Maxn], summ[Maxn];
bool vis[Maxn];
std::vector<int> mapp[Maxn], newmap[Maxn];

void tarjan(int);
int min(int xx, int yy) { return xx<yy?xx:yy; }

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=m; i++){
		scanf("%d %d", &u, &v);
		edge[i].u=u; edge[i].v=v;
		mapp[u].push_back(v);
		cnt[u]++;
	}

	for(int i=1; i<=n; i++){
		if(!vis[i]){
			vis[i] = true;
			tarjan(i);
		}
	}
/*
	for(int i=0; i<scnt; i++){
		for(int j=0; j<cnts[i]; j++){
			printf("%d ", scc[i][j]);
		}
		printf("\n");
	}
*/
	for(int i=0; i<scnt; i++){
		for(int j=0; j<cnts[i]; j++){
			summ[i] += a[scc[i][j]];
		}
	}
	for(int i=1; i<=m; i++){
		if(mst[edge[i].u]!=mst[edge[i].v]){
			newmap[mst[edge[i].u]].push_back(mst[edge[i].v]);
			newcnt[mst[edge[i].u]]++;
		}
	}
/*
	for(int i=0; i<scnt; i++){
		printf("%d ", summ[i]);
	}
	printf("\n");
	for(int i=0; i<scnt; i++){
		printf("point[%d]: ", i);
		for(int j=0; j<newcnt[i]; j++){
			printf("%d ", newmap[i][j]);
		}
		printf("\n");
	}
*/

	return 0;
}

void tarjan(int point){
	stack[top++] = point;
	tim++;
	dfn[point] = low[point] = tim;
	for(int i=0; i<cnt[point]; i++){
		if(!vis[mapp[point][i]]){
			vis[mapp[point][i]] = true;
			tarjan(mapp[point][i]);
			low[point] = min(low[point], low[mapp[point][i]]);
		}
		else{
			for(int j=0; j<top; j++){
				if(stack[j] == mapp[point][i]){
					low[point] = min(low[point], low[mapp[point][i]]);
					break;
				}
			}
		}
	}
	if(low[point] == dfn[point]){
		while(stack[top] != point && top!=0){
			mst[stack[top-1]] = scnt;
			scc[scnt][cnts[scnt]++] = stack[top-1]; 
			top--;
		}
		scnt++;
	}
}
