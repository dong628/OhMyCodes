#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
using std::swap;

const int Maxn = 5e5+5;
std::vector<int> tree[Maxn];
int n, m, s, x, y, a, b, logg, maxdep;
bool vis[Maxn];
int queue[Maxn], depth[Maxn], fa[Maxn][20], cnt[Maxn];
int max(int xx, int yy) { return xx>yy?xx:yy; }
void prework(int);
int query(int, int);
void dfs(int);

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	scanf("%d %d %d", &n, &m, &s);
	for(int i=1; i<n; i++){
		scanf("%d %d", &x, &y);
		tree[x].push_back(y);
		cnt[x]++;
		tree[y].push_back(x);
		cnt[y]++;
	}

	depth[s] = 1;
	fa[s][0] = s;
	dfs(s);

/*	for(int i=0; i<n; i++){
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
	for(int cs=0; cs<m; cs++){
		scanf("%d %d", &a, &b);
		printf("%d\n", query(a, b));
	}

	return 0;
}

void dfs(int now){
	vis[now] = true;
	int logg = log(depth[now])/log(2);
	for(int i=1; i<=logg; i++){
		fa[now][i] = fa[fa[now][i-1]][i-1];
	}
	for(int i=0; i<cnt[now]; i++){
		if(!vis[tree[now][i]]){
			fa[tree[now][i]][0] = now;
			depth[tree[now][i]] = depth[now]+1;
//			vis[tree[now][i]] = true;
			dfs(tree[now][i]);
		}
	}
}

/*
void prework(int root){
	int l=0, r=0;
	queue[r++] = root;
	vis[root] = true;
	depth[root] = 1;
	while(l<r){
		now = queue[l++];
		for(int i=0; i<cnt[now]; i++){
			if(!vis[tree[now][i]]){
				queue[r++] = tree[now][i];
				vis[tree[now][i]] = true;
				fa[tree[now][i]][0] = now;
				depth[tree[now][i]] = depth[now]+1;
				maxdep = max(maxdep, depth[tree[now][i]]);
			}
		}
	}
	fa[root][0] = root;
	int logg = log(maxdep)/log(2);
	for(int i=1; i<=logg; i++){
		for(int j=1; j<=n; j++){
//			if(depth[j]<(1<<i)) break;
			fa[j][i] = fa[fa[j][i-1]][i-1];
		}
	}
}
*/

int query(int n1, int n2){
	if(depth[n1]<depth[n2]) swap(n1, n2);
	logg = log(n1)/log(2);
	while(depth[n1]>depth[n2]){
		if(depth[fa[n1][logg]]>=depth[n2]){
			n1=fa[n1][logg];
		}
		logg--;
	}
	logg = log(n1)/log(2);
	while(fa[n1][0] != fa[n2][0]){
		if(fa[n1][logg] != fa[n2][logg]){
			n1 = fa[n1][logg];
			n2 = fa[n2][logg];
		}
		logg--;
	}
	return fa[n1][0];
}
