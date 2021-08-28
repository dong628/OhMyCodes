#include <cstdio>
#include <iostream>
#include <vector>
using std::vector;

const int Maxn=205;
struct Edge{
	int u, v;
} edge[Maxn*Maxn];
int n, a, dfn[Maxn], low[Maxn], rd[Maxn], cd[Maxn], cnts, cntedge, cnt[Maxn], mst[Maxn];
int stack[Maxn], top, cntcd, cntrd, tm;
bool vis[Maxn], mv[Maxn][Maxn];
vector<int> mapp[Maxn];
int max(int xx, int yy) { return xx>yy?xx:yy; }
int min(int xx, int yy) { return xx<yy?xx:yy; }
void tarjan(int);

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		while(true){
			scanf("%d", &a);
			if(a==0) break;
			edge[cntedge].u = i;
			edge[cntedge].v = a;
			cntedge++;
			mapp[i].push_back(a);
			cnt[i]++;
		}
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			tarjan(i);
		}
	}
	for(int i=1; i<=n; i++){
//		mapp[i].clear();
	}
	for(int i=0; i<cntedge; i++){
		if(mst[edge[i].u]!=mst[edge[i].v] && (!mv[mst[edge[i].u]][mst[edge[i].v]])){
//			mapp[mst[edge[i].u]].push_back(mst[edge[i].v]);
//			cnt[mst[edge[i].u]]++;
			mv[mst[edge[i].u]][mst[edge[i].v]] = true;
			rd[mst[edge[i].v]]++;
			cd[mst[edge[i].u]]++;
		}
	}
	for(int i=0; i<cnts; i++){
		if(rd[i]==0) cntrd++;
		if(cd[i]==0) cntcd++;
	}
	printf("%d\n", cntrd);
/*	if(cnts==1){
		printf("0\n");
	}
	else{
		printf("%d\n", max(cntrd, cntcd));
	}*/

	return 0;
}

void tarjan(int point){
	vis[point] = true;
	low[point] = (++tm);
	dfn[point] = low[point];
	stack[top++] = point;
	for(int i=0; i<cnt[point]; i++){
		if(!vis[mapp[point][i]]){
			tarjan(mapp[point][i]);
			low[point] = min(low[point], low[mapp[point][i]]);
		}
		else{
			for(int i=0; i<top; i++){
				if(stack[i]==mapp[point][i]){
					low[point] = min(low[point], low[mapp[point][i]]);
					break;
				}
			}
		}
	}
	if(dfn[point]==low[point]){
		while(stack[top]!=point && top!=0){
			mst[stack[--top]] = cnts;
//			scc[cnts][scnt[cnts]++] = stack[--top];
		}
		cnts++;
	}
}
