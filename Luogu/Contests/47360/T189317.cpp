#include <cstdio>
#include <iostream>
#include <vector>
using std::vector;

const int Maxn=1e2+5;
int tree[Maxn][Maxn];
int a[Maxn], front, rear, sta[Maxn], n, m, x, y, ans[Maxn][2], node, cnt;
bool vis[Maxn], visfa[Maxn];

int main(){
	freopen("data.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		tree[x][tree[x][0]+1] = y;
		tree[x][0]++;
		tree[y][tree[y][0]+1] = x;
		tree[y][0]++;
	}
	for(int i=1; i<=n; i++){
		if(tree[i][0]==1) a[rear++]=i;
	}
	while(front<rear){
		node = a[front];
		front++;
		vis[node]=true;
		for(int i=1; i<=tree[node][0]; i++){
			if(!vis[i]){
				if(sta[node]&1){
					ans[cnt][1] = tree[node][i];
					ans[cnt][0] = node;
					cnt++;
				}
				else{
					sta[tree[node][i]]++;
					ans[cnt][1] = node;
					ans[cnt][0] = tree[node][i];
					cnt++;
				}
				if(!visfa[i]){
					visfa[i]=true;
					a[rear++]=i;
				}
			}
		}
	}
	if(sta[node]&1) printf("-1\n");
	else{
		for(int i=0; i<cnt; i++){
			printf("%d %d\n", ans[i][0], ans[i][1]);
		}
	}

	return 0;
}
