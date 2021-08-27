#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

const int Maxn=1e4+5, Maxm=1e5+5;
struct Edge{
	int u, v;
} edge[Maxm];
int n, m, u, v, tim, scnt, top;
int a[Maxn], cnt[Maxn], cnts[Maxn], scc[Maxn][Maxn], stack[Maxn], dfn[Maxn], low[Maxn];
int newcnt[Maxn], mst[Maxn], summ[Maxn], rdrcnt[Maxn], rdrcnt2[Maxn], dp[Maxn], tp[Maxn], maxdp, tail;
bool vis[Maxn];
std::vector<int> mapp[Maxn], newmap[Maxn], rdr[Maxn];

void tarjan(int);
//void topo(int);
void topo(void);
int min(int xx, int yy) { return xx<yy?xx:yy; }
int max(int xx, int yy) { return xx>yy?xx:yy; }

int main(){
//	freopen("data.in", "r", stdin);

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
			rdr[mst[edge[i].v]].push_back(mst[edge[i].u]);
			rdrcnt[mst[edge[i].v]]++;
			rdrcnt2[mst[edge[i].v]]++;
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
	topo();
/*
	for(int i=0; i<scnt; i++){
		if(rdrcnt[i] == 0){
			tp[tail++] = i;
			vis[i] = true;
			memset(vis, 0, sizeof(vis));
			topo(i);
			break;
		}
	}
*/
	for(int i=0; i<scnt; i++){
		dp[i] = summ[i];
	}
	for(int i=1; i<scnt; i++){
		for(int j=0; j<rdrcnt2[tp[i]]; j++){
			dp[tp[i]] = max(dp[tp[i]], dp[rdr[tp[i]][j]]+summ[tp[i]]);
		}
	}
	for(int i=0; i<scnt; i++){
		maxdp = max(maxdp, dp[i]);
	}
	printf("%d", maxdp);

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
/*
void topo(int point){
	for(int i=0; i<newcnt[point]; i++){
		if(!vis[newmap[point][i]]){
			tp[tail++] = newmap[point][i];
			vis[newmap[point][i]] = true;
			topo(newmap[point][i]);
		}
	}
}
*/
void topo(void){
	int point;
	memset(stack, 0, sizeof(stack));
	top = 0;
	for(int i=0; i<scnt; i++){
		if(rdrcnt[i] == 0) stack[top++] = i;
	}
	while(top>0){
		point = stack[--top];
		tp[tail++] = point;
		for(int i=0; i<newcnt[point]; i++){
			rdrcnt[newmap[point][i]]--;
			if(rdrcnt[newmap[point][i]]==0){
				stack[top++] = newmap[point][i];
			}
		}
	}
}
