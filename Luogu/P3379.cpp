#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

const int Maxn=5e5+5;
void dfs(int);
void prework(void);
int query(int, int);
vector<int> tree[Maxn];
int n, m, s, x, y, cnt[Maxn], depth[Maxn], fa[Maxn][50], depdel;
int a, b;
bool vis[Maxn];

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	scanf("%d %d %d", &n, &m, &s);
	for(int i=1; i<n; i++){
		scanf("%d %d", &x, &y);
		tree[x].push_back(y);
		tree[y].push_back(x);
		cnt[x]++; cnt[y]++;
	}
	fa[s][0] = s;
	vis[s] = true; depth[s] = 1;
	dfs(s);
	prework();
/*
	for(int i=0; i<n; i++){
		printf("fa[%d]: ", i);
		for(int j=0; j<=16; j++){
			printf("%d ", fa[i][j]);
		}
		printf("\n");
	}
	printf("\ndepth: ");
	for(int i=0; i<=n; i++){
		printf("%d ", depth[i]);
	}
	printf("\n");
*/
	for(int i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
//		query(a, b);
		printf("%d\n", query(a, b));
	}

	return 0;
}

void dfs(int point){
	for(int i=0; i<cnt[point]; i++){
		if(!vis[tree[point][i]]){
			vis[tree[point][i]] = true;
			depth[tree[point][i]] = depth[point]+1;
			fa[tree[point][i]][0] = point;
			dfs(tree[point][i]);
		}
	}
}

void prework(void){
	int logg = log(n)/log(2)+1;
	for(int i=1; i<=logg; i++){
		for(int j=1; j<=n; j++){
			fa[j][i] = fa[fa[j][i-1]][i-1];
		}
	}
}

int query(int n1, int n2){
	if(depth[n1]>depth[n2]) swap(n1, n2);
	int logg = log(n)/log(2)+1;
	if(depth[n2]>depth[n1]){
		for(int i=logg; i>=0; i--){
			if(depth[fa[n2][i]]>=depth[n1]){
				n2=fa[n2][i];
//				printf("%d -> ", n2);
			}
		}
//		printf("\n");
	}
/*
	if(depth[n2]>depth[n1]){
		depdel = depth[n2]-depth[n1];
		for(int i=0; depdel>0; i++){
			if(depdel & 1) n2 = fa[n2][i];
			depdel >>= 1;
		}
	}
*/
	if(n1 == n2) return n1;
	for(int i=logg; i>=0; i--){
		if(fa[n1][i] != fa[n2][i]){
			n1 = fa[n1][i];
			n2 = fa[n2][i];
		}
	}
	return fa[n1][0];
}
