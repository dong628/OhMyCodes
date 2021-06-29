#include <cstdio>
#include <iostream>
#include <cstring>

const int Maxn=25;
int n, nu[Maxn], m[Maxn][Maxn], maxv[Maxn], vis[Maxn], book[Maxn], maxval, maxdep;
void dfs(int, int, int);

int main(){
	freopen("data.in", "r", stdin);
	
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &nu[i]);
	}
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			scanf("%d", &m[i][j]);
		}
	}
	for(int i=1; i<=n; i++){
		memset(vis, 0, sizeof(vis));
		memset(book, 0, sizeof(book));
		vis[1]=i;
		book[i]=1;
		dfs(i, 2, 0);
	}
	for(int i=1; i<maxdep; i++){
		printf("%d ", maxv[i]);
	}
	printf("\n%d", maxval);

	return 0;
}

void dfs(int now, int depth, int val){
	val += nu[now];
	bool flag=true;
	for(int i=now; i<=n; i++){
		if(m[now][i] && (!book[i])){
			flag=false;
			book[i]=1;
			vis[depth]=i;
			dfs(i, depth+1, val);
			book[i]=0;
			vis[depth]=0;
		}
	}
	if(flag && val>maxval){
		for(int i=1; i<depth; i++){
			maxv[i]=vis[i];
		}
		maxval=val;
		maxdep=depth;
	}
}
