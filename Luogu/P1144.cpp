#include <cstdio>
#include <iostream>
#include <vector>

const int Maxn=1e6+5, Mod=100003;
std::vector<int> mapp[Maxn];
int queue[Maxn], cnt[Maxn], bfn[Maxn], ans[Maxn], now, x, y, n, m;
bool vis[Maxn];

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d", &x, &y);
		mapp[x].push_back(y);
		mapp[y].push_back(x);
		cnt[x]++;
		cnt[y]++;
	}
	int front=0, rear=0;
	queue[rear++] = 1;
	vis[1] = true;
	ans[1] = 1;
	while(front<rear){
		now = queue[front++];
		for(int i=0; i<cnt[now]; i++){
			if(!vis[mapp[now][i]]){
				queue[rear++] = mapp[now][i];
				bfn[mapp[now][i]] = bfn[now]+1;
				vis[mapp[now][i]] = true;
				ans[mapp[now][i]] += ans[now]%Mod;
				ans[mapp[now][i]] %= Mod;
			}
			else{
				if(bfn[mapp[now][i]]==bfn[now]+1){
					ans[mapp[now][i]] += ans[now]%Mod;
					ans[mapp[now][i]] %= Mod;
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		printf("%d\n", ans[i]);
	}

	return 0;
}
