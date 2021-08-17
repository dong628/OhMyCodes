#include <cstdio>
#include <iostream>
#include <cstring>

void dfs(int, int);
const int Maxn=50;
int n, m, x, y, ind[Maxn][Maxn], cnt[Maxn], cho[Maxn], tmp[Maxn];
bool flag, vis[Maxn], ex[Maxn];

int main(){
//	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d", &x, &y);
		ex[x]=true; ex[y]=true;
		if(x!=y){
			ind[x][++cnt[x]] = i;
			ind[y][++cnt[y]] = i;
		}
		else{
			ind[y][++cnt[y]] = i;
		}
	}
	for(int i=1; i<=n; i++){
		flag=false;
		dfs(0, i);
		if(flag){
			printf("%d", i);
			return 0;
		}
	}

	return 0;
}

void dfs(int now, int maxn){
	if(now==maxn){
		memset(tmp, 0, sizeof(tmp));
		for(int i=0; i<now; i++){
			for(int j=1; j<=cnt[cho[i]]; j++){
				tmp[ind[cho[i]][j]]++;
			}
		}
		flag=true;
		for(int i=1; i<=n; i++){
			if(ex[x] && tmp[i]!=1){
				flag=false;
				break;
			}
		}
		return;
	}
	for(int i=1; i<=n; i++){
		if(ex[i] && vis[i]!=true){
			vis[i]=true;
			cho[now]=i;
			dfs(now+1, maxn);
			cho[now]=0;
			vis[i]=false;
			if(flag) return;
		}
	}
}
